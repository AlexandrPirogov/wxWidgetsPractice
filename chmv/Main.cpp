#include "Main.h"

Main::Main() : wxFrame(nullptr, wxID_ANY, "googogo")
{
	
	notebook = new cNotebook(this);
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	sizer->Add(notebook,1, wxEXPAND | wxALL, 5);
	this->SetSizerAndFit(sizer);
	Autorization* d = new Autorization();
	d->Show();
}

Main::~Main()
{

}