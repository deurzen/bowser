#ifndef __BOWSER__BOWSER__GUARD__
#define __BOWSER__BOWSER__GUARD__

#include <memory>


class bowser_t
{
public:
    bowser_t() = default;

    void setup();
    void run();

    static ::std::unique_ptr<bowser_t> init();

};

#endif//__BOWSER__BOWSER__GUARD__
