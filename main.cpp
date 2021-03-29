#include "include/precomp.h"

int main (void) {

    Wordclock::Time* time = new Wordclock::Time();

    Wordclock::Wordclock* clock = new Wordclock::Wordclock();
    clock->setup();

    //int a = time->getMinutes();

    return 0;
}