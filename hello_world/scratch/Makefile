CC=arm-none-eabi-gcc
CFLAGS= -c -mcpu=cortex-m4 -mthumb -std=gnu11 -O0

# $^ : dependency
# $@ : target
# left hand : target
# right hand : dependency

all: main.o led.o

main.o : main.c
# $(CC) $(CFLAGS) main.c -o main.o
# $(CC) $(CFLAGS) $^ -o $@
	$(CC) $(CFLAGS) -o $@ $^

led.o : led.c
	$(CC) $(CFLAGS) -o $@ $^


clean:
	rm *.o
