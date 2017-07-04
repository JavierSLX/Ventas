#pragma once   //_____________________________________________ RangosDlg.h  
#include "resource.h"

class RangosDlg: public Win::Dialog
{
public:
	RangosDlg()
	{
	}
	~RangosDlg()
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
