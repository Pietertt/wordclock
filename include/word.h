#pragma once

namespace Wordclock {

    class Wordclock;
    class Register;
    
    class Word {

        public: 
            Word(Wordclock*, Register* reg, int place);

            void on();
            void off();
            void toggle();
            void test();

            Register* getRegister();
            void setRegister(Register* reg);
            int getPlace();
            void setPlace(int place);

        private:
            Wordclock* wordclock;
            Register* reg;
            int place;

        protected:

    };
}
