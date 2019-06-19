#ifndef __BOWSER__BROWSER__WINDOW__GUARD__
#define __BOWSER__BROWSER__WINDOW__GUARD__

#include "../common.hh"

#include "tab.hh"
#include "status.hh"

#include <QWidget>

#include <vector>


typedef class window_t : public QWidget
{
    Q_OBJECT

public:
    window_t()
        : m_main()
    {
        m_main.resize(800, 600);
        m_main.setWindowTitle(BROWSER_NAME.c_str());

        m_tabs.push_back((m_current_tab = new tab_t{m_main}));
        show();
    }

    virtual ~window_t()
    {
        for (auto& tab : m_tabs)
            delete tab;
    }

    inline void show() { m_main.show(); }
    inline void hide() { m_main.hide(); }

private slots:
    void on_url_send();
    void on_toggle_released();
    void on_gen_released();
    void on_selection_changed();
    void on_back();
    void on_forward();

private:
    QWidget m_main;

    tab_ptr_t m_current_tab;
    ::std::vector<tab_ptr_t> m_tabs;
    status_t m_statusbar;

}* window_ptr_t;

#endif//__BOWSER__BROWSER__WINDOW__GUARD__
