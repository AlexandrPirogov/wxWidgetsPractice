#include "Autorization.h"

wxBEGIN_EVENT_TABLE(Autorization, wxFrame)
	EVT_BUTTON(14000, OnOKBtnClicked)
wxEND_EVENT_TABLE()

Autorization::Autorization() : wxFrame(nullptr, wxID_ANY, "Авторизация", wxDefaultPosition, wxSize(220,150))
{
	ok = new wxButton(this, 14000, "OK", wxPoint(50, 50));
	phone = new wxTextCtrl(this, wxID_ANY, "", wxPoint(15, 15), wxSize(200, 20));
}

Autorization::~Autorization()
{
}

void Autorization::OnOKBtnClicked(wxCommandEvent& evt)
{
	code = 1;
	Destroy();
	evt.Skip();
}
