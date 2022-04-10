#pragma once

#include "wx/notebook.h"
#include "wx/wx.h"

#include "BuyTicketPanel.h"
#include "UserTicketsPanel.h"


class cNotebook : public wxPanel
{
public:
	cNotebook(wxWindow* parent);
	~cNotebook();

private:
	wxNotebook *notebook = nullptr;

	BuyTicketPanel* buyTicket = nullptr;
	UserTicketsPanel* userTickets = nullptr;
};

