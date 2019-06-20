#ifndef __BOWSER__BROWSER__STATUSBAR__TEXTBASE__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__TEXTBASE__GUARD__

#include <QWidget>


class textbase_t : public QWidget
{
    Q_OBJECT

public:
    textbase_t(QWidget& parent)
        : QWidget(&parent),
          m_parent(parent)
    {}

private:
    QWidget& m_parent;

};

#endif//__BOWSER__BROWSER__STATUSBAR__TEXTBASE__GUARD__
