NAME			:= main.ccp
DEVICE			:= atmega328p
PORT			:= /dev/tty.usbmodem2101
BAUD			:= 115200
OUTPUT			:= bin/main.hex
BIN				:= bin/main.bin
SRC				:= src/
CONTAINER_ID 	:= 2ae5df2eb236
CORE			:= /var/folders/jb/tmjxrj3s4jd3cfj0ddpxv16w0000gn/T/arduino_build_878921/../arduino_cache_921585/core/core_arduino_avr_uno_51f02b7210b938436b779d1c032618e1.a
ARDUINO			:= /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/cores/arduino
STANDARD		:= /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/variants/standard
SOURCE			:= /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/libraries/SPI/src
SPI				:= /Applications/Arduino.app/Contents/Java/hardware/arduino/avr/libraries/SPI/src/SPI.cpp

compile:
	@docker exec -it $(CONTAINER_ID) avr-g++ -Wall -g -Os -mmcu=atmega328p $(wildcard src/*.cpp) $(SPI) /private/var/folders/ny/2xdk0hds4nj5bk2rt8rv9jgh0000gn/T/arduino-sketch-BCEA2B85DA9400418B2DF93B190A4161/libraries/Rtc_by_Makuna/RtcDateTime.cpp.o /private/var/folders/ny/2xdk0hds4nj5bk2rt8rv9jgh0000gn/T/arduino-sketch-BCEA2B85DA9400418B2DF93B190A4161/libraries/Rtc_by_Makuna/RtcUtility.cpp.o $(CORE) -o $(BIN) -I include -I$(ARDUINO) -I$(SOURCE) -Iinclude -I$(STANDARD) -I/Users/pieterboersma/Documents/Arduino/libraries/Rtc_by_Makuna/src
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
