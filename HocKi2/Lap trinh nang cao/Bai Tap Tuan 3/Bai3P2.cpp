#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>

struct Point
{
    int index;
    float x;
    float y;
};

struct Line
{
    Point startPnt;
    Point endPnt;

    float (*length)(struct Line*);
    bool (*containsPoint)(struct Line*, struct Point);

    int countPoints;
};

float lineLength(struct Line* line)
{
    return sqrt(pow(line->endPnt.x - line->startPnt.x, 2) + pow(line->endPnt.y - line->startPnt.y, 2));
}

bool pointOnLine(struct Line* line, struct Point point)
{
    float y0_expected = line->startPnt.y + (point.x - line->startPnt.x) * (line->endPnt.y - line->startPnt.y) / (line->endPnt.x - line->startPnt.x);
    return fabs(y0_expected - point.y) < 0.00001;
}

float totalLength(Line* lines, int m)
{
    float total = 0.0;
    for (int i = 0; i < m; ++i)
    {
        total += lines[i].length(&lines[i]);
    }
    return total;
}

void countPointsOnLines(Line* lines, int numLines, Point* points, int numPoints)
{
    for (int i = 0; i < numLines; ++i)
    {
        lines[i].countPoints = 0;
        for (int j = 0; j < numPoints; ++j)
        {
            if (lines[i].containsPoint(&lines[i], points[j]))
            {
                lines[i].countPoints++;
            }
        }
    }
}

void nhapDiem(Point* a, int i)
{
    printf("\nNhap toa do cua diem thu %d:\n", i);
    printf("Nhap x[%d]: ", i);
    scanf("%f", &a->x);
    printf("Nhap y[%d]: ", i);
    scanf("%f", &a->y);
    a->index = i;
}

Point* nhapDanhSachDiem(int n)
{
    Point* a = (Point*)malloc(n * sizeof(Point));
    for (int i = 0; i < n; i++)
    {
        nhapDiem(&a[i], i);
    }
    return a;
}

void xuatDSDiem(Point* a, int n)
{
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            printf("(%.2f, %.2f), ", a[i].x, a[i].y);
        else
            printf("(%.2f, %.2f).\n", a[i].x, a[i].y);
    }
}

void nhapDT(Line* a, Point* b, int i, int n)
{
    printf("Doan thang thu %d:\n", i);
    printf("Start Point [%d] - Nhap chi so cua 1 diem: ", i);
    scanf("%d", &a->startPnt.index);
    for (int j = 0; j < n; j++)
    {
        if (a->startPnt.index == b[j].index)
        {
            a->startPnt.x = b[j].x;
            a->startPnt.y = b[j].y;
            break;
        }
    }
    printf("End Point [%d] - Nhap chi so cua 1 diem: ", i);
    scanf("%d", &a->endPnt.index);
    for (int j = 0; j < n; j++)
    {
        if (a->endPnt.index == b[j].index)
        {
            a->endPnt.x = b[j].x;
            a->endPnt.y = b[j].y;
            break;
        }
    }
}

Line* nhapDanhSachDT(Point* b, int m, int n)
{
    Line* a = (Line*)malloc(n * sizeof(Line));
    for (int i = 0; i < m; i++)
    {
        nhapDT(&a[i], b, i, n);
    }
    return a;
}

void xuatDanhSachDT(Line* a, int n)
{
    printf("\nDanh sach cac doan thang:\n");
    for (int i = 0; i < n; i++)
    {
        printf("Doan thang %d: ", i);
        printf("Start Point: (%.2f, %.2f), ", a[i].startPnt.x, a[i].startPnt.y);
        printf("End Point: (%.2f, %.2f)\n", a[i].endPnt.x, a[i].endPnt.y);
    }
}

int main()
{
    int n;
    printf("Nhap so luong diem: ");
    scanf("%d", &n);

    Point* pnt = nhapDanhSachDiem(n);
    printf("\nDanh sach diem vua nhap la: ");
    xuatDSDiem(pnt, n);

    int m;
    printf("Nhap so luong doan thang: ");
    scanf("%d", &m);
    Line* line = nhapDanhSachDT(pnt, m, n);
    printf("\nDanh sach diem vua nhap la:\n");
    xuatDanhSachDT(line, m);

    float total = totalLength(line, m);
    printf("\nTong do dai cac doan thang: %.2f\n", total);

    countPointsOnLines(line, m, pnt, n);
    for (int i = 0; i < m; i++)
    {
        printf("Doan thang %d co %d diem thuoc.\n", i, line[i].countPoints);
    }

    free(pnt);
    free(line);

    return 0;
}