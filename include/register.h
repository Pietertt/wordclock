#pragma once

namespace Wordclock {
    class Register {

        public: 
            Register(int clock, int latch, int data, volatile uint8_t* reg);

            void setClockPin(int pin);
            void setLatchPin(int pin);
            void setDataPin(int pin);

            int getClockPin();
            int getLatchPin();
            int getDataPin();

            void setRegister(volatile uint8_t* reg);
            volatile uint8_t* getRegister();

        private:
            int clockPin;
            int latchPin;
            int dataPin;

            volatile uint8_t* reg;

        protected:
        
    };
}