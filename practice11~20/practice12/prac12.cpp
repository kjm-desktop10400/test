#include<windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){

    switch(msg){
        case WM_SYSCOMMAND:
            MessageBox(hwnd, TEXT("recieve WM_SYSCOMMAND"), TEXT("wnd msg"), MB_ICONINFORMATION);
            break;
        case WM_CLOSE:
            MessageBox(hwnd, TEXT("recieve WM_CLOSE"), TEXT("wnd msg"), MB_ICONINFORMATION);
            return 0;
        case WM_LBUTTONUP:
            MessageBox(hwnd, TEXT("recieve WM_LBUTTONUP"), TEXT("wnd msg"), MB_ICONINFORMATION);
            PostQuitMessage(0);
            break;
    }

    return DefWindowProc(hwnd, msg, wp, lp);

}

int WINAPI WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        PSTR lpCmdLine,
        int nCmdShow
        ){

	HWND hwnd;
	MSG msg;
	WNDCLASS winc;

	winc.style		= CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc	= WndProc;
	winc.cbClsExtra	= winc.cbWndExtra	= 0;
	winc.hInstance		= hInstance;
	winc.hIcon		= LoadIcon(NULL , IDI_APPLICATION);
	winc.hCursor		= LoadCursor(NULL , IDC_ARROW);
	winc.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName	= NULL;
	winc.lpszClassName	= TEXT("WND");

	if (!RegisterClass(&winc)) return 0;

	hwnd = CreateWindow(
			TEXT("wnd") , TEXT("prac12.exe") ,
			WS_OVERLAPPEDWINDOW  | WS_VISIBLE ,
			1000 , 500 , 300 , 200 , NULL , NULL ,
			hInstance , NULL
	);

	if (hwnd == NULL) return 0;

	while (GetMessage(&msg , NULL , 0 , 0)) DispatchMessage(&msg);
	return msg.wParam;

}