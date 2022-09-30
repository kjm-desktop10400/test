#include<windows.h>

#define O_WM_LBUTTONUP 1000

MSG msg2;

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){

    switch(msg){
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        case O_WM_LBUTTONUP:
            if(wp == 1){
                MessageBox(hwnd, TEXT("got O_WM_LBUTTONUP"), TEXT("msg"), MB_ICONINFORMATION);
                PostQuitMessage(0);
            }
            break;
    }
    return DefWindowProc(hwnd, msg, wp, lp);
}

LRESULT CALLBACK WndProc2(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp){
    
    if(msg == WM_LBUTTONUP){
        return O_WM_LBUTTONUP;
    }
    else if(msg == WM_DESTROY){
        MessageBox(hwnd, TEXT("destroied wnd2"), TEXT("recieved WM_DESTORY"), MB_ICONINFORMATION);
        PostQuitMessage(0);
    }

    return DefWindowProc(hwnd, msg, wp, lp);
}

int WINAPI WinMain(
    HINSTANCE hInstance, 
    HINSTANCE hPrevInstance,
    PSTR lpCmdLine,
    int nCmdShow){

    HWND hwnd;
    HWND hwnd2;
	MSG msg1;
    MSG msg2;
	WNDCLASS winc, winc2;

	winc.style		= CS_HREDRAW | CS_VREDRAW;
	winc.lpfnWndProc	= WndProc;
	winc.cbClsExtra	= winc.cbWndExtra	= 0;
	winc.hInstance		= hInstance;
	winc.hIcon		= LoadIcon(NULL , IDI_APPLICATION);
	winc.hCursor		= LoadCursor(NULL , IDC_ARROW);
	winc.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc.lpszMenuName	= NULL;
	winc.lpszClassName	= TEXT("KITTY");

    winc2.style		= CS_HREDRAW | CS_VREDRAW;
	winc2.lpfnWndProc	= WndProc2;
	winc2.cbClsExtra	= winc.cbWndExtra	= 0;
	winc2.hInstance		= hInstance;
	winc2.hIcon		= LoadIcon(NULL , IDI_APPLICATION);
	winc2.hCursor		= LoadCursor(NULL , IDC_ARROW);
	winc2.hbrBackground	= (HBRUSH)GetStockObject(WHITE_BRUSH);
	winc2.lpszMenuName	= NULL;
	winc2.lpszClassName	= TEXT("WND2");

	if (!RegisterClass(&winc)) return 0;
    if(!RegisterClass(&winc2)) return 0;

	hwnd = CreateWindow(
			TEXT("KITTY") , TEXT("Kitty on your lap") ,
			WS_OVERLAPPEDWINDOW | WS_VISIBLE ,
			100 , 100 , 300 , 200 , NULL , NULL ,
			hInstance , NULL
	);

    hwnd2 = CreateWindow(
            TEXT("WND2"), TEXT("2nd wnd"),
            WS_OVERLAPPEDWINDOW | WS_VISIBLE,
            200, 200, 300, 200, NULL, NULL,
            hInstance, NULL
    );

    MessageBox(NULL, TEXT("HWND1"), (LPCWSTR)hwnd, MB_ICONINFORMATION);

    while(TRUE){

        if(GetMessage(&msg1, hwnd, 0, 0) == 0){
            MessageBox(hwnd, TEXT("GOOD BYE"), TEXT("END"), MB_ICONINFORMATION);
            break;
        }
        GetMessage(&msg2, hwnd2, 0, 0);
        if(DispatchMessage(&msg2) == O_WM_LBUTTONUP){
            msg1.message = O_WM_LBUTTONUP;
        }
        DispatchMessage(&msg1);

    }

    return 0;
}