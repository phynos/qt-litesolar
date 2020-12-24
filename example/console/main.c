#include <windows.h>
#include <stdio.h>

//int HWND_BROADCAST = 0xffff;

int main(void) {
	HWND hWnd = FindWindow( NULL , "光伏监控系统" );	
	if(hWnd == NULL){
		printf("find nothing.\r\n");
	} else {
		printf("find.\r\n");
		int WM_SHOWME = RegisterWindowMessage("WM_SHOWME");
		PostMessage(HWND_BROADCAST,WM_SHOWME,0,0);
	}
	system("pause");
}