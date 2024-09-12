// (2024-3-13)KiemTra.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "(2024-3-13)KiemTra.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
//WCHAR szTitle[L"Vẽ hình"];
WCHAR szWindowClass[MAX_LOADSTRING];            // the main window class name

// Forward declarations of functions included in this code module:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: Place code here.

    // Initialize global strings
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_MY2024313KIEMTRA, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY2024313KIEMTRA));

    MSG msg;

    // Main message loop:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  FUNCTION: MyRegisterClass()
//
//  PURPOSE: Registers the window class.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    /*wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY2024313KIEMTRA));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);*/

    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY2024313KIEMTRA));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    //wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY2024313KIEMTRA);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDR_MENU1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   FUNCTION: InitInstance(HINSTANCE, int)
//
//   PURPOSE: Saves instance handle and creates main window
//
//   COMMENTS:
//
//        In this function, we save the instance handle in a global variable and
//        create and display the main program window.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Store instance handle in our global variable

   /*HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);*/

   HWND hWnd = CreateWindowW(szWindowClass, TEXT("Vẽ hình"), WS_OVERLAPPEDWINDOW,
       CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  PURPOSE: Processes messages for the main window.
//
//  WM_COMMAND  - process the application menu
//  WM_PAINT    - Paint the main window
//  WM_DESTROY  - post a quit message and return
//
//

HBRUSH hBrush = CreateSolidBrush(RGB(255, 0, 0));
COLORREF colorForHBrush = RGB(0, 0, 0);



void DrawRhombus(HDC hdc, int xStart, int yStart, int xCurrent, int yCurrent)
{
    int xMid = (xStart + xCurrent) / 2;
    int yMid = (yStart + yCurrent) / 2;
    int dx = abs(xCurrent - xStart) / 2;
    int dy = abs(yCurrent - yStart) / 2;

    // Set màu viền và độ dày
    COLORREF color = RGB(255, 0, 0);
    HPEN hPen = CreatePen(PS_SOLID, 3, color);
    hBrush = CreateSolidBrush(colorForHBrush);
    SelectObject(hdc, hPen);

    // Vẽ các đường thẳng

    /*
    * MoveToEx(hdc, xMid + dx, yMid, NULL);
    LineTo(hdc, xMid - dx, yMid);
    LineTo(hdc, xMid, yMid + dy);
    LineTo(hdc, xMid, yMid - dy);
    LineTo(hdc, xMid + dx, yMid);
    */
    

    MoveToEx(hdc, xMid + dx, yMid, NULL);
    LineTo(hdc, xMid, yMid + dy);
    LineTo(hdc, xMid - dx, yMid);
    LineTo(hdc, xMid, yMid - dy);
    LineTo(hdc, xMid + dx, yMid);

    DeleteObject(hPen);
}

void DrawEllipse(HDC hdc, int xStart, int yStart, int xCurrent, int yCurrent)
{
    int xMid = (xStart + xCurrent) / 2;
    int yMid = (yStart + yCurrent) / 2;
    int dx = abs(xCurrent - xStart) / 2;
    int dy = abs(yCurrent - yStart) / 2;

    // Set color and pen properties (optional)
    COLORREF color = RGB(255, 0, 0); // Red color
    int penWidth = 3; // Adjust for desired thickness
    HPEN hPen = CreatePen(PS_SOLID, penWidth, color);
    SelectObject(hdc, hPen); // Select the pen for drawing

    // Bresenham algorithm variables
    int x = 0, y = dy;
    int d1 = (dy * dy) - (dx * dx * dy) + (dx * dx / 4);

    // Draw first octant (adjust for other octants if needed)
    while (x <= dx)
    {
        MoveToEx(hdc, xMid + x, yMid + y, NULL);
        LineTo(hdc, xMid - x, yMid + y);
        LineTo(hdc, xMid + x, yMid - y);
        LineTo(hdc, xMid - x, yMid - y);

        if (d1 < 0)
        {
            d1 += (2 * x + 1);
        }
        else
        {
            d1 += (2 * x - 2 * y + 1);
            y--;
        }
        x++;
    }

    // Draw remaining part of the ellipse (optional, for a complete ellipse)
    y = 0;
    x = dx;
    d1 = (dx * dx) - (dy * dy * dx) + (dy * dy / 4);
    while (y <= dy)
    {
        MoveToEx(hdc, xMid + x, yMid + y, NULL);
        LineTo(hdc, xMid - x, yMid + y);
        LineTo(hdc, xMid + x, yMid - y);
        LineTo(hdc, xMid - x, yMid - y);

        if (d1 < 0)
        {
            d1 += (2 * y + 1);
        }
        else
        {
            d1 += (-2 * x + 2 * y + 1);
            x--;
        }
        y++;
    }

    // Clean up (optional)
    DeleteObject(hPen);
}

HWND hWnd; // Handle của cửa sổ
HDC hdc; // Handle của device context (DC)
bool isDrawing = true; // Biến cờ để theo dõi trạng thái vẽ
int xStart, yStart; // Tọa độ bắt đầu vẽ
int xCurrent, yCurrent; // Tọa độ hiện tại của chuột
static HPEN hpen = CreatePen(PS_SOLID, 3, RGB(0, 0, 0));
int wmId;

int min = 60, sec = 0;
TCHAR leftTime[30];
int width, height;

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {

    case WM_CREATE:
        SetTimer(hWnd, 1, 1000, NULL);
    case WM_LBUTTONDOWN:
        isDrawing = true;
        xStart = LOWORD(lParam);
        yStart = HIWORD(lParam);

        // Set DC cho cửa sổ
        hdc = GetDC(hWnd);

        // Bắt đầu vẽ hình
       

        ReleaseDC(hWnd, hdc);
        break;

    case WM_SIZE:
        width = LOWORD(lParam);
        height = HIWORD(lParam);
        break;

    case WM_MOUSEMOVE:
        if (isDrawing)
        {
            xCurrent = LOWORD(lParam);
            yCurrent = HIWORD(lParam);

            // Set DC cho cửa sổ
            hdc = GetDC(hWnd);

            

            ReleaseDC(hWnd, hdc);
        }
        break;

    case WM_LBUTTONUP:
        if (isDrawing)
        {
            isDrawing = false;

            // Set DC cho cửa sổ
            hdc = GetDC(hWnd);

            // Vẽ lại hình một lần nữa để đảm bảo độ dày viền
            if (wmId == ID_H_Thoi)
            {
                DrawRhombus(hdc, xStart, yStart, xCurrent, yCurrent);
            }
            else if (wmId == ID_H_Ellipse)
            {
                DrawEllipse(hdc, xStart, yStart, xCurrent, yCurrent);
            }

            ReleaseDC(hWnd, hdc);
        }
        break;

    case WM_TIMER:
        if (sec > 0)
        {
            sec = sec - 1;

        }
        else if (sec == 0)
        {
            sec = 59;
            min -= 1;
        }

        wsprintfW(leftTime, L"Time: %d:%d", min, sec);
        hdc = GetDC(hWnd);
        TextOut(hdc, width - 150, height - 40, leftTime, 30);
        ReleaseDC(hWnd, hdc);
        break;

    case WM_COMMAND:
        {
            wmId = LOWORD(wParam);
            // Parse the menu selections:
            switch (wmId)
            {
            case ID_MN_XanhLaCay:
                colorForHBrush = RGB(0, 255, 0);
                break;

            case ID_MN_Vang:
                colorForHBrush = RGB(0, 255, 255);
                break;

            case ID_KN_GachNgang:
                

                break;

          
            case ID_H_Thoat:
                
                if (MessageBox(hWnd, L"Bạn có chắc chắn muốn thoát?", L"Xác nhận thoát", MB_YESNO | MB_ICONQUESTION) == IDYES)
                {
                    // Handle quit logic (e.g., destroy window, send close message)
                    DestroyWindow(hWnd);
                }
                break;

            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: Add any drawing code that uses hdc here...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}


// Message handler for about box.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
