#include "StatusBar.h"

void StatusBar::UpdateText(const char* message)
{
	m_statusbar->copy_label(message);
}

StatusBar::StatusBar(int windowWidth, int windowHeight)
{
	m_statusbar = new Fl_Box(0, windowHeight - 20, windowWidth, 20);
	m_statusbar->box(FL_FLAT_BOX);
	m_statusbar->align(FL_ALIGN_LEFT | FL_ALIGN_INSIDE);
}
