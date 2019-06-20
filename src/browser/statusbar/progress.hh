#ifndef __BOWSER__BROWSER__STATUSBAR__PROGRESS__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__PROGRESS__GUARD__

#include <QWidget>


class progress_t : public QWidget
{
    Q_OBJECT

public:
    progress_t(QWidget& parent)
        : QWidget(&parent),
          m_parent(parent)
    {}

private:
    QWidget& m_parent;

};

#endif//__BOWSER__BROWSER__STATUSBAR__PROGRESS__GUARD__
