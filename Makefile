NAME			:= main.ccp
DEVICE			:= atmega328p
PORT			:= /dev/tty.usbmodem2201
BAUD			:= 115200
OUTPUT			:= bin/main.hex
BIN				:= bin/main.bin
SRC				:= src/
CONTAINER_ID 	:= bc0fa43dc0e3

compile:
	@docker exec -it $(CONTAINER_ID) avr-gcc -Wall -g -Os -mmcu=atmega328p -o $(BIN) $(wildcard src/*.cpp) -I include
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


# NAME			:= main.ccp
# DEVICE			:= atmega328p
# PORT			:= /dev/tty.usbmodem2201
# BAUD			:= 115200
# OUTPUT			:= bin/main.hex
# BIN				:= bin/main.bin
# SRC				:= src/
# CONTAINER_ID 	:= 367eae41ab8e
# COMPILER		:= /Users/pieterboersma/Library/Arduino15/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++

# compile:
# 	@echo 8
# 	@/Users/pieterboersma/Library/Arduino15/packages/arduino/tools/avr-gcc/7.3.0-atmel3.6.1-arduino7/bin/avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -flto -w -x c++ -E -CC -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -I/Users/pieterboersma/Library/Arduino15/packages/arduino/hardware/avr/1.8.6/cores/arduino -Iinclude -I/Users/pieterboersma/Library/Arduino15/packages/arduino/hardware/avr/1.8.6/variants/standard $(wildcard src/*.cpp) -o /dev/null

# test:
# 	@$(COMPILER) -Wall -g -Os -mmcu=atmega328p $(wildcard src/*.cpp) /private/var/folders/ny/2xdk0hds4nj5bk2rt8rv9jgh0000gn/T/arduino-sketch-3352D81E12F1523ED5373D4D680153BC/libraries/SPI/SPI.cpp.o /private/var/folders/ny/2xdk0hds4nj5bk2rt8rv9jgh0000gn/T/arduino-sketch-3352D81E12F1523ED5373D4D680153BC/../arduino-core-cache/core_arduino_avr_uno_a6211c11026c186eb63d730dc4093e25.a -o $(BIN) -I include -I/Users/pieterboersma/Library/Arduino15/packages/arduino/hardware/avr/1.8.6/cores/arduino -I/Users/pieterboersma/Library/Arduino15/packages/arduino/hardware/avr/1.8.6/libraries/SPI/src -Iinclude -I/Users/pieterboersma/Library/Arduino15/packages/arduino/hardware/avr/1.8.6/variants/standard
# 	@docker exec -it $(CONTAINER_ID) avr-objcopy -j .text -j .data -O ihex $(BIN) $(OUTPUT)

# flash:
# 	@avrdude -v -p$(DEVICE) -carduino -P$(PORT) -b$(BAUD) -D -Uflash:w:$(OUTPUT)
# 	@make clean

# clean:
# 	@rm -rf bin/*.bin
# 	@rm -rf bin/*.hex

# run:
# 	@make test
# 	@make flash


# # avr-g++ -c -g -Os -w -std=gnu++11 -fpermissive -fno-exceptions -ffunction-sections -fdata-sections -fno-threadsafe-statics -Wno-error=narrowing -flto -w -x c++ -E -CC -mmcu=atmega328p -DF_CPU=16000000L -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR -I/Users/pieterboersma/Library/Arduino15/packages/arduino/hardware/avr/1.8.6/cores/arduino -I/Users/pieterboersma/Library/Arduino15/packages/arduino/hardware/avr/1.8.6/variants/standard /private/var/folders/ny/2xdk0hds4nj5bk2rt8rv9jgh0000gn/T/arduino-sketch-3352D81E12F1523ED5373D4D680153BC/sketch/sketch_nov29a.ino.cpp -o /dev/null

# # @docker exec -it $(CONTAINER_ID) avr-gcc -Wall -g -Os -mmcu=atmega328p -o $(BIN) main.cpp wordclock.cpp register.cpp singleregister.cpp doubleregister.cpp time.cpp word.cpp -I include
# # @docker exec -it $(CONTAINER_ID) avr-objcopy -j .text -j .data -O ihex $(BIN) $(OUTPUT)