// GameOfLife.cpp : Defines the entry point for the application.
//

#include "framework.h"
#include "windowsx.h"
#include "GameOfLife.h"
#include <vector>
#include <exception>

#define MAX_LOADSTRING 100

class State
{
    bool _isAlive;
    int _lives;
public: 
    State(bool isAlive, int lives)
    {
        if (!isAlive) {
            _lives = 0;
        }
        if (lives = 0) {
            _isAlive = false;
        }
        if (lives > 2 || lives < 0) throw std::exception("Wrong number of lives");
        _isAlive = isAlive;
        _lives = lives;
    }

    bool IsAlive()
    {
        return _isAlive;
    }

    void SetIsAlive(bool isAlive, int lives)
    {
        if (lives > 2 || lives < 0) throw std::exception("Wrong number of lives");
        _isAlive = isAlive;
        _lives = lives;
    }

    int GetLives() {
        return _lives;
    }
};

class Cell
{
    State _state = State(false, 0);

public:

    Cell(State state)
    {
        _state = state;
    }

    Cell()
    {

    }

    bool IsAlive()
    {
        return _state.IsAlive();
    }

    void SetIsAlive(bool isAlive, int lives)
    { 
        if (lives > 2 || lives < 0) throw std::exception("Wrong number of lives");
        if (lives == 0) {
            isAlive = false;
        }
        _state.SetIsAlive(isAlive, lives);
    }

    int GetLives() {
        return _state.GetLives();
    }
};

class Grid
{
    std::vector<std::vector<Cell>> _cells;
    int _width;
    int _height;

public:
    Grid(int width, int height) : _width(width), _height(height)
    {
        _cells.resize(height);

        for (auto rowIndex = 0; rowIndex < height; ++rowIndex)
        {
            _cells[rowIndex].resize(width);
        }
    }

    int GetWidth()
    {
        return _width;
    }

    int GetHeight()
    {
        return _height;
    }

    Cell& GetCell(int rowIndex, int columnIndex)
    {
        if (rowIndex < 0 || rowIndex >= _height) throw std::exception("Wrong rowIndex");
        if (columnIndex < 0 || columnIndex >= _width) throw std::exception("Wrong columnIndex");

        return _cells[rowIndex][columnIndex];
    }

    std::vector< std::vector<Cell>> GetAllCells() {
        return _cells;
    }

};

class LifeEngine
{
public:
    Grid CalculateNext(Grid currentGrid)
    {
        auto newGrid = Grid(currentGrid.GetWidth(), currentGrid.GetHeight());

        auto distance = 1;

        for (auto rowIndex = 0; rowIndex < currentGrid.GetHeight(); ++rowIndex)
        {
            for (auto columnIndex = 0; columnIndex < currentGrid.GetWidth(); ++columnIndex)
            {
                auto aliveCellCount = CalculateAliveNeighbour(rowIndex, columnIndex, currentGrid, distance);

                if (aliveCellCount == 3 && !currentGrid.GetCell(rowIndex, columnIndex).IsAlive())
                {
                    newGrid.GetCell(rowIndex, columnIndex).SetIsAlive(true, 2);
                }
                else if ((aliveCellCount == 2 || aliveCellCount == 3) && currentGrid.GetCell(rowIndex, columnIndex).IsAlive())
                {
                    newGrid.GetCell(rowIndex, columnIndex).SetIsAlive(true, 1);
                }
                else
                {
                   
                    newGrid.GetCell(rowIndex, columnIndex).SetIsAlive(false, 0);
                    
                }
            }
        }

        return newGrid;
    }

private:
    int GetLeftStartIndex(int columnIndex, int gridWidth, int distance)
    {
        if (max(columnIndex - distance, 0) == 0) {
            return gridWidth - 1 - distance;
        }
        return columnIndex - distance;
    }

    int GetTopStartIndex(int rowIndex, int distance)
    {
        return max(rowIndex - distance, 0);
    }

    int GetRightStartIndex(int columnIndex, int gridWidth, int distance)
    {
        if (min(columnIndex + distance, gridWidth - 1) == gridWidth - 1) {
            return  distance;
        }
        return columnIndex + distance;
    }

