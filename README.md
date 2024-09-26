Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

monty/
│
├── main.c               # main function, free_stack and execute_opcode
├── stack_ops.c          # push, pall, pint functions
├── stack_ops2.c         # pop, swap, add functions
├── util.c               # nop, is_integer functions
├── monty.h              # header file with structure definitions and function prototypes
