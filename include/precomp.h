#pragma once

#define F_CPU                       16000000
#define BLINK_DELAY_MS              1000
#define AMOUNT_OF_WORDS             21
#define DUTY_CYCLE_LOW              1
#define DUTY_CYCLE_HIGH             100
#define LOW_POWER_HOUR              16

#define DS1302_ENABLE               0x8E
#define DS1302_TRICKLE              0x90
#define DS1302_SCLK_PIN             SCLK
#define DS1302_IO_PIN               IO
#define DS1302_CE_PIN               C_E
#define bcd2bin                     (h,l)    (((h)*10) + (l))
#define bin2bcd_h                   (x)   ((x)/10)
#define bin2bcd_l                   (x)    ((x)%10)
#define DS1302_SECONDS              0x80
#define DS1302_MINUTES              0x82
#define DS1302_HOURS                0x84
#define DS1302_DATE                 0x86
#define DS1302_MONTH                0x88
#define DS1302_DAY                  0x8A
#define DS1302_YEAR                 0x8C
#define DS1302_CLOCK_BURST          0xBE
#define DS1302_CLOCK_BURST_WRITE    0xBE
#define DS1302_CLOCK_BURST_READ     0xBF
#define DS1302_RAMSTART             0xC0
#define DS1302_RAMEND               0xFC
#define DS1302_RAM_BURST            0xFE
#define DS1302_RAM_BURST_WRITE      0xFE
#define DS1302_RAM_BURST_READ       0xFF
#define DS1302_D0                   0  
#define DS1302_D1                   1
#define DS1302_D2                   2
#define DS1302_D3                   3
#define DS1302_D4                   4
#define DS1302_D5                   5
#define DS1302_D6                   6
#define DS1302_D7                   7
#define DS1302_READBIT              DS1302_D0
#define DS1302_RC                   DS1302_D6
#define DS1302_CH                   DS1302_D7
#define DS1302_AM_PM                DS1302_D5
#define DS1302_12_24                DS1302 D7
#define DS1302_WP                   DS1302_D7
#define DS1302_ROUT0                DS1302_D0
#define DS1302_ROUT1                DS1302_D1
#define DS1302_DS0                  DS1302_D2
#define DS1302_DS1                  DS1302_D2
#define DS1302_TCS0                 DS1302_D4
#define DS1302_TCS1                 DS1302_D5
#define DS1302_TCS2                 DS1302_D6
#define DS1302_TCS3                 DS1302_D7

#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stddef.h>

#include <arduino.h>
#include <SPI.h>
#include <ThreeWire.h>
#include <RtcDS1302.h>

#include "wordclock.h"
#include "register.h"
#include "singleregister.h"
#include "doubleregister.h"
#include "word.h"
#include "RTC.h"