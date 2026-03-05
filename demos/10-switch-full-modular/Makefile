# makfile configuration
COMMON_OBJECTS  = 
CPU             = msp430g2553
CFLAGS          = -mmcu=${CPU} -I../h -I/opt/ti/msp430-gcc/include
LDFLAGS		= -L/opt/ti/msp430-gcc/include 

#switch the compiler (for the internal make rules)
CC              = msp430-elf-gcc
AS              = msp430-elf-as

all: button.elf 

#additional rules for files
button.elf: ${COMMON_OBJECTS} p1_interrupt_handler.o led.o switches.o buttonMain.o ../lib/libTimer.a
	${CC} ${CFLAGS} ${LDFLAGS} -o $@ $^

load: button.elf
	mspdebug ${MSPLOADER_OPTION} "prog $^"

clean:
	rm -f *.o *.elf

