#include "UserTicketsPanel.h"

wxBEGIN_EVENT_TABLE(UserTicketsPanel, wxPanel)
	EVT_BUTTON(13000, OnRefreshBtnClicked)
	EVT_BUTTON(13010, OnDeleteSelectedBtnClicked)
wxEND_EVENT_TABLE()

UserTicketsPanel::UserTicketsPanel(wxWindow* parent) : wxPanel(parent, wxID_ANY)
{
	wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);
	wxPanel* panel = new wxPanel(this, wxID_ANY);
	refresh = new wxButton(panel, 13000, "Обновить", wxPoint(15,15), wxSize(100,100));
	remove = new wxButton(panel, 13010, "Удалить", wxPoint(15, 115), wxSize(100, 100));
	history = new wxListView(panel, wxID_ANY, wxPoint(300,15), wxSize(500,700));
	history->AppendColumn("Тип билета");
	history->AppendColumn("Точка отправления");
	history->AppendColumn("Точка прибытия");
	history->AppendColumn("Дата");
	history->AppendColumn("Доп");

	SetBackgroundColour(wxColor(181, 218, 219));
	history->SetBackgroundColour(wxColor(35, 35, 35));
	history->SetTextColour(wxColor(255, 255, 255));
	history->SetColumnWidth(0, 100);
	history->SetColumnWidth(1, 100);
	history->SetColumnWidth(2, 100);
	history->SetColumnWidth(3, 100);
	sizer->Add(panel, 1, wxEXPAND | wxCENTER | wxRIGHT, 10);
	this->SetSizerAndFit(sizer);

	

}

UserTicketsPanel::~UserTicketsPanel()
{
}

void UserTicketsPanel::OnRefreshBtnClicked(wxCommandEvent& evt)
{
	history->DeleteAllItems();
	auto vec = StaticTicketsContainer::tickets;
	int k = 0;
	for (auto& item : vec)
	{
		history->InsertItem(k, item.type);
		history->SetItem(k, 1, item.from);
		history->SetItem(k, 2, item.to);
		history->SetItem(k, 3, item.date);
		k++;
	}
	evt.Skip();
}

void UserTicketsPanel::OnDeleteSelectedBtnClicked(wxCommandEvent& evt)
{
	int item_to_delete = history->GetSelectedItemCount();
	history->DeleteItem(item_to_delete-1);
	if (StaticTicketsContainer::tickets.size() == 1)
		StaticTicketsContainer::tickets.clear();
	else
	StaticTicketsContainer::tickets.erase(StaticTicketsContainer::tickets.begin() + item_to_delete, 
		StaticTicketsContainer::tickets.begin() + item_to_delete + 1);
	evt.Skip();
}
