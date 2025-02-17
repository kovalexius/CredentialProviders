// CredentialManager.cpp : Implementation of WinMain


#include "resource.h"
#include "CredentialManager.h"
#include "MainDialog.h"

using namespace ATL;

CAppModule _AtlModule;

BEGIN_OBJECT_MAP(ObjectMap)
END_OBJECT_MAP()

extern "C" int WINAPI _tWinMain(HINSTANCE hInstance, HINSTANCE /*hPrevInstance*/,
								LPTSTR /*lpCmdLine*/, int nShowCmd)
{
	CMessageLoop theLoop;

	HRESULT hRes = ::CoInitialize(NULL);

	hRes = _AtlModule.Init(ObjectMap, hInstance);
	ATLASSERT(SUCCEEDED(hRes));

	_AtlModule.AddMessageLoop(&theLoop);

	CMainDialog dlgMain;

	if(dlgMain.Create(NULL) == NULL)
	{
		ATLTRACE(_T("Main dialog creation failed!\n"));
		return 0;
	}

	dlgMain.ShowWindow(nShowCmd);

	int nRet = theLoop.Run(); 

	_AtlModule.RemoveMessageLoop();

	_AtlModule.Term();

	::CoUninitialize();

	return nRet;
}
