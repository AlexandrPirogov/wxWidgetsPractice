#pragma once

#include "wx/wx.h"

class ticketsSeatsPanel : public wxPanel
{
public:
	ticketsSeatsPanel(wxWindow* parent);
	~ticketsSeatsPanel();

	void Reset();
private:
	wxButton** seats = nullptr;
	int h = 2;
	int w = 10;
	void InitSeats();
	void OnSeatsButtonClicked(wxCommandEvent& evt);
};

