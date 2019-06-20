#ifndef __BOWSER__BROWSER__STATUSBAR__BACKFORWARD__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__BACKFORWARD__GUARD__

#include "textbase.hh"


class backforward_t : public textbase_t
{
    Q_OBJECT

public:
    backforward_t(QWidget& parent)
        : textbase_t(parent),
          m_parent(parent)
    {
        textbase_t::setText("[<>]");
    }

private:
    QWidget& m_parent;

};

#endif//__BOWSER__BROWSER__STATUSBAR__BACKFORWARD__GUARD__
