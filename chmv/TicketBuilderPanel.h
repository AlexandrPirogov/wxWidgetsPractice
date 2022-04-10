#pragma once

#include "wx/wx.h"
#include "wx/calctrl.h"
#include <string>

#include "Ticket.h"
#include "StaticTicketsContainer.h"

class TicketBuilderPanel : public wxPanel
{
public:
	TicketBuilderPanel(wxWindow* parent);
	~TicketBuilderPanel();
	
private:

	wxWindow* parent = nullptr;

	wxRadioBox* ticketType = nullptr;
	
	wxComboBox* fromCity = nullptr;
	wxComboBox* toCity = nullptr;

	wxCalendarCtrl* date = nullptr;

	wxButton* findSeats = nullptr;
	wxButton* buySeats = nullptr;

	void Init();
	void OnFindSeatsBtnClicked(wxCommandEvent& evt);
	void OnBuySeatsBtnClicked(wxCommandEvent& evt);
	void OnRadioBoxClicked(wxCommandEvent& evt);

	wxDECLARE_EVENT_TABLE();
};

