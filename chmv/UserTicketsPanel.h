#pragma once

#include "wx/wx.h"
#include <wx/listctrl.h>
#include "StaticTicketsContainer.h"
#include "Ticket.h"

class UserTicketsPanel : public wxPanel
{
public:
	UserTicketsPanel(wxWindow* parent);
	~UserTicketsPanel();
private:
	wxButton* refresh = nullptr;
	wxButton* remove = nullptr;

	wxListView* history = nullptr;

	void OnRefreshBtnClicked(wxCommandEvent& evt);
	void OnDeleteSelectedBtnClicked(wxCommandEvent& evt);
	wxDECLARE_EVENT_TABLE();
};

