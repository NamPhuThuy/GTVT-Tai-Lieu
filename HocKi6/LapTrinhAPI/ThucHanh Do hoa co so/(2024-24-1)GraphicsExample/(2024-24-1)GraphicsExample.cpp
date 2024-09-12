// (2024-24-1)GraphicsExample.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "(2024-24-1)GraphicsExample.h"

#define MAX_LOADSTRING 100

// Global Variables:
HINSTANCE hInst;                                // current instance
WCHAR szTitle[MAX_LOADSTRING];                  // The title bar text
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
    LoadStringW(hInstance, IDC_MY2024241GRAPHICSEXAMPLE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Perform application initialization:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_MY2024241GRAPHICSEXAMPLE));

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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_MY2024241GRAPHICSEXAMPLE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_MY2024241GRAPHICSEXAMPLE);
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

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
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
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static HDC hdc;
    static int x, y;
    static int count = 0;
    static POINT point[10000];

    static int width, height;

    switch (message)
    {
        //Khi thay đổi kích thước cửa sổ
        case WM_SIZE:
            /*
            * x = LOWORD(lParam);
            y = HIWORD(lParam);
            hdc = GetDC(hWnd);
            MoveToEx(hdc, 0, 0, NULL);
            LineTo(hdc, x, y);
            ReleaseDC(hWnd, hdc);
            */


            width = LOWORD(lParam);
            height = LOWORD(lParam);
            hdc = GetDC(hWnd);
            Rectangle(hdc, width / 6, height / 6, 5 * width / 6, 5 * height / 6);
            
            MoveToEx(hdc, 0, 0, NULL);
            LineTo(hdc, width, height);

            MoveToEx(hdc, 0, height, NULL);
            LineTo(hdc, width, 0);

            Ellipse(hdc, width/6, height/6, 5 * width / 6, 5 * height / 6);
            RoundRect(hdc, width / 4, height / 4, 3 * width / 4, 3 * height / 4, 300, 200);

            ReleaseDC(hWnd, hdc);

            

            break;
        case WM_LBUTTONDOWN: //Thông điệp nhấn chuột trái
        
            /*
            x = LOWORD(lParam);
            y = HIWORD(lParam);

            hdc = GetDC(hWnd);
            SetPixel(hdc, x, y, RGB(128, 0, 128));
            */


            //Kể từ lần nhấn chuột trái thứ hai, vẽ 1 đoạn thẳng nối điểm hiên thời và điểm trước đó lại với nhau
            point[count].x = LOWORD(lParam);
            point[count].y = HIWORD(lParam);
            hdc = GetDC(hWnd);
            SetPixel(hdc, point[count].x, point[count].y, 0);

            if (count > 0)
            {
                
                MoveToEx(hdc, point[count - 1].x, point[count - 1].y, nullptr);
                LineTo(hdc, point[count].x, point[count].y);
                
            }
            

            ReleaseDC(hWnd, hdc);
            count += 1;
            //
            break;

        case WM_RBUTTONDOWN:
            //Nhấn chuột phải xoá miền thao tác
            /*
            * InvalidateRect(hWnd, nullptr, TRUE);
            count = 0;
            */
            point[count].x = LOWORD(lParam);
            point[count].y = HIWORD(lParam);
            count += 1;

            hdc = GetDC(hWnd);

            //SetPixel(hdc, point[count].x, point[count].y, 0);
            Polyline(hdc, point, count);

            ReleaseDC(hWnd, hdc);
            break;
            //

        case WM_LBUTTONDBLCLK:
            //Click đúp chuột trái vẽ gấp khúc
            hdc = GetDC(hWnd);
            for (int i = 0; i < count - 1; i++) {
                MoveToEx(hdc, point[i].x, point[i].y, nullptr);
                LineTo(hdc, point[i + 1].x, point[i + 1].y);
            }
            ReleaseDC(hWnd, hdc);
            //

            break;

        case WM_COMMAND:
            {
                int wmId = LOWORD(wParam);
                // Parse the menu selections:
                switch (wmId)
                {
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
                for (int i = 30; i < 130; i++)
                    SetPixel(hdc, 50, i, RGB(128, 0, 128));

                for (int i = 50, j = 30; i < 150; i++, j++)
                {
                    SetPixel(hdc, i, j, RGB(128, 0, 128));
                }

                for (int i = 30; i < 130; i++)
                    SetPixel(hdc, 150, i, RGB(128, 0, 128));

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
