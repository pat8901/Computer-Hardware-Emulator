all: output

output: main.o register.o instruction_register.o instruction_pointer.o ram.o clock.o
	gcc main.o register.o instruction_register.o instruction_pointer.o ram.o clock.o -o output

main.o: main.c 
	gcc -c main.c

ram.o: ./ram/ram.c 
	gcc -c ./ram/ram.c

clock.o: ./clock/clock.c 
	gcc -c ./clock/clock.c

register.o: ./registers/register.c 
	gcc -c ./registers/register.c

instruction_register.o: ./registers/instruction_register.c 
	gcc -c ./registers/instruction_register.c

instruction_pointer.o: ./registers/instruction_pointer.c 
	gcc -c ./registers/instruction_pointer.c

clean:
	rm *.o output