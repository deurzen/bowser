#ifndef __BOWSER__BROWSER__STATUSBAR__TEXTBASE__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__TEXTBASE__GUARD__

#include <QWidget>
#include <QLabel>

#include "elidedlabel.hh"

class textbase_t : public QLabel
{
    Q_OBJECT

public:
    textbase_t(QWidget& parent)
        : QLabel(&parent),
          m_parent(parent)
    {
        QLabel::setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Minimum);
    }

private:
    QWidget& m_parent;

};

#endif//__BOWSER__BROWSER__STATUSBAR__TEXTBASE__GUARD__
