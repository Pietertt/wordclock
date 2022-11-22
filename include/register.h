#pragma once

namespace Wordclock {
    class Register {

        public: 
            void setClockPin(int pin);
            void setLatchPin(int pin);
            void setDataPin(int pin);

            int getClockPin();
            int getLatchPin();
            int getDataPin();

            byte getData();
            void setData(bool data, int position);
            void setData(byte data);
            void toggleData(int position);

            virtual void shiftOut() = 0;

        private:
            int clockPin;
            int latchPin;
            int dataPin;

            byte data;

        protected:
        
    };
}