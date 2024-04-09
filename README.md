# Creating a sorting algorithm

## The problem

This project is an intriguing case study that explores sorting algorithms and their performance. The objective is straightforward: given a sequence of random numbers arranged in a stack data structure (stack A), use an empty auxiliary stack (stack B) and a specific set of stack operations to sort them. The operations allowed for this task are described as follows:

- **`sa`** : **swap a** - Swap the first 2 elements at the top of stack A. Do nothing if there is only one or no elements).
- **`sb`** : **swap b** - Swap the first 2 elements at the top of stack B. Do nothing if there is only one or no elements).
- **`ss`** : **`sa`** and **`sb`** at the same time.
- **`pa`** : **push a** - take the first element at the top of b and put it at the top of a. Do nothing if B is empty.
- **`pb`** : **push b** - take the first element at the top of a and put it at the top of b. Do nothing if A is empty.
- **`ra`** : **rotate a** - shift up all elements of stack A by 1. The first element becomes the last one.
- **`rb`** : **rotate b** - shift up all elements of stack B by 1. The first element becomes the last one.
- **`rr`** : **`ra`** and **`rb`** at the same time.
- **`rra`** : **reverse rotate a** - shift down all elements of stack A by 1. The last element becomes the first one.
- **`rrb`** : **reverse rotate b** - shift down all elements of stack B by 1. The last element becomes the first one.
- **`rrr`** : **`rra`** and **`rrb`** at the same time.

The challenge is to find the shortest sequence of operations that accomplishes this task, with as few moves as possible. The push swap problem is often used as a benchmark for evaluating the efficiency of sorting algorithms and programs.

I managed to get an average of 595 moves for 100 random numbers and an average of 4806 for 500 random numbers.
