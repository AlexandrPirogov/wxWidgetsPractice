#pragma once

#include "wx/wx.h"
#include "wx/splitter.h"

#include "TicketBuilderPanel.h"
#include "ticketsSeatsPanel.h"

class BuyTicketPanel : public wxPanel
{
public:
	BuyTicketPanel(wxWindow* parent);
	void ShowSeats();
	void Reset();
	~BuyTicketPanel();

private:
	wxBoxSizer* sizer = nullptr;
	TicketBuilderPanel* ticketBuilderPanel = nullptr;
	ticketsSeatsPanel* SeatsPanel = nullptr;
	wxSplitterWindow* splitter = nullptr;
	wxPanel *filler = nullptr;
};

