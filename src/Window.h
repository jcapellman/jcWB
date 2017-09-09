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

class Window
{
public:
	int Show();
	void AddItem(const char *realname,const char *menuname,
		const char *shortcut,
		int flags = 0);
private:
	Fl_Menu_Bar * menubar;
};