#include "include/precomp.h"

namespace Wordclock {

    Time::Time() {

    }

    int Time::getMinutes() {
        return this->minutes;
    }

    int Time::getSeconds() {
        return this->seconds;
    }

    void Time::setSeconds(int seconds) {
        this->seconds = seconds;
    }

    void Time::setMinutes(int minutes) {
        this->minutes = minutes;
    }

    int Time::getHour() {
        return this->hour;
    }

    void Time::setHour(int hour) {
        this->hour = hour;
    }

    void Time::tick() {
        // this->counter += 10;

        // if (this->counter >= 1000) {
            this->setSeconds(this->getSeconds() + 1);
            // this->counter = 0;
        // }

        if (this->getHour() == 24) {
            this->setHour(0);
        }

        if (this->getMinutes() == 60) {
            this->setHour(this->getHour() + 1);
            this->setMinutes(0);
        }

        if (this->getSeconds() == 60) {
            this->setMinutes(this->getMinutes() + 1);
            this->setSeconds(0);
        }
    }
}
