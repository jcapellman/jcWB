#include "Window.h"
#include "NavBarButton.h"

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

}

static string dtos(double value) {
	ostringstream strs;
	strs << value;
	return strs.str();
}

static void navigateURL(Fl_Widget  * widget, void*d) {
	CURL *curl = curl_easy_init();
	string readBuffer;

	updateStatusBar("Connecting to ", inputURL->value());

	curl_easy_setopt(curl, CURLOPT_HTTPGET, 1);
	curl_easy_setopt(curl, CURLOPT_URL, inputURL->value());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

	CURLcode res = curl_easy_perform(curl);
	
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
	
		NavBarButton * btnBack = new NavBarButton("Back", "@<", false, 5, 35, 65, 30);
		NavBarButton * btnForward = new NavBarButton("Foward", "@>", false, 75, 35, 65, 30);
		NavBarButton * btnRefresh = new NavBarButton("Refresh", "@reload", false, 145, 35, 65, 30);
		NavBarButton * btnStop = new NavBarButton("Stop", "@square", false, 215, 35, 65, 30);

		statusBar = new StatusBar(win.w(), win.h());
		
	win.end();

	win.resizable(_content);

	win.show();

	return Fl::run();
}
