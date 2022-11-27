#pragma once

namespace Wordclock {
    
    class Time {

        public: 
            Time();
            int getSeconds();
            void setSeconds(int seconds);
            int getMinutes();
            void setMinutes(int minutes);
            int getHour();
            void setHour(int hour);
            void tick();

        private:
            int seconds = 0;
            int minutes = 0;
            int hour = 0;

        protected:

    };
}
