#pragma once

#define F_CPU 16000000
#define BLINK_DELAY_MS 1000

#define LATCH 0
#define CLOCK 4
#define DATA 3

#include <avr/io.h>
#include <util/delay.h>

#include "wordclock.h"
