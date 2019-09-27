# 0x18. C - Stacks, Queues - LIFO, FIFO
## Monty

Monty 0.98 is a scripting language that is first compiled into Monty byte codes (Just like Python). It relies on a unique stack, with specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files.

## Monty byte code files

Files containing Monty byte codes usually have the .m extension. Most of the industry uses this standard but it is not required by the specification of the language. There is not more than one instruction per line. There can be any number of spaces before or after the opcode and its argument:

```
 push 0$
push 1$
push 2$
  push 3$
                   pall    $
push 4$
    push 5    $
      push    6        $
pall$

```

Monty byte code files can contain blank lines (empty or made of spaces only, and any additional text after the opcode or its required argument is not taken into account:

```
push 0 Push 0 onto the stack$
push 1 Push 1 onto the stack$
$
push 2$
  push 3$
                   pall    $
$
$
                           $
push 4$
$
    push 5    $
      push    6        $
$
pall This is the end of our program. Monty is awesome!$

```

## Usage

All the files are compiled in the following form:

```
 gcc -Wall -Werror -Wextra -pedantic *.c -o monty.

```

To Run the program:

```
 ./monty bytecode_file
```

Available Operation Codes:

| Opcode | Description |
|---------------- | -----------|
|push   | Pushes an element to the stack.|
|pall   | Prints all the values on the stack, starting from the to of the stack.|
|pint   | Prints the value at the top of the stack, followed by a new line.|
|pop    | Removes the to element of the stack. |
|swap   | Swaps the top to elements of the stack.|
|add    | Adds the top two elements of the stack.|
|nop    | This opcode does not do anything.|
|sub    | Subtracts the top two elements of the stack from the second top element of the stack.|
|div    | Divides the second top element of the stack by the top element of the stack.|
|mul | Multiplies the second top element of the stack with the top element of the stack.|
|mod    | Computes the rest of the division of the second top element of the stack by the top element of the stack.|
|#      | When the first non-space character of a line is #, treat this line as a comment.|
|pchar  | prints the char at the top of the stack, followed by a new line.|
|pstr   | prints the string starting at the top of the stack, followed by a new line.|
|rotl   | rotates the stack to the top.|
|rotr   | rotates the stack to the bottom.|
|stack  | sets the format of the data to a stack (LIFO). This is the default behavior of the program.|
|queue  | sets the format of the data to a queue (FIFO).|

## Tasks

### 0. push, pall
Implement the push and pall opcodes.

1. The push opcode
* Usage: push <int>
   where <int> is an integer
* if <int> is not an integer or if there is no argument given to push, print the error message L<line_number>: usage: push integer, followed by a new line, and exit with the status EXIT_FAILURE
   where is the line number in the file
* You won’t have to deal with overflows. Use the atoi function

2. The pall opcode

The opcode pall prints all the values on the stack, starting from the top of the stack.

* Usage pall
* Format: see example
* If the stack is empty, don’t print anything

### 1. pint
Implement the pint opcode.
* Usage: pint
* If the stack is empty, print the error message L<line_number>: can't pint, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

### 2. pop
Implement the pop opcode.
* Usage: pop
* If the stack is empty, print the error message L<line_number>: can't pop an empty stack, followed by a new line, and exit with the status EXIT_FAILURE

### 3. swap
Implement the swap opcode.
* Usage: swap
* If the stack contains less than two elements, print the error message L<line_number>: can't swap, stack too short, followed by a new line, and exit with the status EXIT_FAILURE

### 4. add
Implement the add opcode.
* Usage: add
* If the stack contains less than two elements, print the error message L<line_number>: can't add, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
 *The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
   The top element of the stack contains the result
   The stack is one element shorter

### 5. nop
Implement the nop opcode.
* Usage: nop

### 6. sub
Implement the sub opcode.
* Usage: sub
* If the stack contains less than two elements, print the error message L<line_number>: can't sub, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
   The top element of the stack contains the result
   The stack is one element shorter

### 7. div
Implement the div opcode.
* Usage: div
* If the stack contains less than two elements, print the error message L<line_number>: can't div, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
   The top element of the stack contains the result
   The stack is one element shorter
* If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

### 8. mul
Implement the mul opcode.
* Usage: mul
* If the stack contains less than two elements, print the error message L<line_number>: can't mul, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
   The top element of the stack contains the result
   The stack is one element shorter

### 9. mod
Implement the mod opcode.
* Usage: mod
* If the stack contains less than two elements, print the error message L<line_number>: can't mod, stack too short, followed by a new line, and exit with the status EXIT_FAILURE
* The result is stored in the second top element of the stack, and the top element is removed, so that at the end:
   The top element of the stack contains the result
   The stack is one element shorter
* If the top element of the stack is 0, print the error message L<line_number>: division by zero, followed by a new line, and exit with the status EXIT_FAILURE

### 10. comments
Every good language comes with the capability of commenting.

### 11. pchar
Implement the pchar opcode.
* Usage: pchar
* The integer stored at the top of the stack is treated as the ascii value of the character to be printed
* If the value is not in the ascii table (man ascii) print the error message L<line_number>: can't pchar, value out of range, followed by a new line, and exit with the status EXIT_FAILURE
* If the stack is empty, print the error message L<line_number>: can't pchar, stack empty, followed by a new line, and exit with the status EXIT_FAILURE

### 12. pstr
Implement the pstr opcode.
* Usage: pstr
* The integer stored in each element of the stack is treated as the ascii value of the character to be printed
* The string stops when either:
   the stack is over
   the value of the element is 0
   the value of the element is not in the ascii table
* If the stack is empty, print only a new line

### 13. rotl
Implement the rotl opcode.
* Usage: rotl
* The top element of the stack becomes the last one, and the second top element of the stack becomes the first one
* rotl never fails

### 14. rotr 
Implement the rotr opcode
* Usage: rotr
* The last element of the stack becomes the top element of the stack
rotr never fails

### 15. stack, queue 
Implement the stack and queue opcodes.
1. The stack opcode
The opcode stack sets the format of the data to a stack (LIFO). This is the default behavior of the program.
* Usage: stack

2. The queue opcode
The opcode queue sets the format of the data to a queue (FIFO).
* Usage: queue
When switching mode:
* The top of the stack becomes the front of the queue
* The front of the queue becomes the top of the stack

### 16. Holberton
Write a Brainf*ck script that prints Holberton, followed by a new line.
* All your Brainf*ck files should be stored inside the bf sub directory
* You can install the bf interpreter to test your code: sudo apt-get install bf
* Read: Brainf*ck

### 17. Add two digits
Add two digits given by the user.
* Read the two digits from stdin, add them, and print the result
* The total of the two digits with be one digit-long (<10)

### 18. Multiplication
Multiply two digits given by the user.

* Read the two digits from stdin, multiply them, and print the result
* The result of the multiplication will be one digit-long (<10)

### 19. Multiplication level up
Multiply two digits given by the user.
* Read the two digits from stdin, multiply them, and print the result, followed by a new line
