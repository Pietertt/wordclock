#pragma once

#define F_CPU 16000000
#define BLINK_DELAY_MS 1000

#define CLOCKA 7
#define LATCHA 6
#define DATAA 5

#define CLOCKB 2
#define LATCHB 1
#define DATAB 0

#include <avr/io.h>
#include <util/delay.h>

#include "wordclock.h"
