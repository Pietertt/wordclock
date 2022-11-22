#include "include/precomp.h"

extern "C" void __cxa_pure_virtual() { while (1); }

void* operator new(size_t objsize) {
    return malloc(objsize);
}

void operator delete(void* obj) {
    free(obj);
}

int main (void) {

    Wordclock::Time* time = new Wordclock::Time();

    Wordclock::Wordclock* clock = new Wordclock::Wordclock();
    clock->setup();
    clock->test();

    while (true) {
        clock->allOff();
        clock->decide_time(time);
        clock->commit();

        _delay_ms(1000);

        time->tick();
    }

    return 0;
}