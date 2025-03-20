# 42 Push_Swap

<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/ReivenIV/42_push_swap?color=lightblue" />
<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/ReivenIV/42_push_swap?color=green" />

Because swap_push isn't as natural

Given a set of integers, sort it using a predefined set of instructions using
two stacks. The instruction set is defined below. This program outputs a program
in push_swap instructions that sorts the input integers.

> ⚠️ **Warning**: Don't copy/paste anything you don't understand: it's bad for you, and for the school.

## Instruction set

For the following instructions, if the instruction is not possible, the part of
it that can't be executed won't.

| Code  | Instruction                         | Action                                                 |
| ----- | ----------------------------------- | ------------------------------------------------------ |
| `sa`  | swap a                              | swaps the 2 top elements of stack a                    |
| `sb`  | swap b                              | swaps the 2 top elements of stack b                    |
| `ss`  | swap a + swap b                     | both `sa` and `sb`                                     |
| `pa`  | push a                              | moves the top element of stack b at the top of stack a |
| `pb`  | push b                              | moves the top element of stack a at the top of stack b |
| `ra`  | rotate a                            | shifts all elements of stack a from bottom to top      |
| `rb`  | rotate b                            | shifts all elements of stack b from bottom to top      |
| `rr`  | rotate a + rotate b                 | both `ra` and `rb`                                     |
| `rra` | reverse rotate a                    | shifts all elements of stack a from top to bottom      |
| `rrb` | reverse rotate b                    | shifts all elements of stack b from top to bottom      |
| `rrr` | reverse rotate a + reverse rotate b | both `rra` and `rrb`                                   |

- In case you want to test the projet (or your own) i totally recomend to use these tester : 
	- https://github.com/SimonCROS/push_swap_tester	

# Stats of these push_swap : 

- Started date : 22/01/2025.
- Finished date : 11/02/2025.
- validated date : 12/02/2025.
- Validated with : 98 points.
- Time spend coding these project : 46hrs 32min

### 100 random numbers 100 runs:
 - worst : 677
 - median : 605
 - best : 531
 - deviation : 28.8
 - effectivnes : 100%
 - objective of less than 700 moves : 100%

### 500 random numbers 100 runs:
 - worst : 5746
 - median : 5480
 - best : 5102
 - deviation : 123.3
 - effectivnes : 100%
 - objective of less than 5500 moves : ~60%
