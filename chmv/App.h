#pragma once
#include "Main.h"

#include "wx/wx.h"

class App : public wxApp
{

public:
	App();
	~App();

	virtual bool OnInit();
private:
	Main* main = nullptr;
};

