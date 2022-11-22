#pragma once

namespace Wordclock {
    
    class Register;
    class DoubleRegister;
    class Time;
    class Word;

    class Wordclock {

        public: 
            Wordclock();
            void setup();
            void test();
            void allOn();
            void allOff();
            void decide_time(Time* time);
            void blink();
            void commit();

        private:
            Register* a;
            Register* b;
            Register* c;
            Register* d;

            Word* HET;
            Word* IS;
            Word* VIJF;
            Word* TIEN;
            Word* KWART;
            Word* OVER;
            Word* VOOR;
            Word* HALF;
            Word* ELF;
            Word* TWEE;
            Word* TWEEDE_VIJF;
            Word* EEN;
            Word* VIER;
            Word* TWEEDE_TIEN;
            Word* TWAALF;
            Word* DRIE;
            Word* NEGEN;
            Word* ACHT;
            Word* ZES;
            Word* ZEVEN;
            Word* UUR;

            Word* words[21];

        protected:

    };
}