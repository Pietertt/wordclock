#include "include/precomp.h"

namespace Wordclock {
    SingleRegister::SingleRegister(int clock, int latch, int data, volatile uint8_t* reg) {
        this->setClockPin(clock);
        this->setLatchPin(latch);
        this->setDataPin(data);
        this->setRegister(reg);
    }

    SingleRegister::SingleRegister() : Register() {

    }

    void SingleRegister::setRegister(volatile byte* reg) {
        this->reg = reg;
    }

    volatile byte* SingleRegister::getRegister() {
        return this->reg;
    }

    void SingleRegister::shiftOut() {
        *this->getRegister() &= ~(0b1 << this->getLatchPin());

        for (int i = 0; i < 8; i++)  {
            *this->getRegister() ^= (-(!!(this->getData() & (1 << (7 - i)))) ^ *this->getRegister()) & (1 << this->getDataPin());
            *this->getRegister() |= (0b1 << this->getClockPin());
            *this->getRegister() &= ~(0b1 << this->getClockPin());
        }

        *this->getRegister() |= (0b1 << this->getLatchPin());
    }
}
