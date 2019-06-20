#ifndef __BOWSER__BROWSER__STATUSBAR__STATUS__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__STATUS__GUARD__

#include "../../decoration.hh"

#include "command.hh"
#include "text.hh"
#include "url.hh"
#include "position.hh"
#include "backforward.hh"
#include "tabindex.hh"
#include "progress.hh"

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
          m_stack(),
          m_command(*this),
          m_text(*this),
          m_url(*this),
          m_position(*this),
          m_backforward(*this),
          m_tabindex(*this),
          m_progress(*this)
    {
        QWidget::setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Fixed);
        m_layout.setContentsMargins(0, 0, 0, 0);
        m_layout.setSpacing(5);
        m_layout.addLayout(&m_stack);
        m_stack.setContentsMargins(0, 0, 0, 0);
        m_stack.addWidget(&m_command);
        m_stack.addWidget(&m_text);
        m_layout.addWidget(&m_url);
        m_layout.addWidget(&m_position);
        m_layout.addWidget(&m_backforward);
        m_layout.addWidget(&m_tabindex);
        m_layout.addWidget(&m_progress);
    }

    void resize();
    void draw();

private:
    QWidget& m_parent;

    QHBoxLayout m_layout;
    QStackedLayout m_stack;

    command_t m_command;
    text_t m_text;
    url_t m_url;
    position_t m_position;
    backforward_t m_backforward;
    tabindex_t m_tabindex;
    progress_t m_progress;

}* status_ptr_t;

#endif//__BOWSER__BROWSER__STATUSBAR__STATUS__GUARD__
