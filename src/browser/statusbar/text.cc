#include "text.hh"

void
text_t::setText(const QString& text, bool temp)
{
    (temp ? m_temp : m_perm) = text;
    if (!m_temp.isEmpty())
        textbase_t::setText(m_temp);
    else if (!m_perm.isEmpty())
        textbase_t::setText(m_perm);
    else
        textbase_t::setText("");
}

void
text_t::check_reset(const QString& text)
{
    if (!m_perm.compare(text))
        m_perm.clear();
}
