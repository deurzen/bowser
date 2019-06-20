#ifndef __BOWSER__BROWSER__STATUSBAR__URL__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__URL__GUARD__

#include "textbase.hh"

#include <QWidget>
#include <QUrl>


enum class urltype_t { success, success_https, error, warn, hover, normal };

class url_t : public textbase_t
{
    Q_OBJECT

public:
    url_t(QWidget& parent)
        : textbase_t(parent),
          m_parent(parent),
          m_hover(""),
          m_loaded("https://deurzen.net"),
          m_type(urltype_t::normal),
          m_status(urltype_t::normal)
    {
          update();
    }

    void update();
    void on_tab_change(QUrl);

protected slots:
    void on_status_change();
    void on_set_loaded(QUrl);
    void on_set_hover(::std::string&);

private:
    QWidget& m_parent;

    QUrl m_hover;
    QUrl m_loaded;

    urltype_t m_type;
    urltype_t m_status;

};

#endif//__BOWSER__BROWSER__STATUSBAR__URL__GUARD__
