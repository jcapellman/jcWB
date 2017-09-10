#include "Window.h"

void MainWindow::AddItem(const char *realname, const char *menuname, const char *shortcut, int flags) {
	ItemData *id = new ItemData(realname, static_cast<void*>(this));
	menubar->add(menuname, shortcut, NULL, static_cast<void*>(id), flags);
}

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
	((std::string*)userp)->append((char*)contents, size * nmemb);
	return size * nmemb;
}

static void updateStatusBar(const char * arg1, const char * arg2 = NULL) {
	string fullString = string(arg1, strlen(arg1));

	if (arg2 != NULL) {
		fullString.assign(arg2, strlen(arg2));
	}

	statusbar->copy_label(fullString.c_str());
}

static string dtos(double value) {
	ostringstream strs;
	strs << value;
	return strs.str();
}

static void navigateURL(Fl_Widget  * widget, void*d) {
	CURL *curl;
	CURLcode res;
	curl = curl_easy_init();
	std::string readBuffer;

	updateStatusBar("Connecting to ", inputURL->value());

	curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
	curl_easy_setopt(curl, CURLOPT_URL, inputURL->value());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

	res = curl_easy_perform(curl);
	
	curl_easy_cleanup(curl);

	((Fl_Help_View*)d)->value(readBuffer.c_str());

	updateStatusBar(STATUS_BAR_MSG_DOCUMENT_DONE, NULL);
}

int MainWindow::Show()
{
	string title = APP_NAME + " - [Version " + APP_VERSION + "]";

	Fl_Window win(800, 600, title.c_str());
	
	win.begin();	
		menubar = new Fl_Menu_Bar(0, 0, win.w(), 30);

		AddItem("File", "File", "File");
		AddItem("Edit", "Edit", "Edit");
		AddItem("View", "View", "View");
		AddItem("Go", "Go", "Go");
		AddItem("Window", "Window", "Window");
		AddItem("Help", "Help", "Help");

		inputURL = new Fl_Input(5, 70, win.w() - 60, 30);
		_content = new Fl_Help_View(5, 110, win.w() - 10, win.h()-135);

		Fl_Button * btnGo = new Fl_Button(win.w() - 50, 70, 45, 30, "Go");
		btnGo->tooltip("Go");
		btnGo->callback(navigateURL, _content);

		Fl_Box box(win.w() - 55, 35, 64, 30);
		Fl_PNG_Image  png("icon.png");
		
		box.image(png);
	
		Fl_Button* btnBack = new Fl_Button(5, 35, 65, 30, "@<");
		btnBack->tooltip("Back");
		btnBack->deactivate();

		Fl_Button* btnForward = new Fl_Button(75, 35, 65, 30, "@>");
		btnForward->tooltip("Forward");
		btnForward->deactivate();

		Fl_Button* btnRefresh = new Fl_Button(145, 35, 65, 30, "@reload");
		btnRefresh->tooltip("Refresh");
		btnRefresh->deactivate();

		Fl_Button* btnStop = new Fl_Button(215, 35, 65, 30, "@square");
		btnStop->tooltip("Stop");
		btnStop->deactivate();

		statusbar = new Fl_Box(0, win.h() - 20, win.w(), 20);
		statusbar->box(FL_FLAT_BOX);
		statusbar->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
		
	win.end();

	win.resizable(_content);

	win.show();

	return Fl::run();
}
