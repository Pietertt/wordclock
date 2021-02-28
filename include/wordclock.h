#pragma once

namespace Wordclock {
    class Wordclock {

        public: 
            Wordclock();

        private:
            void shiftOut(int data, int latch, int clock, bool test, uint8_t value);


    };
}