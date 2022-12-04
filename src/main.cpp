#include "../include/precomp.h"

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
    time->setMinutes(21);
    time->setHour(20);

    Wordclock::Wordclock* clock = new Wordclock::Wordclock();
    clock->time = time;
    clock->setup();
    
    // clock->test();

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

        time->tick();
        clock->sleep(575);
    }

    return 0;
}
