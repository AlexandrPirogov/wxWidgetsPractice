#include "cNotebook.h"

cNotebook::cNotebook(wxWindow* parent) : wxPanel(parent, wxID_ANY, wxDefaultPosition, wxSize(200,200))
{
	notebook = new wxNotebook(this, wxID_ANY, wxDefaultPosition);
	buyTicket = new BuyTicketPanel(notebook);
	userTickets = new UserTicketsPanel(notebook);

	notebook->AddPage(buyTicket, wxT("Бронь билетов"));
	notebook->AddPage(userTickets, wxT("Ваши билеты"));

	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(notebook, 1, wxEXPAND | wxALL, 5);
	this->SetSizerAndFit(sizer);

}

cNotebook::~cNotebook()
{
}
