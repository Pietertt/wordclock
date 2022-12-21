#include "../include/precomp.h"

extern "C" void __cxa_pure_virtual() { while (1); }

void* operator new(size_t objsize) {
    return malloc(objsize);
}

void operator delete(void* obj) {
    free(obj);
}

int main () {
    Wordclock::Wordclock* clock = new Wordclock::Wordclock();
    clock->setup();
    clock->test();

    char string[50] = __TIME__;

    char* token = strtok(string, ":");
    clock->setHour(atoi(token) + 1);
    token = strtok(NULL, ":");
    clock->setMinutes(atoi(token));
    token = strtok(NULL, ":");
    clock->setSeconds(atoi(token));

    int hour = clock->getHour();
    int minutes = clock->getMinutes();

    clock->allOff();
    clock->decide_time();
    clock->commit();

    while (true) {
        if (minutes != clock->getMinutes() || hour != clock->getHour()) {
            clock->allOff();
            clock->decide_time();
            clock->commit();
            hour = clock->getHour();
            minutes = clock->getMinutes();
        }

        int randomNumber = rand() % ((500 + 1) - 0) + 0;
        int counter = 0;

        if (randomNumber == 1) {
            for (int i = 0; i < 100; i++) {
                clock->random();
                clock->commit();

                if (counter == 10) {
                    clock->tick();
                    counter = 0;
                }

                _delay_ms(100);
                counter++;
            }

            clock->allOff();
            clock->decide_time();
            clock->commit();
        }

        clock->tick();
        _delay_ms(1000);
    }

    return 0;
}
