#include <windows.h>
#include <cstdio> 

const char g_szClassName[] = "CalculatorWindow";


char buffer[256] = "";
double firstNumber = 0.0, secondNumber = 0.0;
char currentOperation = '\0';


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam);


HWND CreateButton(HWND hwnd, const char* text, int x, int y, int width, int height, int id) {
    return CreateWindow("BUTTON", text, WS_VISIBLE | WS_CHILD, x, y, width, height, hwnd, (HMENU)(intptr_t)id, NULL, NULL);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    WNDCLASSEX wc;
    HWND hwnd;
    MSG Msg;


    wc.cbSize = sizeof(WNDCLASSEX);
    wc.style = 0;
    wc.lpfnWndProc = WndProc;
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    wc.hInstance = hInstance;
    wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor = LoadCursor(NULL, IDC_ARROW);
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
    wc.lpszMenuName = NULL;
    wc.lpszClassName = g_szClassName;
    wc.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

    if (!RegisterClassEx(&wc)) {
        MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }


    hwnd = CreateWindowEx(
        WS_EX_CLIENTEDGE,
        g_szClassName,
        "Calculator",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 300, 400,
        NULL, NULL, hInstance, NULL);

    if (hwnd == NULL) {
        MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
        return 0;
    }

    ShowWindow(hwnd, nCmdShow);
    UpdateWindow(hwnd);


    while (GetMessage(&Msg, NULL, 0, 0) > 0) {
        TranslateMessage(&Msg);
        DispatchMessage(&Msg);
    }

    return Msg.wParam;
}

#include <cmath>

void HandleButtonClick(HWND hwnd, WPARAM wParam) {
    switch (wParam) {
        case 1: case 2: case 3: case 4: case 5: case 6: case 7: case 8: case 9: case 0:
            sprintf(buffer, "%s%c", buffer, (char)(wParam + '0'));
            break;
        case '+':
        case '-':
        case '*':
        case '/':
            firstNumber = atof(buffer);
            currentOperation = (char)wParam;
            buffer[0] = '\0';
            break;
        case '=':
            secondNumber = atof(buffer);
            double result;

            if (currentOperation == '+') result = firstNumber + secondNumber;
            else if (currentOperation == '-') result = firstNumber - secondNumber;
            else if (currentOperation == '*') result = firstNumber * secondNumber;
            else if (currentOperation == '/') {
                if (secondNumber == 0) {
                    strcpy(buffer, "Error");
                    break;
                }
                result = firstNumber / secondNumber;
            }

            // Check if the result is an integer
            if (std::floor(result) == result) {
                sprintf(buffer, "%.0f", result); // Display as integer if no fractional part
            } else {
                sprintf(buffer, "%f", result); // Display as float otherwise
            }
            break;
        case 'C':
            buffer[0] = '\0';
            firstNumber = secondNumber = 0;
            currentOperation = '\0';
            break;
    }
    SetWindowText(GetDlgItem(hwnd, 100), buffer);
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
    switch (msg) {
        case WM_CREATE:
            CreateWindow("STATIC", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 20, 20, 240, 30, hwnd, (HMENU)100, NULL, NULL);
            CreateButton(hwnd, "1", 20, 60, 50, 50, 1);
            CreateButton(hwnd, "2", 80, 60, 50, 50, 2);
            CreateButton(hwnd, "3", 140, 60, 50, 50, 3);
            CreateButton(hwnd, "+", 200, 60, 50, 50, '+');

            CreateButton(hwnd, "4", 20, 120, 50, 50, 4);
            CreateButton(hwnd, "5", 80, 120, 50, 50, 5);
            CreateButton(hwnd, "6", 140, 120, 50, 50, 6);
            CreateButton(hwnd, "-", 200, 120, 50, 50, '-');

            CreateButton(hwnd, "7", 20, 180, 50, 50, 7);
            CreateButton(hwnd, "8", 80, 180, 50, 50, 8);
            CreateButton(hwnd, "9", 140, 180, 50, 50, 9);
            CreateButton(hwnd, "*", 200, 180, 50, 50, '*');

            CreateButton(hwnd, "0", 20, 240, 50, 50, 0);
            CreateButton(hwnd, "C", 80, 240, 50, 50, 'C');
            CreateButton(hwnd, "=", 140, 240, 50, 50, '=');
            CreateButton(hwnd, "/", 200, 240, 50, 50, '/');
            break;
            

        case WM_COMMAND:
            HandleButtonClick(hwnd, wParam);
            break;

        case WM_CLOSE:
            DestroyWindow(hwnd);
            break;

        case WM_DESTROY:
            PostQuitMessage(0);
            break;

        default:
            return DefWindowProc(hwnd, msg, wParam, lParam);
    }
    return 0;
}

