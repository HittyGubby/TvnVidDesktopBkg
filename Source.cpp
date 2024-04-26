#include <windows.h>
#include <stdio.h>

BOOL CALLBACK EnumWindowsProc(_In_ HWND hwnd, _In_ LPARAM Lparam)
{
	HWND hDefView = FindWindowEx(hwnd, 0, L"SHELLDLL_DefView", 0);
	if (hDefView != 0) {
		//find next class name workerw and hide
		HWND hWorkerw = FindWindowEx(0, hwnd, L"WorkerW", 0);
		ShowWindow(hWorkerw, SW_HIDE);

		return FALSE;
	}
	return TRUE;
}

int main(int argc, char* argv[])
{
	{
		HWND hProgman = FindWindow(L"Progman", 0);				// find pm	
		SendMessageTimeout(hProgman, 0x52C, 0, 0, 0, 100, 0);	// send msg
		HWND hTvn = FindWindow(L"TvnWindowClass", 0);				// find tvn window
		SetParent(hTvn, hProgman);							// set as subwindow
		EnumWindows(EnumWindowsProc, 0);						// find second workerw and hide
	}

	return 0;
}