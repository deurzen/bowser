#ifndef __BOWSER__BROWSER__STATUSBAR__TABINDEX__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__TABINDEX__GUARD__

#include "textbase.hh"


class tabindex_t : public textbase_t
{
    Q_OBJECT

public:
    tabindex_t(QWidget& parent)
        : textbase_t(parent),
          m_parent(parent)
    {
        textbase_t::setText("[1/1]");
    }

private:
    QWidget& m_parent;

};

#endif//__BOWSER__BROWSER__STATUSBAR__TABINDEX__GUARD__
