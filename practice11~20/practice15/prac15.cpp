#include<windows.h>

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){

	switch(msg){
		case WM_DESTROY :
			PostQuitMessage(0);
			return 0;
		case WM_LBUTTONUP:
			LPTSTR lptstr = TEXT("kitty on your lap");
			HDC hDC = GetDC(hwnd);
			TextOut(hDC, 10, 10, lptstr, lstrlen(lptstr));
			if(!ReleaseDC(hwnd, hDC)) {
				MessageBox(hwnd, TEXT("couldnt release DC"), TEXT("error"), MB_ICONINFORMATION);
			}
			PostQuitMessage(0);

			return 0;
	}

	return DefWindowProc(hwnd, msg, wp, lp);
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow){

    HWND hwnd;
    WNDCLASS winc;
    MSG msg;

	winc.style		= CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc	= WndProc;
	winc.cbClsExtra	= winc.cbWndExtra	= 0;
	winc.hInstance		= hInstance;
	winc.hIcon		= LoadIcon(NULL , IDI_APPLICATION);
	winc.hCursor		= LoadCursor(NULL , IDC_ARROW);
	winc.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName	= NULL;
	winc.lpszClassName	= TEXT("WND");

    if(!RegisterClass(&winc)) return 0;

	hwnd = CreateWindow(TEXT("WND"), TEXT("kitty on your lap"),
				WS_OVERLAPPEDWINDOW | WS_VISIBLE,
				CW_USEDEFAULT, CW_USEDEFAULT,
				CW_USEDEFAULT, CW_USEDEFAULT,
				NULL, NULL, hInstance, NULL
			);    

	if(hwnd == NULL) return 0;

	while(GetMessage(&msg, NULL, 0, 0)) DispatchMessage(&msg);
	return msg.wParam;

}