#include<windows.h>

int WINAPI WinMain(
            HINSTANCE hInstace,
            HINSTANCE hPrevInstance,
            PSTR lpCmdLine,
            int nCmdShow)
    {

    LPTSTR Line = GetCommandLine();
    CHAR own[50];
    int count = 1;
    while(1){
        if(Line[count] == TEXT('\"')){
            break;
        }

        own[count -1] = Line[count];
        count++;
    }

    MessageBox(NULL, own, TEXT("kitty"), MB_ICONINFORMATION);

    return 0;
}