    int GetBottomStartIndex(int rowIndex, int gridHeight, int distance)
    {
        return min(rowIndex + distance, gridHeight - 1);
    }

    int CalculateAliveNeighbour(int rowIndex, int columnIndex, Grid currentGrid, int distance)
    {
        auto aliveCellCount = 0;

        auto leftStartIndex = GetLeftStartIndex(columnIndex, currentGrid.GetWidth(), distance);

        auto rightStartIndex = GetRightStartIndex(columnIndex, currentGrid.GetWidth(), distance);
        
        auto topStartIndex = GetTopStartIndex(rowIndex, distance);
        
        auto bottomStartIndex = GetBottomStartIndex(rowIndex, currentGrid.GetHeight(), distance);

        for (auto neighbourColumnIndex = leftStartIndex; neighbourColumnIndex <= rightStartIndex; ++neighbourColumnIndex)
        {
            for (auto neighbourRowIndex = topStartIndex; neighbourRowIndex <= bottomStartIndex; ++neighbourRowIndex)
            {
                if (rowIndex == neighbourRowIndex && columnIndex == neighbourColumnIndex) continue;

                if (currentGrid.GetCell(neighbourRowIndex, neighbourColumnIndex).IsAlive())
                {
                    ++aliveCellCount;
                }
            }
        }

        return aliveCellCount;
    }
};

Grid grid = Grid(10, 10);
LifeEngine lifeEngine;












HINSTANCE hInst;                               
WCHAR szTitle[MAX_LOADSTRING];                 
WCHAR szWindowClass[MAX_LOADSTRING];           

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

    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_GAMEOFLIFE, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_GAMEOFLIFE));

    MSG msg;

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








ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_GAMEOFLIFE));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_GAMEOFLIFE);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; 

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








int GetCol(HWND hWnd, Grid grid, int x) {
    RECT clientRect;
    GetClientRect(hWnd, &clientRect);
    auto cellWidth = clientRect.right / grid.GetWidth();
    for (auto j = 0; j < grid.GetWidth() + 1; ++j)
    {
        if (x < ((j + 1) * cellWidth) && x >(j * cellWidth))
            return j;
    }
}

int GetRow(HWND hWnd, Grid grid, int x) {
    RECT clientRect;
    GetClientRect(hWnd, &clientRect);
    auto cellHeight = clientRect.bottom / grid.GetHeight();
    for (auto i = 0; i < grid.GetHeight() + 1; ++i)
    {
        if (x < ((i + 1) * cellHeight) && x >(i * cellHeight))
            return i;
    }
}

void DrawGrid(HWND hWnd, HDC hdc)
{
    RECT clientRect;
    GetClientRect(hWnd, &clientRect);

    auto cellWidth = clientRect.right / grid.GetWidth();

    for (auto j = 0; j < grid.GetWidth() + 1; ++j)
    {
        MoveToEx(hdc, cellWidth * j, 0, nullptr);
        LineTo(hdc, cellWidth * j, clientRect.bottom);
    }

    auto cellHeight = clientRect.bottom / grid.GetHeight();

    for (auto i = 0; i < grid.GetHeight() + 1; ++i)
    {
        MoveToEx(hdc, 0, cellHeight * i, nullptr);
        LineTo(hdc, clientRect.right, cellHeight * i);
    }
}

void DrawCells(HWND hWnd, HDC hdc)
{
    RECT clientRect;
    GetClientRect(hWnd, &clientRect);

    auto cellWidth = clientRect.right / grid.GetWidth();
    auto cellHeight = clientRect.bottom / grid.GetHeight();

    auto brush_alive = CreateSolidBrush(RGB(0, 0, 0));
    auto brush_halfdead = CreateSolidBrush(RGB(100, 100, 100));

    for (auto i = 0; i < grid.GetHeight(); ++i)
    {
        for (auto j = 0; j < grid.GetWidth(); ++j)
        {
            if (grid.GetCell(i, j).IsAlive() && grid.GetCell(i, j).GetLives() == 2)
            {
                SelectObject(hdc, brush_alive);
                Ellipse(hdc, j * cellWidth, i * cellHeight, (j + 1) * cellWidth, (i + 1) * cellHeight);
            }
            if (grid.GetCell(i, j).IsAlive() && grid.GetCell(i, j).GetLives() == 1)
            {
                SelectObject(hdc, brush_halfdead);
                Ellipse(hdc, j * cellWidth, i * cellHeight, (j + 1) * cellWidth, (i + 1) * cellHeight);
            }
        }
    }

    DeleteObject(brush_alive);
    DeleteObject(brush_halfdead);
}

