#ifndef __BOWSER__BOWSER__GUARD__
#define __BOWSER__BOWSER__GUARD__

#include "common.hh"
#include "parse.hh"

#include <memory>
#include <string>
#include <vector>


class bowser_t
{
public:
    bowser_t(int argc, char** argv)
        : parser(argc, argv) {}

    void setup();
    void run();

    static ::std::unique_ptr<bowser_t> init(int, char**);

private:
    parser_t parser;

    int argc;
    ::std::vector<char*> args;

};

#endif//__BOWSER__BOWSER__GUARD__
