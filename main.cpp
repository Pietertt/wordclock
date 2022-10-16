#include "include/precomp.h"

int main (void) {

    Wordclock::Time* time = new Wordclock::Time();

    Wordclock::Wordclock* clock = new Wordclock::Wordclock();
    clock->setup();

    //int a = time->getMinutes();

    while (true) {
        clock->decide_time(time);
        time->tick();
        _delay_ms(1000);
    }

    return 0;
}