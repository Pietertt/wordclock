#pragma once

namespace Wordclock {
    
    class Word {

        public: 
            Word();
            int getPosition();
            void setPosition(int position);
            int getLength();
            void setLength(int length);
            volatile uint8_t* getRegister();
            void setRegister(volatile uint8_t* reg);

        private:
            int position;
            int length;
            volatile uint8_t* reg;

        protected:


    };
}
