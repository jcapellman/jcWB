#include "NavBarButton.h"

NavBarButton::NavBarButton(const char * tooltip, const char * icon, bool enabled, int x, int y, int width, int height)
{
	m_btn = new Fl_Button(x, y, width, height, icon);
	m_btn->tooltip(tooltip);

	if (!enabled)
	{
		m_btn->deactivate();
	}
}
