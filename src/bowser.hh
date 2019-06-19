#ifndef __BOWSER__BOWSER__GUARD__
#define __BOWSER__BOWSER__GUARD__

#include "common.hh"
#include "parse.hh"

#include "browser/window.hh"

#include <QApplication>

#include <memory>
#include <string>
#include <vector>


class bowser_t
{
public:
    bowser_t(int argc, char** argv)
        : m_parser(argc, argv)
    {
        m_parser.parse();
        ::std::tie(m_argc, m_args) = m_parser.getargs();
        m_app = new QApplication(m_argc, m_args.data());
        m_instances.push_back(new window_t());
    }

    void setup();
    void run();

    static ::std::unique_ptr<bowser_t> init(int, char**);

private:
    QApplication* m_app;
    parser_t m_parser;

    int m_argc;
    ::std::vector<char*> m_args;

    ::std::vector<window_ptr_t> m_instances;

};

#endif//__BOWSER__BOWSER__GUARD__
