#ifndef __BOWSER__BROWSER__STATUSBAR__TEXT__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__TEXT__GUARD__

#include "textbase.hh"

#include <QWidget>


class text_t : public textbase_t
{
    Q_OBJECT

public:
    text_t(QWidget& parent)
        : textbase_t(parent),
          m_parent(parent),
          m_perm(""),
          m_temp("")
    {}

    void setText(const QString&, bool = false);

protected slots:
    void check_reset(const QString&);

private:
    QWidget& m_parent;
    QString m_perm;
    QString m_temp;

};

#endif//__BOWSER__BROWSER__STATUSBAR__TEXT__GUARD__
