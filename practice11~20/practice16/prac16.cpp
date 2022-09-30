#include<windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){

    HDC hDC;

    switch(msg){
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        case WM_LBUTTONUP:
            hDC = GetDC(hwnd);
            TextOut(hDC, 10, lp, TEXT("lmb upped"), lstrlen(TEXT("lmb upped")));
            if(!ReleaseDC(hwnd, hDC)) return 0;
                MessageBox(hwnd, TEXT("couldnt release DC"), TEXT("error"), MB_ICONINFORMATION);
            return 0;    
    }

    return DefWindowProcW(hwnd, msg, wp, lp);

}

int WINAPI WinMain(HINSTANCE hInstance,
                    HINSTANCE hPrevInstance,
                    PSTR lpCmdLind,
                    int nCmdShow)
{

    HWND hwnd;
    WNDCLASS winc;
    MSG msg;
    int line_count = 0;

	winc.style		= CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc	= WndProc;
	winc.cbClsExtra	= winc.cbWndExtra	= 0;
	winc.hInstance		= hInstance;
	winc.hIcon		= LoadIcon(NULL , IDI_APPLICATION);
	winc.hCursor		= LoadCursor(NULL , IDC_ARROW);
	winc.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName	= NULL;
	winc.lpszClassName	= TEXT("WND");

    if(!RegisterClass(&winc)) {
        MessageBox(hwnd, TEXT("couldnt register window class"), TEXT("error"), MB_ICONINFORMATION);
        return 0;
    }

    hwnd = CreateWindow(TEXT("WND"), TEXT("prac16"),
				WS_OVERLAPPEDWINDOW | WS_VISIBLE,
				CW_USEDEFAULT, CW_USEDEFAULT,
				CW_USEDEFAULT, CW_USEDEFAULT,
				NULL, NULL, hInstance, NULL
			);
    
    if(hwnd == NULL) {
        MessageBox(hwnd, TEXT("couldnt create window"), TEXT("error"), MB_ICONINFORMATION);
        return 0;
    }

    line_count = 10;
    while(GetMessage(&msg, NULL, 0, 0)) {

        if(msg.message == WM_LBUTTONUP){
            msg.lParam = line_count;
            line_count += 10;
        }
        DispatchMessage(&msg);
    }

    return 0;
}