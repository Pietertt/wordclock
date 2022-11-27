#include "include/precomp.h"

extern "C" void __cxa_pure_virtual() { while (1); }

void* operator new(size_t objsize) {
    return malloc(objsize);
}

void operator delete(void* obj) {
    free(obj);
}

int main () {
    Wordclock::Time* time = new Wordclock::Time();
    time->setSeconds(0);
    time->setMinutes(28);
    time->setHour(22);

    Wordclock::Wordclock* clock = new Wordclock::Wordclock();
    clock->setup();
    clock->test();

    int hour = time->getHour();
    int minutes = time->getMinutes();

    clock->allOff();
    clock->decide_time(time);
    clock->commit();

    while (true) {
        
        if (minutes != time->getMinutes() || hour != time->getHour()) {
            clock->allOff();
            clock->decide_time(time);
            clock->commit();
            hour = time->getHour();
            minutes = time->getMinutes();
        }

        _delay_ms(1000);
        time->tick();
    }

    return 0;
}