#ifndef __BOWSER__BROWSER__STATUSBAR__BACKFORWARD__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__BACKFORWARD__GUARD__

#include <QWidget>


class backforward_t : public QWidget
{
    Q_OBJECT

public:
    backforward_t(QWidget& parent)
        : QWidget(&parent),
          m_parent(parent)
    {}

private:
    QWidget& m_parent;

};

#endif//__BOWSER__BROWSER__STATUSBAR__BACKFORWARD__GUARD__
