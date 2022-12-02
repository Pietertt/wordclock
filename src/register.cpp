#include "../include/precomp.h"

namespace Wordclock {

    void Register::setClockPin(int pin) {
        this->clockPin = pin;
    }
            
    void Register::setLatchPin(int pin) {
        this->latchPin = pin;
    }
    
    void Register::setDataPin(int pin) {
        this->dataPin = pin;
    }

    int Register::getClockPin() {
        return this->clockPin;
    }

    int Register::getLatchPin() {
        return this->latchPin;
    }
    
    int Register::getDataPin() {
        return this->dataPin;
    }

    byte Register::getData() {
        return this->data;
    }

    void Register::setData(byte data) {
        this->data = data;
    }

    void Register::setData(bool data, int position) {
        if (data) {
            this->data |= (0b1 << position);
        } else {
            this->data &= ~(0b1 << position);
        }
    }

    void Register::toggleData(int position) {
        this->data ^= 1UL << position;
    }
}