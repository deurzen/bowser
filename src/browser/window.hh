#ifndef __BOWSER__BROWSER__WINDOW__GUARD__
#define __BOWSER__BROWSER__WINDOW__GUARD__

#include "../common.hh"

#include "tabbar/tab.hh"
#include "statusbar/status.hh"

#include <QWidget>

#include <vector>


typedef class window_t : public QWidget
{
    Q_OBJECT

public:
    window_t()
        : m_statusbar(new status_t(*this))
    {
        QWidget::resize(800, 600);
        QWidget::setWindowTitle(BROWSER_NAME.c_str());

        m_statusbar->resize();

        m_tabs.push_back((m_current_tab = new tab_t{*this}));
        show();
    }

    virtual ~window_t()
    {
        for (auto& tab : m_tabs)
            delete tab;
    }

protected:
    void resizeEvent(QResizeEvent*) override;

private slots:
    void on_url_send();
    void on_toggle_released();
    void on_gen_released();
    void on_selection_changed();
    void on_back();
    void on_forward();

private:
    tab_ptr_t m_current_tab;
    ::std::vector<tab_ptr_t> m_tabs;
    status_ptr_t m_statusbar;

}* window_ptr_t;

#endif//__BOWSER__BROWSER__WINDOW__GUARD__
