PRJ_NAME       = blink
MCU_TARGET     = attiny2313
PROGRAMMER     = usbasp

# The above values should be set according to the individual project.
# This makefile assumes one single source file with no dependencies beyond
# cstdlib. If there is more going on than this, you will need to edit the steps
# below.

OPTIMIZE       = -Os
CC             = avr-gcc
OBJCOPY        = avr-objcopy
OBJDUMP        = avr-objdump
CFLAGS         = -g -mmcu=${MCU_TARGET} -Wall ${OPTIMIZE}

${PRJ_NAME}.hex : ${PRJ_NAME}.elf
	${OBJCOPY} -O ihex -R .eeprom ${PRJ_NAME}.elf ${PRJ_NAME}.hex
${PRJ_NAME}.elf : ${PRJ_NAME}.o
	${CC} ${CFLAGS} -o ${PRJ_NAME}.elf ${PRJ_NAME}.o
${PRJ_NAME}.o : ${PRJ_NAME}.c
	${CC} ${CFLAGS} -c ${PRJ_NAME}.c

install :
	avrdude -c ${PROGRAMMER} -p ${MCU_TARGET} -U flash:w:${PRJ_NAME}.hex

clean :
	rm ${PRJ_NAME}.hex ${PRJ_NAME}.elf ${PRJ_NAME}.o
