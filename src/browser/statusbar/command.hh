#ifndef __BOWSER__BROWSER__STATUSBAR__COMMAND__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__COMMAND__GUARD__

#include <QWidget>


class command_t : public QWidget
{
    Q_OBJECT

public:
    command_t(QWidget& parent)
        : QWidget(&parent),
          m_parent(parent)
    {}

private:
    QWidget& m_parent;

};

#endif//__BOWSER__BROWSER__STATUSBAR__COMMAND__GUARD__
