#include "ticketsSeatsPanel.h"

ticketsSeatsPanel::ticketsSeatsPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	InitSeats();
}

ticketsSeatsPanel::~ticketsSeatsPanel()
{
	delete[] seats;
}

void ticketsSeatsPanel::Reset()
{
	
	for (int x = 0; x < h; x++)
	{
		for (int y = 0; y < w; y++)
		{
				seats[y * h + x]->Destroy();
		}
	}
}

void ticketsSeatsPanel::InitSeats()
{

	seats = new wxButton*[h*w];
	wxGridSizer* grid = new wxGridSizer(h, w, 0, 0);
	for (int x = 0; x < h; x++)
	{
		for (int y = 0; y < w; y++)
		{
			seats[y * h + x] = new wxButton(this, 1000 + (y * h + x));
			wxString seats_num = wxString::Format(wxT("%i"), y * h + x);
			seats[y * h + x]->SetLabel("Место " + seats_num);
			if ((y * h + x) % 2 == 0)
				seats[y * h + x]->SetBackgroundColour(wxColor(124, 226, 230));
			else
				seats[y * h + x]->SetBackgroundColour(wxColor(125, 230, 164));
			grid->Add(seats[y * h + x], 1, wxEXPAND | wxALL);
			seats[y * h + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &ticketsSeatsPanel::OnSeatsButtonClicked, this);
		}
	}
	this->SetSizer(grid);
	grid->Layout();
}

void ticketsSeatsPanel::OnSeatsButtonClicked(wxCommandEvent& evt)
{
	wxButton* clicked_button = (wxButton*)evt.GetEventObject();

	clicked_button->SetBackgroundColour(wxColor(200, 100, 242));
	evt.Skip();
};