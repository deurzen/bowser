#include "url.hh"

#include "../../util.hh"


void
url_t::update()
{
    if (!m_hover.isEmpty()) {
        ;// TODO settext
        m_type = urltype_t::hover;
    } else if (!m_loaded.isEmpty()) {
        ;// TODO settext
        m_type = urltype_t::normal; // TODO which normal type? check header m_type (should be conditionally set to something else (http, https, ...))!
    } else {
        ;// TODO settext empty
        m_type = urltype_t::normal;
    }
}

void
url_t::change(QUrl url) // tab changed
{

}

void
url_t::on_load_status_changed() // add loadstatus
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

    m_type = urltype_t::normal;
    update();
}

void
url_t::on_set_hover(::std::string& link)
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
