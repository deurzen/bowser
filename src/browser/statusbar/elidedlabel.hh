#ifndef __BOWSER__BROWSER__STATUSBAR__ELIDEDLABEL__GUARD__
#define __BOWSER__BROWSER__STATUSBAR__ELIDEDLABEL__GUARD__

#include <QFrame>


// https://doc.qt.io/qt-5/qtwidgets-widgets-elidedlabel-example.html
class elidedlabel_t : public QFrame
{
    Q_OBJECT
    Q_PROPERTY(QString text READ text WRITE setText)
    Q_PROPERTY(bool isElided READ isElided)

public:
    explicit elidedlabel_t(QWidget& parent, const QString& text = "")
        : QFrame(&parent),
          m_content(text),
          m_elided(false)
    {
        setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    }

    void setText(const QString&);

    inline const QString& text() const { return m_content; }
    inline bool isElided() const { return m_elided; }

protected:
    void paintEvent(QPaintEvent*) override;

signals:
    void elisionChanged(bool);

private:
    QString m_content;
    bool m_elided;

};

#endif//__BOWSER__BROWSER__STATUSBAR__ELIDEDLABEL__GUARD__
