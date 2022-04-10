#include "TicketBuilderPanel.h"
#include "BuyTicketPanel.h"

wxBEGIN_EVENT_TABLE(TicketBuilderPanel, wxPanel)
	EVT_BUTTON(12050, OnFindSeatsBtnClicked)
	EVT_BUTTON(12060, OnBuySeatsBtnClicked)
	EVT_RADIOBOX(12000, OnRadioBoxClicked)
wxEND_EVENT_TABLE()

TicketBuilderPanel::TicketBuilderPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	this->parent = parent;
	Init();
	SetBackgroundColour(wxColor(230, 197, 235));
}

TicketBuilderPanel::~TicketBuilderPanel()
{
}

void TicketBuilderPanel::Init()
{
	wxArrayString choices;
	choices.Add("ЖД");
	choices.Add("Авиа");
	choices.Add("По морям");

	ticketType = new wxRadioBox(this, 12000, "Тип билета", wxPoint(15,15), wxSize(100,100), choices, 3, wxRA_VERTICAL);
	ticketType->SetBackgroundColour(wxColor(244, 244, 244));
	fromCity = new wxComboBox(this, wxID_ANY, "Выберите точку отправки", wxPoint(175, 15), wxSize(200, 150));
	toCity = new wxComboBox(this, wxID_ANY, "Выберите точку прибытия", wxPoint(400, 15), wxSize(200, 150));

	date = new wxCalendarCtrl(this, wxID_ANY, wxDefaultDateTime, wxPoint(650,15));

	findSeats = new wxButton(this, 12050, "Найти места", wxPoint(900, 15), wxSize(100, 75));
	buySeats = new wxButton(this, 12060, "Забронировать места", wxPoint(900, 100), wxSize(100, 75));
}

void TicketBuilderPanel::OnFindSeatsBtnClicked(wxCommandEvent& evt)
{

	BuyTicketPanel* panel_parent = (BuyTicketPanel*)parent->GetParent();
	panel_parent->ShowSeats();
	buySeats->Enable();
	evt.Skip();
}
void TicketBuilderPanel::OnBuySeatsBtnClicked(wxCommandEvent& evt)
{
	Ticket* t = new Ticket();
	t->date =  std::string(date->GetDate().Format().mb_str());
	t->from = fromCity->GetValue();
	t->to = toCity->GetValue();
	t->type = ticketType->GetString(ticketType->GetSelection());
	StaticTicketsContainer::tickets.push_back(*t);
	BuyTicketPanel* panel_parent = (BuyTicketPanel*)parent->GetParent();
	panel_parent->Reset();
	buySeats->Disable();
	evt.Skip();
}

void TicketBuilderPanel::OnRadioBoxClicked(wxCommandEvent& evt)
{
	wxArrayString from;
	wxArrayString to;
	fromCity->Clear();
	toCity->Clear();
	if (ticketType->GetString(ticketType->GetSelection()) == "ЖД")
	{
		from.Add("Moscow");
		from.Add("Piter");
		from.Add("Samara");
		from.Add("Penza");
		from.Add("Ekb");
		to.Add("Moscow");
		to.Add("Piter");
		to.Add("Samara");
		to.Add("Penza");
		to.Add("Ekb");
	}
	else if (ticketType->GetString(ticketType->GetSelection()) == "Авиа")
	{

		from.Add("Moscow");
		from.Add("Piter");
		from.Add("Samara");
		to.Add("Moscow");
		to.Add("Piter");
		to.Add("Samara");
	}
	else {
		from.Add("Moscow");
		from.Add("Samara");
		to.Add("Moscow");
		to.Add("Samara");
	}
	fromCity->Append(from);
	toCity->Append(to);
	evt.Skip();
}
