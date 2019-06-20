#include "elidedlabel.hh"

#include <QPainter>
#include <QTextLayout>


void
elidedlabel_t::setText(const QString& text)
{
    m_content = text;
    update();
}

void
elidedlabel_t::paintEvent(QPaintEvent* event)
{
    QFrame::paintEvent(event);

    QPainter painter(this);
    QFontMetrics metrics = painter.fontMetrics();

    bool has_elided = false;
    int linespacing = metrics.lineSpacing();
    int y = 0;

    QTextLayout textLayout(m_content, painter.font());
    textLayout.beginLayout();
    forever {
        QTextLine line = textLayout.createLine();

        if (!line.isValid())
            break;

        line.setLineWidth(width());
        int nextline_y = y + linespacing;

        if (height() >= nextline_y + linespacing) {
            line.draw(&painter, QPoint(0, y));
            y = nextline_y;
        } else {
            QString lastline = m_content.mid(line.textStart());
            QString lastline_elided = metrics.elidedText(lastline, Qt::ElideRight, width());
            painter.drawText(QPoint(0, y + metrics.ascent()), lastline_elided);
            line = textLayout.createLine();
            has_elided = line.isValid();
            break;
        }
    }
    textLayout.endLayout();
    if (has_elided != m_elided) {
        m_elided = has_elided;
        emit elisionChanged(has_elided);
    }
}
