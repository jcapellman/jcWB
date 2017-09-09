#include "Window.h"

void Window::AddItem(const char *realname, const char *menuname, const char *shortcut, int flags) {
	ItemData *id = new ItemData(realname, static_cast<void*>(this));
	menubar->add(menuname, shortcut, nullptr, static_cast<void*>(id), flags);
}

int Window::Show()
{
	Fl_Window win(800, 600, APP_NAME);

	win.begin();
	
	menubar = new Fl_Menu_Bar(0, 0, win.w(), 30);

	AddItem("File", "File", "File");
	AddItem("Edit", "Edit", "Edit");
	AddItem("View", "View", "View");
	AddItem("Go", "Go", "Go");
	AddItem("Window", "Window", "Window");
	AddItem("Help", "Help", "Help");

	Fl_Input * inputURL = new Fl_Input(5, 70, win.w() - 10, 30);

	Fl_Multi_Browser browserContent(5, 110, win.w() - 10, 550);

	Fl_Box box(win.w() - 55, 35, 64, 30);
	Fl_PNG_Image  png("icon.png");	
	box.image(png);
	
	Fl_Button* btnBack = new Fl_Button(5, 35, 65, 30, "@<");
	btnBack->tooltip("Back");

	Fl_Button* btnForward = new Fl_Button(75, 35, 65, 30, "@>");
	btnForward->tooltip("Forward");

	Fl_Button* btnRefresh = new Fl_Button(145, 35, 65, 30, "@reload");
	btnRefresh->tooltip("Refresh");

	Fl_Button* btnStop = new Fl_Button(215, 35, 65, 30, "@square");
	btnStop->tooltip("Stop");

	win.end();

	win.show();

	return Fl::run();
}
