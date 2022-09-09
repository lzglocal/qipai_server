#include "Stdafx.h"
#include <afxdllx.h>

#include<time.h>
#include<stdlib.h>

//////////////////////////////////////////////////////////////////////////

static AFX_EXTENSION_MODULE GameServerDLL= {NULL,NULL};

//DLL ����������
extern "C" int APIENTRY DllMain(HINSTANCE hInstance, DWORD dwReason, LPVOID lpReserved)
{
  UNREFERENCED_PARAMETER(lpReserved);
  if(dwReason==DLL_PROCESS_ATTACH)
  {
	srand(time(0));
    if(!AfxInitExtensionModule(GameServerDLL, hInstance))
    {
      return 0;
    }
    new CDynLinkLibrary(GameServerDLL);
  }
  else if(dwReason==DLL_PROCESS_DETACH)
  {
    AfxTermExtensionModule(GameServerDLL);
  }
  return 1;
}

//////////////////////////////////////////////////////////////////////////
