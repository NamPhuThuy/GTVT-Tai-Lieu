#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <float.h>

void nhapXau(char *s)
{
    printf("Nhap vao mot chuoi: ");
    fgets(s, 100, stdin);

    if (s[strlen(s) - 1] == '\n')
    {
        s[strlen(s) - 1] = '\0';
    }
}

int tachTu(char* s, char** words)
{
    char* token = strtok(s, " ");
    int cnt = 0;
    while (token != NULL)
    {
        words[cnt] = strdup(token);
        cnt++;
        token = strtok(NULL, " ");
    }

    return cnt;
}

void inTu(char** words, int cnt)
{
    for (int i = 0; i < cnt; i++)
    {
        printf("%s\n", words[i]);
    }
}

char* timTuDaiNhat(char** words, int cnt)
{
    int max = INT_MIN;
    char* maxC = NULL;
    for (int i = 0; i < cnt; i++)
    {
        int temp = strlen(words[i]);
        if (temp > max)
        {
            max = temp;
            maxC = strdup(words[i]);
        }
    }
    return maxC;
}

void daoNguocTu(char** words, int cnt, char** reversedString)
{
    int totalLength = 0;
    for (int i = 0; i < cnt; i++)
    {
        totalLength += strlen(words[i]);
    }

    totalLength += cnt - 1;

    *reversedString = (char*)malloc((totalLength + 1) * sizeof(char));
    if (*reversedString == NULL) {
        printf("Loi: Khong the cap phat bo nho.\n");
        exit(1);
    }

    int currentIndex = 0;
    for (int i = 0; i < cnt; i++)
    {
        int wordLength = strlen(words[i]);

        for (int j = wordLength - 1; j >= 0; j--)
        {
            (*reversedString)[currentIndex++] = words[i][j];
        }

        if (i < cnt - 1) {
            (*reversedString)[currentIndex++] = ' ';
        }
    }
    (*reversedString)[currentIndex] = '\0';
}

char** chuyenTu(char** words, int cnt, int* check)
{
    const char* replacement = "NewWord";
    *check = 0;

    char** words1Change = (char**)malloc(cnt * sizeof(char*));
    if (words1Change == NULL) {
        printf("Loi: Khong the cap phat bo nho.\n");
        exit(1);
    }

    for (int i = 0; i < cnt; i++)
    {
        words1Change[i] = (char*)malloc((strlen(words[i]) + 1) * sizeof(char));
        if (words1Change[i] == NULL) {
            printf("Loi: Khong the cap phat bo nho.\n");
            exit(1);
        }
        if (words[i][0] == 't')
        {
            strcpy(words1Change[i], replacement);
            *check = 1;
        }
        else
        {
            strcpy(words1Change[i], words[i]);
        }
    }
    return words1Change;
}

char* ketHopTu(char** words, int cnt)
{
    int totalLength = 0;
    for (int i = 0; i < cnt; i++)
    {
        totalLength += strlen(words[i]);
    }

    char* result = (char*)malloc((totalLength + cnt) * sizeof(char));
    if (result == NULL) {
        printf("Loi: Khong the cap phat bo nho.\n");
        exit(1);
    }

    int currentIndex = 0;
    for (int i = 0; i < cnt; i++)
    {
        strcpy(result + currentIndex, words[i]);
        currentIndex += strlen(words[i]);
        result[currentIndex++] = ' ';
    }
    result[currentIndex - 1] = '\0';

    return result;
}

int* thongKeTanSuatTu(char **words, int cnt)
{
    int* count = (int*)calloc(256, sizeof(int));

    for (int i = 0; i < cnt; i++)
    {
        char *word = words[i];
        while (*word != '\0')
        {
            count[(int)*word]++;
            word++;
        }
    }

    return count;
}

char** sapXepTheoThuTuTuDien(char **words, int cnt)
{
    for (int i = 0; i < cnt - 1; i++)
    {
        for (int j = 0; j < cnt - i - 1; j++)
        {
            if (strcmp(words[j], words[j + 1]) > 0)
            {
                char *temp = words[j];
                words[j] = words[j + 1];
                words[j + 1] = temp;
            }
        }
    }

    return words;
}

int main()
{
    // Nhap vao mot chuoi ky tu s
    char s[100];
    nhapXau(s);

    // Xuat cac tu phan biet ra man hinh
    char* words[100];
    printf("\nTu chuoi ky tu tren, ta co tung tu phan biet la:\n");
    int cnt = tachTu(s, words);
    inTu(words, cnt);

    // Tim tu do dai lon nhat
    char* maxChar = timTuDaiNhat(words, cnt);
    printf("\nTu dai nhat la: %s\n", maxChar);

    // Dao nguoc cac tu va luu vao chuoi s1
    char* s1;
    daoNguocTu(words, cnt, &s1);
    printf("\nChuoi ky tu sau khi dao nguoc cac tu la: %s\n", s1);

    // Thay the nhung tu co ky tu dau la 't' trong chuoi s1 thanh tu "NewWord"
    int check;
    char* words1[100];
    int cnt1 = tachTu(s1, words1);
    char** words1Change = chuyenTu(words1, cnt1, &check);
    if (check == 0) printf("\nKhong co tu nao co ky tu dau la 't'\n");
    else
    {
        char* s1Change = ketHopTu(words1Change, cnt1);
        printf("\nChuoi ki tu s1 moi sau khi thay the nhung tu co ky tu dau la 't' thanh tu 'NewWord' la: %s\n", s1Change);
        free(s1Change);
    }

    // Thong ke tan suat xuat hien cua cac ky tu trong chuoi s
    int* tk = thongKeTanSuatTu(words, cnt);

    printf("\nThong ke tan suat xuat hien cua cac ky tu trong cac tu:\n");
    for (int i = 0; i < 256; i++)
    {
        if (tk[i] > 0 && (char)i != '\0' && (char)i != '\n')
        {
            printf("Ky tu '%c' xuat hien %d lan.\n", (char)i, tk[i]);
        }
    }
    free(tk); 

    // Sap xep cac tu trong s theo thu tu tu diem tang dan
    char** sortedWords = sapXepTheoThuTuTuDien(words, cnt);
    char* sortedString = ketHopTu(sortedWords, cnt);
    printf("\nSau khi sap xep cac tu trong s theo thu tu tu diem tang dan, ta duoc chuoi moi la: %s\n", sortedString);

	// Giai phong bo nho
    free(maxChar);
    free(s1);
    for (int i = 0; i < cnt; i++) {
        free(words[i]);
    }
    free(words1Change);
    free(sortedWords);
    free(sortedString);

    return 0;
}