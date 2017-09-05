#include "lwwb.h"

int main()
{
	Fl_Window win(800, 600, "lwwb");
	
	win.begin();

	Fl_Input * inputURL = new Fl_Input(5, 5, 790, 30);

	Fl_Multi_Browser browserContent(5, 45, 790, 550);

	win.end();
	
	win.show();

	return Fl::run();
}