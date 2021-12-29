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

            byte getData();
            void setData(bool data, int position);
            void setData(byte data);

            void setRegister(volatile uint8_t* reg);
            volatile uint8_t* getRegister();

            void shiftOut(byte value);
            void doubleShiftOut(Register* a, byte value);

            void increment();
            void doubleIncrement(Register* a);
            void loop();
            void doubleLoop(Register* reg);

        private:
            int clockPin;
            int latchPin;
            int dataPin;

            volatile uint8_t* reg;
            byte data;

        protected:
        
    };
}
