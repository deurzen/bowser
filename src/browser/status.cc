#include "status.hh"


void
status_t::resize()
{
    auto size = m_parent.size();
    QLineEdit::resize(size.width(), STATUSBAR_HEIGHT);
}
