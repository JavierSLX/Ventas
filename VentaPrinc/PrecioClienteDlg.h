#pragma once   //_____________________________________________ PrecioClienteDlg.h  
#include "resource.h"

class PrecioClienteDlg: public Win::Dialog
{
public:
	PrecioClienteDlg()
	{
	}
	~PrecioClienteDlg()
	{
	}
private:
	//______ Wintempla GUI manager section begin: DO NOT EDIT AFTER THIS LINE
	void Window_Open(Win::Event& e);
	void GetDialogTemplate(DLGTEMPLATE& dlgTemplate)
	{
		dlgTemplate.style = DS_CENTER | DS_MODALFRAME | WS_POPUP | WS_VISIBLE | WS_CAPTION | WS_SYSMENU;

	}
};