void OnPaint(HWND hWnd, int x, int y)
{
    PAINTSTRUCT ps;
    HDC hdc = BeginPaint(hWnd, &ps);
    RECT clientRect;
    GetClientRect(hWnd, &clientRect);

    auto cellWidth = clientRect.right / grid.GetWidth();
    auto cellHeight = clientRect.bottom / grid.GetHeight();
    
    auto br = CreateSolidBrush(RGB(255, 255, 0));
    SelectObject(hdc, br);
    Rectangle(hdc, x * cellWidth, y * cellHeight, (x + 1) * cellWidth, (y + 1) * cellHeight);
    DeleteObject(br);

    DrawGrid(hWnd, hdc);
    DrawCells(hWnd, hdc);

    EndPaint(hWnd, &ps);
}











LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    static int x, y;
    static int coor_x, coor_y, hcoor_x, hcoor_y;
    static int hover_x, hover_y;
    RECT clientRect;
    GetClientRect(hWnd, &clientRect);
    static int P_Value = 0;
    static int key;
    static bool Control = false;
    switch (message)
    {
    case WM_CREATE:

        grid.GetCell(1, 1).SetIsAlive(true, 2);
        grid.GetCell(1, 2).SetIsAlive(true, 2);
        grid.GetCell(2, 0).SetIsAlive(true, 2);
        grid.GetCell(3, 1).SetIsAlive(true, 2);
        grid.GetCell(2, 4).SetIsAlive(true, 2);
        grid.GetCell(2, 3).SetIsAlive(true, 2);
        grid.GetCell(0, 1).SetIsAlive(true, 2);
        grid.GetCell(0, 0).SetIsAlive(true, 2);
        grid.GetCell(1, 3).SetIsAlive(true, 2);
        grid.GetCell(4, 1).SetIsAlive(true, 2);
        grid.GetCell(4, 2).SetIsAlive(true, 2);

        if (P_Value % 2 == 0) {
            SetTimer(hWnd, 1, 1000, NULL);
        }
        break;

    case WM_TIMER:
        grid = lifeEngine.CalculateNext(grid);
        InvalidateRect(hWnd, nullptr, true);
        break;
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
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
        OnPaint(hWnd, hover_x, hover_y);
        }
        break;
    case WM_LBUTTONDOWN:
        coor_x = LOWORD(lParam);
        coor_y = HIWORD(lParam);
        x = GetRow(hWnd, grid, coor_y);
        y = GetCol(hWnd, grid, coor_x);
        grid.GetCell(x, y).SetIsAlive(true, 2);
        InvalidateRect(hWnd, NULL, TRUE);
        OnPaint(hWnd, hover_x, hover_y);
        break;
    case WM_RBUTTONDOWN: {
        coor_x = LOWORD(lParam);
        coor_y = HIWORD(lParam);
        x = GetRow(hWnd, grid, coor_y);
        y = GetCol(hWnd, grid, coor_x);
        int life = grid.GetCell(x, y).GetLives();
        grid.GetCell(x, y).SetIsAlive(true, life - 1);
        InvalidateRect(hWnd, NULL, TRUE);
        OnPaint(hWnd, hover_x, hover_y);
        break;
    }
    case WM_MOUSEMOVE:
    {
        coor_x = LOWORD(lParam);
        coor_y = HIWORD(lParam);
        hover_y = GetRow(hWnd, grid, coor_y);
        hover_x = GetCol(hWnd, grid, coor_x);
        InvalidateRect(hWnd, nullptr, true);
        break;
    }
    case WM_MOUSEWHEEL:
    {
        int fwKeys = GET_KEYSTATE_WPARAM(wParam);
        int zDelta = GET_WHEEL_DELTA_WPARAM(wParam);
        int AddCell = zDelta / 120;
        if (zDelta > 0 && grid.GetWidth() + AddCell <= 25 && fwKeys != MK_SHIFT) {
            Grid NewGrid(grid.GetWidth() + AddCell, grid.GetHeight());
            for (int i = 0; i < grid.GetAllCells().size(); ++i) {
                for (int l = 0; l < ((grid.GetAllCells())[i]).size(); ++l) {
                    bool current_state = (((grid.GetAllCells())[i])[l]).IsAlive();
                    int current_lives = (((grid.GetAllCells())[i])[l]).GetLives();
                    NewGrid.GetCell(i, l).SetIsAlive(current_state, current_lives);
                }
            }
            grid = lifeEngine.CalculateNext(NewGrid);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        if (zDelta < 0 && grid.GetWidth() + AddCell >= 3 && fwKeys != MK_SHIFT) {
            Grid NewGrid(grid.GetWidth() + AddCell, grid.GetHeight());
            for (int i = 0; i < NewGrid.GetAllCells().size(); ++i) {
                for (int l = 0; l < ((NewGrid.GetAllCells())[i]).size(); ++l) {
                    bool current_state = (((grid.GetAllCells())[i])[l]).IsAlive();
                    int current_lives = (((grid.GetAllCells())[i])[l]).GetLives();
                    NewGrid.GetCell(i, l).SetIsAlive(current_state, current_lives);
                }
            }
            grid = lifeEngine.CalculateNext(NewGrid);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        if (zDelta > 0 && grid.GetHeight() + AddCell <= 25 && fwKeys == MK_SHIFT) {
            Grid NewGrid(grid.GetWidth(), grid.GetHeight() + AddCell);
            for (int i = 0; i < grid.GetAllCells().size(); ++i) {
                for (int l = 0; l < ((grid.GetAllCells())[i]).size(); ++l) {
                    bool current_state = (((grid.GetAllCells())[i])[l]).IsAlive();
                    int current_lives = (((grid.GetAllCells())[i])[l]).GetLives();
                    NewGrid.GetCell(i, l).SetIsAlive(current_state, current_lives);
                }
            }
            grid = lifeEngine.CalculateNext(NewGrid);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        if (zDelta < 0 && grid.GetHeight() + AddCell >= 3 && fwKeys == MK_SHIFT) {
            Grid NewGrid(grid.GetWidth(), grid.GetHeight() + AddCell);
            for (int i = 0; i < NewGrid.GetAllCells().size(); ++i) {
                for (int l = 0; l < ((NewGrid.GetAllCells())[i]).size(); ++l) {
                    bool current_state = (((grid.GetAllCells())[i])[l]).IsAlive();
                    int current_lives = (((grid.GetAllCells())[i])[l]).GetLives();
                    NewGrid.GetCell(i, l).SetIsAlive(current_state, current_lives);
                }
            }
            grid = lifeEngine.CalculateNext(NewGrid);
            InvalidateRect(hWnd, NULL, TRUE);
        }
        break;
    }
    case WM_KEYDOWN:
        key = wParam;
        switch (key) {
        case VK_SPACE:
            ++P_Value;
            if (P_Value % 2 == 0) {
                SetTimer(hWnd, 1, 1000, NULL);
            }
            else {
                KillTimer(hWnd, 1);
            }
            break;
        case VK_CONTROL:
            Control = true;
            break;
        }
        break;
    case WM_KEYUP:
        switch (wParam) {
        case VK_CONTROL:
            Control = false;
            break;
        }
        break;
    case WM_SYSKEYDOWN:
        switch (wParam) {
        case VK_F10:
            if (P_Value % 2 == 1 && !Control) {
                grid = lifeEngine.CalculateNext(grid);
                InvalidateRect(hWnd, NULL, TRUE);
                OnPaint(hWnd, hover_x, hover_y);
            }
            if (P_Value % 2 == 1 && Control) {
                for (int i = 0; i < 5; ++i) {
                    grid = lifeEngine.CalculateNext(grid);
                }
                InvalidateRect(hWnd, NULL, TRUE);
            }
            break;
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
