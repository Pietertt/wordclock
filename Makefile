DEVICE			:= atmega328p
BAUD			:= 115200
OUTPUT			:= bin/main.hex
BIN				:= bin/main.bin
SRC				:= src/*.cpp
ARDUINO_BINARY	:= arduino.a
ARDUINO_PATH	:= /Users/pieterboersma/Library/Arduino15

compile:
	@docker exec -it $$(docker container ls  | grep 'wordclock' | awk '{print $$1}') avr-g++ \
		-Wall \
		-g \
		-Os \
		-mmcu=atmega328p \
		$(wildcard $(SRC)) $(ARDUINO_BINARY) \
		-o $(BIN) \
		-I include \
		-I $$(find $(ARDUINO_PATH) -path '*cores*/*' -name "arduino") \
		-I $$(find $(ARDUINO_PATH) -path '*variants*/*' -name "standard")
	@docker exec -it $$(docker container ls  | grep 'wordclock' | awk '{print $$1}') avr-objcopy \
		-j .text \
		-j .data \
		-O ihex $(BIN) $(OUTPUT)
	@stat -f%z bin/main.hex

flash:
	@avrdude -v -p$(DEVICE) -carduino -P$$(ls /dev/tty.usbmodem*) -b$(BAUD) -D -Uflash:w:$(OUTPUT)
	@make clean

clean:
	@rm -rf bin/*.bin
	@rm -rf bin/*.hex

run:
	@make compile
	@make flash
