#include "url.hh"

#include "../../util.hh"


void
url_t::update()
{
    if (!m_hover.isEmpty()) {
        textbase_t::setText(m_hover.toString());
        m_type = urltype_t::hover;
    } else if (!m_loaded.isEmpty()) {
        textbase_t::setText(m_loaded.toString());
        m_type = m_status;
    } else {
        textbase_t::setText("");
        m_type = urltype_t::normal;
    }
}

void
url_t::on_tab_change(QUrl url) // tab changed
{

}

void
url_t::on_status_change() // add loadstatus
{

}

void
url_t::on_set_loaded(QUrl url)
{
    if (url.isEmpty())
        m_loaded.clear();
    else if (!url.isValid())
        m_loaded = "invalid";
    else
        m_loaded = safe_displaystring(url);

    m_status = urltype_t::normal;
    update();
}

void
url_t::on_set_hover(std::string& link)
{
    if (link.empty()) {
        m_hover.clear();
    } else {
        QUrl url = QUrl(link.c_str());
        if (url.isValid())
            m_hover = safe_displaystring(url);
        else
            m_hover = ("(invalid) " + link).c_str();
    }

    update();
}
