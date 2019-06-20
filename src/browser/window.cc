#include "window.hh"

#include <QResizeEvent>

void
window_t::resizeEvent(QResizeEvent* event)
{
    QWidget::resizeEvent(event);
    m_current_tab->resize();
    m_statusbar->resize();
}

void
window_t::on_url_send()
{
}

void
window_t::on_toggle_released()
{

}

void
window_t::on_gen_released()
{

}

void
window_t::on_selection_changed()
{

}

void
window_t::on_back()
{

}

void
window_t::on_forward()
{

}
