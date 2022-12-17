#include "../include/precomp.h"

namespace Wordclock {
    SingleRegister::SingleRegister(int clock, int latch, int data, volatile uint8_t* reg) {
        this->setClockPin(clock);
        this->setLatchPin(latch);
        this->setDataPin(data);
        this->setRegister(reg);
    }

    SingleRegister::SingleRegister() : Register() {

    }

    void SingleRegister::setRegister(volatile uint8_t* reg) {
        this->reg = reg;
    }

    volatile uint8_t* SingleRegister::getRegister() {
        return this->reg;
    }

    void SingleRegister::shiftOut() {
        // PORTC &= ~(0b1 << this->getLatchPin());

        // SPI.beginTransaction(SPISettings(16000000, MSBFIRST, SPI_MODE0));
        // SPI.transfer(this->getData());
        // SPI.endTransaction();

        // PORTC |= (0b1 << this->getLatchPin());

        *this->getRegister() &= ~(0b1 << this->getLatchPin());

        for (int i = 0; i < 8; i++)  {
             *this->getRegister() ^= (-(!!(this->getData() & (1 << (7 - i)))) ^ *this->getRegister()) & (1 << this->getDataPin());
             *this->getRegister() |= (0b1 << this->getClockPin());
             *this->getRegister() &= ~(0b1 << this->getClockPin());
         }

         *this->getRegister() |= (0b1 << this->getLatchPin());

    }
}
