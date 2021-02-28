#include "include/precomp.h"

namespace Wordclock {
    Wordclock::Wordclock() {
    DDRB |= 0B111111;

        while(1) {
            this->shiftOut(0b11111111);
            _delay_ms(1000);
            
            this->shiftOut(0b00000000);
            _delay_ms(1000);
        }
    }

    void Wordclock::shiftOut(uint8_t value) {
        PORTB = ~(0b1 << LATCH) & PORTB;

        for (int i = 0; i < 8; i++)  {
            if (value & (1 << (7 - i))) {
                PORTB |= (0b1 << DATA);
            } else {
                PORTB &= ~(0b1 << DATA);
            }

            PORTB = (0b1 << CLOCK) | PORTB;
            PORTB = ~(0b1 << CLOCK) & PORTB;
        }

        PORTB = (0b1 << LATCH) | PORTB;
    }
}