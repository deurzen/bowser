#ifndef __BOWSER__BROWSER__STATUSBAR__PROGRESS__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__PROGRESS__GUARD__

#include <QProgressBar>


class progress_t : public QProgressBar
{
    Q_OBJECT

public:
    progress_t(QWidget& parent)
        : QProgressBar(&parent),
          m_parent(parent),
          m_enabled(false),
          m_value(0)
    {
        QProgressBar::setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        QProgressBar::setTextVisible(false);
        QProgressBar::hide();
    }

    void on_tab_change();

protected slots:
    void on_load();
    void on_progress(int);

private:
    QWidget& m_parent;

    bool m_enabled;
    int m_value;

};

#endif//__BOWSER__BROWSER__STATUSBAR__PROGRESS__GUARD__
