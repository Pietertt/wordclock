#include "include/precomp.h"

namespace Wordclock {
    Wordclock::Wordclock() {
    DDRB |= 0B111111;
    DDRC |= 0B111111;

        while(true) {
            this->shiftOut(0, 1, 2, true, 0b11111111);
            _delay_ms(1000);
            
            this->shiftOut(0, 1, 2, true, 0b00000000);
            _delay_ms(1000);
        }
    }

    void Wordclock::shiftOut(int data, int latch, int clock, bool test, uint8_t value) {
        if (test) {
            PORTB &= ~(0b1 << latch);
        } else {
            PORTC &= ~(0b1 << latch);
        }

        for (int i = 0; i < 8; i++)  {
            if (value & (1 << (7 - i))) {
                if (test) {
                    PORTB |= (0b1 << data);
                } else {
                    PORTC |= (0b1 << data);
                }
            } else {
                if (test) {
                    PORTB &= ~(0b1 << data);
                } else {
                    PORTC &= ~(0b1 << data);
                }
            }

            if (test) {
                PORTB |= (0b1 << clock);
                PORTB &= ~(0b1 << clock);
            } else {
                PORTC |= (0b1 << clock);
                PORTC &= ~(0b1 << clock);
            }
        }

        if (test) {
            PORTB = (0b1 << latch) | PORTB;
        } else {
            PORTC = (0b1 << latch) | PORTC;
        }
    }
}