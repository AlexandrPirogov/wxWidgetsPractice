#pragma once

#include "wx/wx.h"

class Autorization : public wxFrame
{
public:
	Autorization();
	~Autorization();
	int code = 0;
private:
	wxButton* ok = nullptr;
	wxTextCtrl* phone = nullptr;

	void OnOKBtnClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

