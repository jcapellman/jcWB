#include <FL/Fl.H>
#include <FL/Fl_Window.H>

#pragma comment(lib, "fltk.lib")

using namespace std;

int main()
{
	Fl_Window win(800, 600, "lwwb");
	
	win.begin();
	
	win.end();
	
	win.show();

	return Fl::run();
}