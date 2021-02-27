#define F_CPU 16000000
#define BLINK_DELAY_MS 1000

#define LATCH 0
#define CLOCK 4
#define DATA 3

#define LED 3

#include <avr/io.h>
#include <util/delay.h>

//void shiftOut(uint8_t val);

class Test {

    public:
        Test() {
            DDRB |= 0B111111; // PORTB5

            while(1) {
                this->shiftOut(0b111111);
                _delay_ms(BLINK_DELAY_MS);

                this->shiftOut(0b000000);
                _delay_ms(BLINK_DELAY_MS);
            }

        }
    
    private:
        void shiftOut(uint8_t val)
        {
            PORTB = ~(0b1 << LATCH) & PORTB;
            uint8_t i;

            for (i = 0; i < 8; i++)  {
                if (val & (1 << (7 - i))) {
                    PORTB |= (1 << DATA);  // Data 1
                } else {
                    PORTB &= ~(1 << DATA); // Data 0
                }
                PORTB |= (1 << CLOCK);      // Clock HIGH
                _delay_us(10);
                PORTB &= ~(1 << CLOCK);     // Clock LOW
                _delay_us(10);
            }

            PORTB = (0b1 << LATCH) | PORTB;
        }
};

int main (void) {

    Test test;

    return 0;
}