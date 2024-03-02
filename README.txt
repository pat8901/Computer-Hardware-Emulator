CPU Emulation Project
=====================

Description:
------------
This program aims to emulate the components of a CPU using the C programming language. 
So far, I have implemented the clock and a generic register. The clock provides the timing mechanism for the CPU, 
and the generic register serves as a placeholder for storing data or addresses. In its current form the program will generate 
random 8-bit values and insert into the inputs of the generic register. On the next clock cycle the outputs of the register are
set equal to the inputs. 

As the program runs the status is printed to the console. 

Next Steps:
-----------
In the upcoming phases of the project, I plan to implement the instruction register and the instruction pointer register. 
The instruction register will hold the current instruction being executed, while the instruction 
pointer register will point to the next instruction to be executed.

How to Run:
-----------
In order to run the program be sure to compile both clock.c and register.c. Onced compiled run the register executable,
this is the entry point into the program.

Author:
-------
Patrick Seitz