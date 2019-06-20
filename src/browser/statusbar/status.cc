#include "status.hh"


void
status_t::resize()
{
    auto size = m_parent.size();
    if (size.height() > TAB_HEIGHT) {
        QWidget::move(0, size.height() - TAB_HEIGHT);
        QWidget::resize(size.width(), STATUSBAR_HEIGHT);
    }
}
