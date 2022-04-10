#pragma once

#include "Autorization.h"

#include "wx/wx.h"
#include "cNotebook.h"

class Main : public wxFrame
{
public:
	Main();
	~Main();
private:
	cNotebook* notebook = nullptr;
};

