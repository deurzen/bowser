#ifndef __BOWSER__BROWSER__STATUSBAR__URL__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__URL__GUARD__

#include <QWidget>
#include <QUrl>


enum class urltype_t { success, success_https, error, warn, hover, normal };

class url_t : public QWidget
{
    Q_OBJECT

public:
    url_t(QWidget& parent)
        : QWidget(&parent),
          m_parent(parent),
          m_hover(),
          m_loaded(),
          m_type(urltype_t::normal)
    {}

    void update();
    void change(QUrl); // tab changed

protected slots:
    void on_load_status_changed();
    void on_set_loaded(QUrl);
    void on_set_hover(::std::string&);

private:
    QWidget& m_parent;

    QUrl m_hover;
    QUrl m_loaded;
    urltype_t m_type;

};

#endif//__BOWSER__BROWSER__STATUSBAR__URL__GUARD__
