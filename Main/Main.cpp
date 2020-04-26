#include "stdafx.h"

HINSTANCE g_hMainInstance;

extern "C" _declspec(dllexport) void EntryPoint()
{
	// Old Protect pointer
	DWORD MainOldProtect = 0;
	
	// Protect the code to be executed
	if(VirtualProtect(LPVOID(oMainEntryPoint),SIZE_T(oMainEndPoint),PAGE_EXECUTE_READWRITE,&MainOldProtect))
	{
		gConfig.Load();
		gCrack.Load();		
	}
	else
	{
		// Error message
		MessageBox(NULL,"Failed to start","Virtual Protect",MB_OK|MB_ICONERROR);
		PostQuitMessage(0);
	}
}

BOOL APIENTRY DllMain(HANDLE hHandle,DWORD dwReason,LPVOID lpReserved)
{
	// Not used parameter
	UNREFERENCED_PARAMETER(lpReserved);

	// Attach instance to global var
	if(dwReason == DLL_PROCESS_ATTACH)
	{
		g_hMainInstance = (HINSTANCE)hHandle;
	}

	return TRUE;
}