#pragma once

#include "jcwb.h"

class ItemData {
	std::string menuname;  // use for keeping track of the 'internal menu name'
	void *data;            // use for keeping track of 'this'
public:
	ItemData(const char *menuname, void *data) {
		this->menuname = menuname;
		this->data = data;
	}
	void*       GetData()     const { return(data); }
	const char* GetMenuName() const { return(menuname.c_str()); }
};

static Fl_Input * inputURL;
static Fl_Box * statusbar;

class MainWindow
{
public:
	int Show();
	void AddItem(const char *realname,const char *menuname,
		const char *shortcut,
		int flags = 0);
private:	
	Fl_Menu_Bar * menubar;
	
	Fl_Help_View * _content;

	Fl_Callback *enter_cb; 
	void *enter_data;

	void SetEnterCallback(Fl_Callback *cb, void *data) {
		enter_cb = cb;
		enter_data = data;
	}
};