#include "include/precomp.h"

namespace Wordclock {
    Register::Register(int clock, int latch, int data, volatile uint8_t* reg) {
        this->setClockPin(clock);
        this->setLatchPin(latch);
        this->setDataPin(data);
        this->setRegister(reg);

        this->setData(0b00000000);
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

    void Register::shiftOut(byte value) {
        *this->getRegister() &= ~(0b1 << this->getLatchPin());

        for (int i = 0; i < 8; i++)  {
            if (value & (1 << (7 - i))) {
                *this->getRegister() |= (0b1 << this->getDataPin());
            } else {
                *this->getRegister() &= ~(0b1 << this->getDataPin());
            }
            *this->getRegister() |= (0b1 << this->getClockPin());
            *this->getRegister() &= ~(0b1 << this->getClockPin());
        }

        *this->getRegister() |= (0b1 << this->getLatchPin());
    }

    void Register::doubleShiftOut(Register *a, byte value) {
        this->setData(0, a->getLatchPin());
        this->shiftOut(this->getData());

        for (int i = 0; i < 8; i++) {
            if (value & (1 << (7 - i))) {
                this->setData(1, a->getDataPin());
                this->shiftOut(this->getData());
            } else {
                this->setData(0, a->getDataPin());
                this->shiftOut(this->getData());
            }
            this->setData(1, a->getClockPin());
            this->shiftOut(this->getData());
            this->setData(0, a->getClockPin());
            this->shiftOut(this->getData());
        }

        this->setData(1, a->getLatchPin());
        this->shiftOut(this->getData());
    }

    void Register::increment() {
        this->data = this->data << 1;
    }

    void Register::doubleIncrement(Register *a) {
        a->setData(a->getData() << 1);
    }

    void Register::loop() {
        this->data = 0b00000001;

        for (int i = 0; i < 8; i++) {
            this->shiftOut(this->data);
            this->increment();
            _delay_ms(100);
        }

        this->setData(0b00000000);
        this->shiftOut(this->data);
    }

    void Register::doubleLoop(Register *reg) {
        reg->setData(0b00000001);

        for (int i = 0; i < 8; i++) {
            this->doubleShiftOut(reg, reg->getData());
            this->doubleIncrement(reg);
            _delay_ms(100);
        }

        this->doubleShiftOut(reg, reg->getData());
    }
}
