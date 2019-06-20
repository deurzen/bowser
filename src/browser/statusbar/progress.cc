#include "progress.hh"


void
progress_t::on_tab_change()
{

}

void
progress_t::on_load()
{
    QProgressBar::setValue(0);
    QProgressBar::setVisible(m_enabled);
}

void
progress_t::on_progress(int value)
{
    QProgressBar::setValue(value);
    if (value == 100)
        QProgressBar::hide();
}
