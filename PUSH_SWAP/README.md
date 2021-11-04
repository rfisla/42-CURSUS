## PUSH_SWAP PROJECT (42 CURSUS)

The **Push_swap project** has a very simple goal: data will need to be sorted. You have at your disposal a set of int values, 2 stacks and a set of instructions to manipulate both stacks.
I have to create a program called push_swap which calculates and displays on the standard output the smallest program using Push_swap instruction language that sorts the integer arguments received. The learning objectives of this project are rigor, a more advanced use of C and use / implementatation of sorting algorithms whith given rules.

To sort the numbers I have the following operations at my disposal:
- **sa : swap a** - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
- **sb : swap b** - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
- **ss** : sa and sb at the same time.
- **pa : push a** - take the first element at the top of b and put it at the top of a. Donothing if b is empty.
- **pb : push b** - take the first element at the top of a and put it at the top of b. Donothing if a is empty.
- **ra : rotate a** - shift up all elements of stack a by 1. The first element becomes the last one.
- **rb : rotate b** - shift up all elements of stack b by 1. The first element becomes the last one.
- **rr** : ra and rb at the same time.
- **rra : reverse rotate a** - shift down all elements of stack a by 1. The last element becomes the first one.
- **rrb : reverse rotate b** - shift down all elements of stack b by 1. The last element becomes the first one.
- **rrr** : rra and rrb at the same time.

### The Push_swap program
I have to write a program named push_swap which will receive as an argument the stack a formatted as a list of integers. The first argument should be at the top of the stack (be careful about the order).
- The program must display the smallest list of instructions possible to sort the stack a, the smallest number being at the top.
- Instructions must be separaed by a ’\n’ and nothing else.
- The goal is to sort the stack with the minimum possible number of operations. During defence number of instructions found in my program will be compared with a maximum number of operations tolerated. If my program either displays a list too big or if the list isn’t sorted properly, I’ll get no points.
- In case of error, I must display Error followed by a ’\n’ on the standard error. Errors include for example: some arguments aren’t integers, some arguments are bigger than an integer, and/or there are duplicates.

A checker program is also provided. If the checker displays KO, it means that the push_swap program came up with a list of instructions that doesn’t sort the list. 

___
### Compilation and execution

Clone the repo in your terminal and compile with ```make``` to obtain the ```push_swap``` program

Some tests:
- ./push_swap 1 3 2
- ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
- ARG=$(seq -1000 1000 | sort -R | tail -n 100 | tr '\n' ' ') ; ./push_swap $ARG | wc -l
- ARG=$(seq -1000 1000 | sort -R | tail -n 500 | tr '\n' ' ') ; ./push_swap $ARG | ./checker $ARG

### Number of sorting movements depending on the size of the stack

- 2 : 2 Movimientos
- 3 : Between 2 and 3 movements
- 5 : between 7 and 12 movements
- 100 : Between 880 and 920 movements
- 500 : Between 8900 and 9100 movements

## Result 
[![jaeskim's 42Project Score](https://badge42.herokuapp.com/api/project/rufernan/push_swap)](https://github.com/JaeSeoKim/badge42)

[![forthebadge](https://forthebadge.com/images/badges/made-with-c.svg)](https://forthebadge.com)
