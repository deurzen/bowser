#ifndef __BOWSER__BROWSER__STATUS__GUARD__
#define __BOWSER__BROWSER__STATUS__GUARD__

#include "../../decoration.hh"

#include <QLineEdit>
#include <QHBoxLayout>
#include <QStackedLayout>


typedef class status_t : public QWidget
{
    Q_OBJECT

public:
    status_t(QWidget& parent)
        : QWidget(&parent),
          m_parent(parent),
          m_layout(),
          m_stack()
    {
        QWidget::setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        m_layout.setContentsMargins(0, 0, 0, 0);
        m_layout.setSpacing(5);
        m_layout.addLayout(&m_stack);
        m_stack.setContentsMargins(0, 0, 0, 0);
    }

    void resize();

private:
    QWidget& m_parent;

    QHBoxLayout m_layout;
    QStackedLayout m_stack;

}* status_ptr_t;

#endif//__BOWSER__BROWSER__STATUS__GUARD__
