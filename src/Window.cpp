#include "Window.h"

void Window::AddItem(const char *realname, const char *menuname, const char *shortcut, int flags) {
	ItemData *id = new ItemData(realname, static_cast<void*>(this));
	menubar->add(menuname, shortcut, nullptr, static_cast<void*>(id), flags);
}

int Window::Show()
{
	Fl_Window win(800, 600, "lwwb");

	win.begin();
	
	menubar = new Fl_Menu_Bar(0, 0, win.w(), 30);

	AddItem("File", "File", "File");
	AddItem("Help", "Help", "Help");

	Fl_Input * inputURL = new Fl_Input(5, 35, win.w() - 10, 30);

	Fl_Multi_Browser browserContent(5, 75, win.w() - 10, 550);

	win.end();

	win.show();

	return Fl::run();
}
