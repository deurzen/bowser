#ifndef __BOWSER__BROWSER__STATUSBAR__TAB__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__TAB__GUARD__

#include "../../decoration.hh"

#include <QUrl>
#include <QWebEngineView>
#include <QWidget>


typedef class tab_t : public QWebEngineView
{
    Q_OBJECT

public:
    tab_t(QWidget& parent)
        : QWebEngineView(&parent),
          m_parent(parent)
    {
        QWebEngineView::move(0, TAB_HEIGHT);
        resize();
    }

    virtual ~tab_t() {}

    void resize();

    void open(const std::string&&);
    void open(QUrl);

private:
    QWidget& m_parent;

}* tab_ptr_t;

#endif//__BOWSER__BROWSER__STATUSBAR__TAB__GUARD__
