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

            uint8_t getData();
            void setData(bool data, int position);
            void setData(uint8_t data);
            void toggleData(int position);
            uint8_t getCopyData();
            void setCopyData(bool data, int position);
            void setCopyData(uint8_t copyData);

            virtual void shiftOut() = 0;

        private:
            int clockPin;
            int latchPin;
            int dataPin;

            uint8_t data;
            uint8_t copyData;

        protected:

    };
}
