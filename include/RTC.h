#pragma once
                                                                                                         //|
#include <stddef.h>                                                                                      //|
#include <string.h>                                                                                    //|
#include "Arduino.h"                                                                                   //|

#define DS1302_ENABLE            0x8E                                                                    //|
#define DS1302_TRICKLE           0x90                                                                    //|

namespace Wordclock {
    class RTC  {                                                                                  //|
        public:                                                                                                //|
        //+++++++++++++++++++++++++++++++++++++++++++++ Class Constructor +++++++++++++++++++++++++++++++++++++++//|  
            RTC(uint8_t inSCLK, uint8_t inIO, uint8_t inC_E);                                                     //|
                                                                                                                //|
            void initRTC(uint8_t CLK, uint8_t IO, uint8_t ENABLE);     // Sets the pins and enable them          //|
            void DS1302_clock_burst_read( uint8_t *p);                 // Reads clock data, and sets pinmode     //|
            void DS1302_clock_burst_write( uint8_t *p);                // Writes clcok data, and sets pinmode    //|
            uint8_t DS1302_read(int address);                          // Reads a byte from DS1302, sets pinmode //|
            void DS1302_write( int address, uint8_t data);             // Writes a byte to DS1302, sets pinmode  //|
            void _DS1302_start( void);                                 // Function to help setup start condition //|
            void _DS1302_stop(void);
            uint8_t _DS1302_toggleread( void);
            void _DS1302_togglewrite( uint8_t data, uint8_t release);
            void setDS1302Time(uint8_t seconds, uint8_t minutes,
                            uint8_t hours, uint8_t dayofweek,
                            uint8_t dayofmonth, uint8_t month,
                            int year);
            void updateTime();

            uint8_t SCLK;
            uint8_t IO;
            uint8_t C_E;
            uint8_t seconds;
            uint8_t minutes;
            uint8_t hours;
            uint8_t dayofweek;
            uint8_t dayofmonth;
            uint8_t month;
            int year;
        };
}
