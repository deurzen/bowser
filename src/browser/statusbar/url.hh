#ifndef __BOWSER__BROWSER__STATUSBAR__URL__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__URL__GUARD__

#include <QWidget>


class url_t : public QWidget
{
    Q_OBJECT

public:
    url_t(QWidget& parent)
        : QWidget(&parent),
          m_parent(parent)
    {}

private:
    QWidget& m_parent;

};

#endif//__BOWSER__BROWSER__STATUSBAR__URL__GUARD__
