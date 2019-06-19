#ifndef __BOWSER__BROWSER__TAB__GUARD__
#define __BOWSER__BROWSER__TAB__GUARD__

#include "../decoration.hh"

#include <QtCore/QUrl>
#include <QWebEngineView>
#include <QWidget>


typedef class tab_t : public QWidget
{
    Q_OBJECT

public:
    tab_t(QWidget& parent)
        : m_view(&parent)
    {
        m_view.move(0, TAB_HEIGHT);
        m_view.resize(parent.size().width(), parent.size().height() - TAB_HEIGHT - STATUSBAR_HEIGHT);
        m_view.setUrl(QUrl("https://deurzen.net"));
    }

    virtual ~tab_t() {}

    inline void show() { m_view.show(); }
    inline void hide() { m_view.hide(); }

private:
    QWebEngineView m_view;

}* tab_ptr_t;

#endif//__BOWSER__BROWSER__TAB__GUARD__
