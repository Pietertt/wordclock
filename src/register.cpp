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

    uint8_t Register::getData() {
        return this->data;
    }

    void Register::setData(uint8_t data) {
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

    uint8_t Register::getCopyData() {
        return this->copyData;
    }

    void Register::setCopyData(uint8_t copyData) {
        this->copyData = copyData;
    }

    void Register::setCopyData(bool copyData, int position) {
        if (copyData) {
            this->copyData |= (0b1 << position);
        } else {
            this->copyData &= ~(0b1 << position);
        }
    }
}
