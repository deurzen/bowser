#ifndef __BOWSER__BROWSER__STATUSBAR__POSITION__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__POSITION__GUARD__

#include "textbase.hh"


class position_t : public textbase_t
{
    Q_OBJECT

public:
    position_t(QWidget& parent)
        : textbase_t(parent),
          m_parent(parent)
    {
        textbase_t::setText("[top]");
    }

private:
    QWidget& m_parent;

};

#endif//__BOWSER__BROWSER__STATUSBAR__POSITION__GUARD__
