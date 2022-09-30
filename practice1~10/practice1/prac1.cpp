#include<windows.h>
#include<stdio.h>

int WINAPI WinMain(
		HINSTANCE hInstance ,
		HINSTANCE hPrevInstance ,
		LPSTR lpCmdLine ,
		int nCmdShow ) {

    UINT reflag = 0;
    LPTSTR lptStr = (LPTSTR)malloc(sizeof(WCHAR)*128);

    wsprintf(lptStr, TEXT("Instance handle : %d"),hInstance);

   reflag = MessageBox(NULL, lptStr, 
                        TEXT("Message Box"), MB_YESNO
                        );
    
    if(reflag == IDYES) MessageBox(NULL, TEXT("pressed yes"), TEXT("pattern yes"), MB_OK);
    else MessageBox(NULL, TEXT("pressed no"), TEXT("pattern no"), MB_OK);

    fprintf(stdout, "succeesed");

	return 0;
}