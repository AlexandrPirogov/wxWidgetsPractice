#include "BuyTicketPanel.h"

BuyTicketPanel::BuyTicketPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	splitter = new wxSplitterWindow(this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 
		wxSP_BORDER | wxSP_LIVE_UPDATE);
	ticketBuilderPanel = new TicketBuilderPanel(splitter);
	
	filler = new wxPanel(splitter, wxID_ANY);
	sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(splitter, 1, wxEXPAND | wxALL, 5);
	splitter->SplitHorizontally(ticketBuilderPanel, filler);
	splitter->SetMinimumPaneSize(200);
	this->SetSizerAndFit(sizer);
}

void BuyTicketPanel::ShowSeats()
{
	if (SeatsPanel != nullptr)
		delete SeatsPanel;
	SeatsPanel = new ticketsSeatsPanel(splitter);
	if (filler != nullptr)
	{
		splitter->ReplaceWindow(filler, SeatsPanel);
		delete filler;
		filler = nullptr;
	}
	else
		splitter->ReplaceWindow(splitter->GetWindow2(), SeatsPanel);
	splitter->SplitHorizontally(ticketBuilderPanel, SeatsPanel);
	splitter->SetMinimumPaneSize(200);
	this->SetSizerAndFit(sizer);
	splitter->Refresh();

}

void BuyTicketPanel::Reset()
{
	SeatsPanel->Reset();
}

BuyTicketPanel::~BuyTicketPanel()
{
}
