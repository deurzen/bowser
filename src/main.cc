#include "bowser.hh"


int
main(int argc, char **argv)
{
    auto bowser = bowser_t::init(argc, argv);

    bowser->setup();
    bowser->run();

    return 0;
}
