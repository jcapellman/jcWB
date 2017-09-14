#pragma once

#include "jcwb.h"

class StatusBar
{
public:
	StatusBar::StatusBar(int windowWidth, int windowHeight);
	void UpdateText(const char * message);
private:
	Fl_Box * m_statusbar;
};