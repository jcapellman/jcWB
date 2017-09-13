#pragma once

#include "jcwb.h"

class NavBarButton
{
	public:
		NavBarButton(const char * tooltip, const char * icon, bool enabled, int x, int y, int width, int height);
	private:
		Fl_Button * m_btn;
};