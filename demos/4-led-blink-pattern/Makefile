# makfile configuration
COMMON_OBJECTS  = main.o 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -I/opt/ti/msp430-gcc/include
LDFLAGS		= -L/opt/ti/msp430-gcc/include 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: led.elf 

#additional rules for files
led.elf: ${COMMON_OBJECTS} 
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^ ../lib/libTimer.a

load: led.elf
	mspdebug ${MSPLOADER_OPTION} "prog $^"

clean:
	rm -f *.o *.elf

main.o: led.h

wdInterruptHandler.o:  led.h

