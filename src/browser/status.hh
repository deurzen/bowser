#ifndef __BOWSER__BROWSER__STATUS__GUARD__
#define __BOWSER__BROWSER__STATUS__GUARD__

#include "../decoration.hh"

#include <QLineEdit>


typedef class status_t : public QLineEdit
{
    Q_OBJECT

public:
    status_t(QWidget& parent)
        : QLineEdit(&parent),
          m_parent(parent)
    {
        QLineEdit::move(0, parent.size().height() - TAB_HEIGHT);
        resize();
    }

    void resize();

private:
    QWidget& m_parent;

}* status_ptr_t;

#endif//__BOWSER__BROWSER__STATUS__GUARD__
