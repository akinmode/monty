# The Monty Program

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on unique stacks and queues (LIFO and FIFO), with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files and close the gap between scripting and programming languages..


# Compilation & Output
```
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```
## Commands (Option Codes)
### Push opcode

The opcode `push` pushes an element to the stack.

_**Usage:**_ `push <int>`, where *int* is an integer.

### Pall opcode

The opcode `pall` prints all the values on the stack, starting from the top of the stack.

_**Usage:**_ `pall`. If the stack is empty, `pall` don’t print anything.
