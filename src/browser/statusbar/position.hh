#ifndef __BOWSER__BROWSER__STATUSBAR__POSITION__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__POSITION__GUARD__

#include <QWidget>


class position_t : public QWidget
{
    Q_OBJECT

public:
    position_t(QWidget& parent)
        : QWidget(&parent),
          m_parent(parent)
    {}

private:
    QWidget& m_parent;

};

#endif//__BOWSER__BROWSER__STATUSBAR__POSITION__GUARD__
