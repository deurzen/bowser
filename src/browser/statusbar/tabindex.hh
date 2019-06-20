#ifndef __BOWSER__BROWSER__STATUSBAR__TABINDEX__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__TABINDEX__GUARD__

#include <QWidget>


class tabindex_t : public QWidget
{
    Q_OBJECT

public:
    tabindex_t(QWidget& parent)
        : QWidget(&parent),
          m_parent(parent)
    {}

private:
    QWidget& m_parent;

};

#endif//__BOWSER__BROWSER__STATUSBAR__TABINDEX__GUARD__
