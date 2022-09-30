#include<windows.h>

int WINAPI WinMain(
                    HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    PSTR lpCmdLine,
                    int nCmdShow
){

    HWND hwnd1 =  CreateWindow(
        TEXT("STATIC"), TEXT("kitty on your lap"),
        WS_CAPTION && WS_CLIPCHILDREN,
        100, 100 , 200, 200,
        NULL, NULL,
        hInstance, NULL
    );

    if (hwnd1 == NULL) return 0;

    HWND hwnd2 =  CreateWindow(
        TEXT("BUTTON"), TEXT("kitty on your lap"),
        WS_BORDER && WS_CAPTION && WS_CHILD,
        200, 400 , 200, 200,
        hwnd1, NULL,
        hInstance, NULL
    );

    if(hwnd2 == NULL) return 0;

    ShowWindow(hwnd1, SW_SHOW);
    ShowWindow(hwnd2, SW_SHOW);

    MessageBox(NULL, TEXT("kitty on your lap"), TEXT("kitty"), MB_ICONINFORMATION);

    return 0;
}