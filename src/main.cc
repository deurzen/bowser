#include "bowser.hh"


int
main(int argc, char **argv)
{
    auto bowser = bowser_t::init();

    bowser->setup();
    bowser->run();

    return 0;
}
