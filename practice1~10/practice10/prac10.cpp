#include<windows.h>
#include<stdlib.h>

#define O_WM_LMBUP 101

LRESULT CALLBACK WndProc1(HWND hwnd , UINT msg , WPARAM wp , LPARAM lp) {
	if (msg == O_WM_LMBUP) {
		MessageBox(hwnd , TEXT("pushed LMB on wnd2") ,
			 TEXT("wnd1") , MB_ICONINFORMATION);
		exit(0);
	}
	return DefWindowProc(hwnd , msg , wp , lp);
}

LRESULT CALLBACK WndProc2(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){
	if(msg == WM_LBUTTONUP){
		MessageBox(hwnd, TEXT("pushed LMB on wnd2"), 
			TEXT("wnd2"), MB_ICONINFORMATION);
	}
	return DefWindowProc(hwnd, msg, wp, lp);
}

int WINAPI WinMain(HINSTANCE hInstance , HINSTANCE hPrevInstance ,
		 PSTR lpCmdLine , int nCmdShow ) {
	HWND hwnd1, hwnd2;
	MSG msg;
	WNDCLASS winc1, winc2;

	winc1.style		= CS_HREDRAW | CS_VREDRAW;
	winc1.lpfnWndProc	= WndProc1;
	winc1.cbClsExtra	= winc1.cbWndExtra	= 0;
	winc1.hInstance		= hInstance;
	winc1.hIcon		= LoadIcon(NULL , IDI_APPLICATION);
	winc1.hCursor		= LoadCursor(NULL , IDC_ARROW);
	winc1.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc1.lpszMenuName	= NULL;
	winc1.lpszClassName	= TEXT("WND1");

	if (!RegisterClass(&winc1)) return 0;

	winc2.style		= CS_HREDRAW | CS_VREDRAW;
	winc2.lpfnWndProc	= WndProc2;
	winc2.cbClsExtra	= winc2.cbWndExtra	= 0;
	winc2.hInstance		= hInstance;
	winc2.hIcon		= LoadIcon(NULL , IDI_APPLICATION);
	winc2.hCursor		= LoadCursor(NULL , IDC_ARROW);
	winc2.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc2.lpszMenuName	= NULL;
	winc2.lpszClassName	= TEXT("WND2");

	if(!RegisterClass(&winc2)) return 0;

	hwnd1 = CreateWindow(
			TEXT("WND1") , TEXT("WND1") ,
			WS_OVERLAPPEDWINDOW  | WS_VISIBLE ,
			100 , 100 , 300 , 200 , NULL , NULL ,
			hInstance , NULL
	);

	if (hwnd1 == NULL) return 0;

    hwnd2 = CreateWindow(
            TEXT("WND2"), TEXT("WND2"),
            WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            200, 200, 300, 200, NULL, NULL,
            hInstance, NULL
    );

	if(hwnd2 == NULL) return 0;

	while (TRUE) {
		GetMessage(&msg , NULL , 0 , 0);
		if(msg.hwnd == hwnd2 && msg.message == WM_LBUTTONUP){
			msg.hwnd = hwnd1;
			msg.message = O_WM_LMBUP;
		}
		DispatchMessage(&msg);
	}
	return 0;
}