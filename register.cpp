#include "include/precomp.h"

namespace Wordclock {
    Register::Register(int clock, int latch, int data, volatile uint8_t* reg) {
        this->setClockPin(clock);
        this->setLatchPin(latch);
        this->setDataPin(data);
        this->setRegister(reg);
    }

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

    void Register::setRegister(volatile uint8_t* reg) {
        this->reg = reg;
    }

    volatile uint8_t* Register::getRegister() {
        return this->reg;
    }
}