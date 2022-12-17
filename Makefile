NAME			:= main.ccp
DEVICE			:= atmega328p
PORT			:= /dev/tty.usbmodem2101
BAUD			:= 115200
OUTPUT			:= bin/main.hex
BIN				:= bin/main.bin
SRC				:= src/
CONTAINER_ID 	:= bc0fa43dc0e3243f975b92e66174d018fe0335f3e2aa1e74e68bb3f63661c8e0
CORE			:= /private/var/folders/ny/2xdk0hds4nj5bk2rt8rv9jgh0000gn/T/arduino-sketch-BCEA2B85DA9400418B2DF93B190A4161/../arduino-core-cache/core_arduino_avr_uno_a6211c11026c186eb63d730dc4093e25.a
ARDUINO			:= /Users/pieterboersma/Library/Arduino15/packages/arduino/hardware/avr/1.8.6/cores/arduino
STANDARD		:= /Users/pieterboersma/Library/Arduino15/packages/arduino/hardware/avr/1.8.6/variants/standard
SOURCE			:= /Users/pieterboersma/Library/Arduino15/packages/arduino/hardware/avr/1.8.6/libraries/SPI/src
SPI				:= /private/var/folders/ny/2xdk0hds4nj5bk2rt8rv9jgh0000gn/T/arduino-sketch-BCEA2B85DA9400418B2DF93B190A4161/libraries/SPI/SPI.cpp.o
COMPILER		:= /Users/pieterboersma/Library/Arduino15/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++

compile:
	@$(COMPILER) -Wall -g -Os -mmcu=atmega328p $(wildcard src/*.cpp) $(SPI) /private/var/folders/ny/2xdk0hds4nj5bk2rt8rv9jgh0000gn/T/arduino-sketch-BCEA2B85DA9400418B2DF93B190A4161/libraries/Rtc_by_Makuna/RtcDateTime.cpp.o /private/var/folders/ny/2xdk0hds4nj5bk2rt8rv9jgh0000gn/T/arduino-sketch-BCEA2B85DA9400418B2DF93B190A4161/libraries/Rtc_by_Makuna/RtcUtility.cpp.o $(CORE) -o $(BIN) -I include -I$(ARDUINO) -I$(SOURCE) -Iinclude -I$(STANDARD) -I/Users/pieterboersma/Documents/Arduino/libraries/Rtc_by_Makuna/src
	@docker exec -it $(CONTAINER_ID) avr-objcopy -j .text -j .data -O ihex $(BIN) $(OUTPUT)

flash:
	@avrdude -v -p$(DEVICE) -carduino -P$(PORT) -b$(BAUD) -D -Uflash:w:$(OUTPUT)
	@make clean

clean:
	@rm -rf bin/*.bin
	@rm -rf bin/*.hex

run:
	@make compile
	@make flash
