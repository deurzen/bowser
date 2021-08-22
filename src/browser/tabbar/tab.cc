#include "tab.hh"

#include <QString>


void
tab_t::resize()
{
    auto size = m_parent.size();
    if (size.height() > TAB_HEIGHT + STATUSBAR_HEIGHT)
        QWebEngineView::resize(size.width(),
            size.height() - TAB_HEIGHT - STATUSBAR_HEIGHT);
}

void
tab_t::open(const std::string&& url)
{
    open(QUrl(url.c_str()));
}

void
tab_t::open(QUrl url)
{
    if (!url.isValid())
        return;

    QWebEngineView::load(url);
}
