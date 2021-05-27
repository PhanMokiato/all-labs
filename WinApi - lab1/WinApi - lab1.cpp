// WinApi - lab1.cpp : Определяет точку входа для приложения.
//


#include "pch.h"
#include "framework.h"
#include "WinApi - lab1.h"
#include <cmath>
#include "wchar.h"

#define _USE_MATH_DEFINES
#include "math.h"

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;                                // текущий экземпляр
WCHAR szTitle[MAX_LOADSTRING];                  // Текст строки заголовка
WCHAR szWindowClass[MAX_LOADSTRING];            // имя класса главного окна

// Отправить объявления функций, включенных в этот модуль кода:
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

    // TODO: Разместите код здесь.

    // Инициализация глобальных строк
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINAPILAB1, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // Выполнить инициализацию приложения:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINAPILAB1));

    MSG msg;

    // Цикл основного сообщения:
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
//  ФУНКЦИЯ: MyRegisterClass()
//
//  ЦЕЛЬ: Регистрирует класс окна.
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
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINAPILAB1));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINAPILAB1);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   ЦЕЛЬ: Сохраняет маркер экземпляра и создает главное окно
//
//   КОММЕНТАРИИ:
//
//        В этой функции маркер экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // Сохранить маркер экземпляра в глобальной переменной

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, 600, 400, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ЦЕЛЬ: Обрабатывает сообщения в главном окне.
//
//  WM_COMMAND  - обработать меню приложения
//  WM_PAINT    - Отрисовка главного окна
//  WM_DESTROY  - отправить сообщение о выходе и вернуться
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static short x0, y0;
    static int cx, cy;
    static double p, fi;
    static double timer_value = 0.0;
    WCHAR string0[30] = (L"Координаты круга: ");
    WCHAR* str1 = new WCHAR[4];
    WCHAR* str2 = new WCHAR[4];
    WCHAR space[3] = (L", ");
    static WCHAR FontName[15] = (L"Century Gothic");
    switch (message)
    {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Разобрать выбор в меню:
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
    case WM_SIZE:
        x0 = LOWORD(lParam);
        y0 = HIWORD(lParam);
        break;
    case WM_CREATE:
        SetTimer(hWnd, 1, 100, NULL);
    case WM_TIMER:
        timer_value += 0.1;
        if (timer_value >= 2 * M_PI) {
            KillTimer(hWnd, 1);
        }
        InvalidateRect(hWnd, NULL, TRUE);
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            WCHAR string[30];
            wcscpy_s(string, string0);
            HDC hdc = BeginPaint(hWnd, &ps);
            LOGBRUSH LB;
            LB.lbColor = RGB(37, 241, 154);
            LB.lbStyle = BS_SOLID;
            HPEN pen1 = ExtCreatePen(PS_GEOMETRIC | PS_DASH, 2, &LB, 0, NULL);
            SelectObject(hdc, pen1);
            MoveToEx(hdc, x0 / 2, 0, NULL);
            LineTo(hdc, x0 / 2 - 20, 20);
            MoveToEx(hdc, x0 / 2, 0, NULL);
            LineTo(hdc, x0 / 2 + 20, 20);
            MoveToEx(hdc, x0 / 2, 0, NULL);
            LineTo(hdc, x0 / 2, y0);
            LineTo(hdc, x0 / 2 - 20, y0 - 20);
            MoveToEx(hdc, x0 / 2, y0, NULL);
            LineTo(hdc, x0 / 2 + 20, y0 - 20);
            MoveToEx(hdc, 0, y0 / 2, NULL);
            LineTo(hdc, 20, y0 / 2 - 20);
            MoveToEx(hdc, 0, y0 / 2, NULL);
            LineTo(hdc, 20, y0 / 2 + 20);
            MoveToEx(hdc, 0, y0 / 2, NULL);
            LineTo(hdc, x0, y0 / 2);
            LineTo(hdc, x0 - 20, y0 / 2 - 20);
            MoveToEx(hdc, x0, y0 / 2, NULL);
            LineTo(hdc, x0 - 20, y0 / 2 + 20);
            for (int y = y0 / 2; y < y0; y += 20) {
                MoveToEx(hdc, x0 / 2 - 10, y, NULL);
                LineTo(hdc, x0 / 2 + 10, y);
            }
            for (int y = y0 / 2; y > 0; y -= 20) {
                MoveToEx(hdc, x0 / 2 - 10, y, NULL);
                LineTo(hdc, x0 / 2 + 10, y);
            }
            for (int x = x0 / 2; x < x0; x += 20) {
                MoveToEx(hdc, x, y0 / 2 - 10, NULL);
                LineTo(hdc, x, y0 / 2 + 10);
            }
            for (int x = x0 / 2; x > 0; x -= 20) {
                MoveToEx(hdc, x, y0 / 2 - 10, NULL);
                LineTo(hdc, x, y0 / 2 + 10);
            }
            DeleteObject(pen1);
            HPEN pen2 = CreatePen(PS_SOLID, 2, RGB(252, 84, 185));
            SelectObject(hdc, pen2);

            MoveToEx(hdc, x0 / 2, y0 / 2, NULL);

            HBRUSH brush1 = CreateSolidBrush(RGB(60, 211, 255));
            SelectObject(hdc, brush1);
            double TwoPi = 2 * M_PI;
            for (fi = 0.0; fi < timer_value; fi += 0.025) {
                p = sin(3 * fi / 7);
                cx = (int)(p * cos(fi) * 100);
                cy = - (int)(p * sin(fi) * 100);
                LineTo(hdc, x0 / 2 + cx, y0 / 2 + cy);
            }
            Ellipse(hdc, x0 / 2 + cx - 20, y0 / 2 + cy - 20, x0 / 2 + cx + 20, y0 / 2 + cy + 20);
            static LOGFONT lf;
            lf.lfCharSet = DEFAULT_CHARSET;
            lf.lfPitchAndFamily = DEFAULT_PITCH;
            wcscpy_s(lf.lfFaceName, FontName);
           _itow_s(cx, str1, 4, 10);
           _itow_s(cy, str2, 4, 10);
           wcscat_s(string, str1);
           wcscat_s(string, space);
           wcscat_s(string, str2);
            lf.lfHeight = 15;
            HFONT hFontN1 = CreateFontIndirect(&lf); 
            SelectObject(hdc, hFontN1);

            TextOut(hdc, 10, 10, string, wcslen(string));


            DeleteObject(hFontN1);
            DeleteObject(brush1);
            DeleteObject(pen2);
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        KillTimer(hWnd, 1);
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }

    delete[] str1;
    delete[] str2;
    return 0;
}

// Обработчик сообщений для окна "О программе".
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
