#include "tab.hh"


void
tab_t::resize()
{
    auto size = m_parent.size();
    if (size.height() > TAB_HEIGHT + STATUSBAR_HEIGHT)
        QWebEngineView::resize(size.width(),
            size.height() - TAB_HEIGHT - STATUSBAR_HEIGHT);
}
