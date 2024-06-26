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

## My Algorithm

This explanation is made for an example of 10 elements, however, to organize a larger amount of numbers the procedure is exactly the same, without any changes.


## Results
For **100 random numbers** this are the results (1000 tests):

![Screenshot from 2023-03-01 01-43-04](images/100.png)

The average was 595 moves.

---

For **500 random numbers**  random numbers this are the results (1000 tests):

![image](images/500.png)

The average was 4806 moves.

---

For **1000 random numbers**  random numbers this are the results (50 tests):

![image](images/1000.png)

The average was 12281 moves.

---
For **10000 random numbers**  random numbers this are the results (1 test):

![image](images/10000.png)

It took, almost 15min to sort the numbers

---
## Time complexity of my algorithm

![image](images/Ctime.png)

As you can see, this algorithm is quite efficient for low input sizes, however, the processing of the algorithm is quite demanding, which means that after a certain input size, a behavior of O(n*n) is reached.

## Visualization

![image](images/gui.png)

In order to better understand what was going on with the algorithm for larger numbers, I used this visualization (https://github.com/elijahkash/push_swap_gui)

## Theory

As this project consists of evaluating the performance of algorithms, I decided to study the main algorithms that existed from the least efficient to the most efficient.

## Big O notation
![image](images/bigO.png)

It describes the worst-case scenario for the number of operations an algorithm takes as a function of the size of the input. The notation is used to classify algorithms according to how their running time or space requirements grow as the size of the input increases.

For example, in the O(N^2) the number of instructions in a program/space occupied by a program is quadratic. When the input size doubles, the time increases by 4 times.

### When a algorithm is stable?

In programming, stability refers to the property of an algorithm that its output does not change significantly for small changes in the input. A stable algorithm is predictable and its results are consistent and reliable, even for inputs that are only slightly different from each other.


## Basic sorting algorithms

### Selection Sort

Selection sort is a simple sorting algorithm that works by repeatedly finding the minimum element from the unsorted part of the list and swapping it with the first element. The algorithm then moves on to the next unsorted element and repeats the process until the entire list is sorted.

![0009-selection-sort-animation](images/selection_Sort.gif)

The time complexity of selection sort is O(n^2) in the worst and average case, but O(n) in the best case (when the array is already sorted). This is because for each element in the array, the algorithm must compare it with every other element in the array.

Time complexity: O(n^2)

### Insertion Sort (keep the deck in order)

![0009-Dark_inverted_insertion_sorting](images/insertion_sort.gif)


It iterates through the list, comparing each element to the elements that come before it, and shifting those elements to the right as necessary to make room for the current element. We can think of this algorithm as someone who plays cards and likes to keep his deck in order: whenever he receives a new card, he goes through the list from beginning to end (or vice versa), trying to place the card between an element with key below yours and one above yours.

Example: 

Imagine a deck of cards and the goals is to sort them in ascending order. Is possible to use the insertion sort algorithm to do this.

1.  Start with the first card in your hand. This is your sorted portion of the deck, because a single card is already sorted.
2. Pick up the second card and compare it to the first card. If the second card is smaller, swap their positions so that the smaller card is now first. Otherwise, leave the cards where they are.
3. Pick up the third card and compare it to the first two cards. Insert it in the correct position in the sorted portion of the deck, so that it is placed before the larger cards and after the smaller cards.
4. Continue this process for each subsequent card, comparing it to the cards in the sorted portion of the deck and inserting it in the correct position.

### Bubble Sort

![0009-bubble-sort-animation](images/Bubble_sort.gif)

It repeatedly steps through the list to be sorted, compares each pair of adjacent items and swaps them if they are in the wrong order.

When we reach the end of the vector, we say that the element that is there (at the end) is sorted, and we don't touch it again. We carry out these changes successively, until only the first element remains to be sorted: in this situation, the vector is completely sorted.

### Shell Sort

![0009-Shell_Sort_Algorithm](images/shell_sort.gif)

Shell sort is a variation of the insertion sort algorithm that improves its efficiency by comparing elements that are farther apart from each other, before comparing elements that are closer together. This is done by using a gap value, also called the increment, that determines the distance between the elements that are being compared.

https://youtu.be/M3bS6w1R434

The time complexity of shell sort is O(n^2), but it is generally faster than bubble sort and insertion sort for larger lists because of the gap value that allows for elements that are farther apart to be compared before elements that are closer together.

### Counting Sort


![image](images/counting_sort.png)


Counting Sort is a sorting algorithm that works by counting the number of occurrences of each element in an array and then using that information to place the elements in their correct positions. It is an efficient algorithm for sorting arrays with a small range of values, but it is not suitable for arrays with a large range of values or for arrays where the elements are not integers. The basic idea of counting sort is to create a count array for each element in the input array and use that count array to determine the position of each element in the sorted output array.

The time complexity of Counting Sort is O(n+k), where n is the number of elements in the input array and k is the range of values of the elements in the array. This makes it an efficient algorithm for arrays with a small range of values.

### Radix Sort

Radix sort is a non-comparative integer sorting algorithm that sorts data with integer keys by grouping the keys by the individual digits which share the same significant position and value. It works by starting from the least significant digit (LSD) and iteratively sorting the elements based on each digit until the most significant digit (MSD). Radix sort is efficient for sorting large numbers of integers and is often used as a subroutine in other sorting algorithms. It can sort integers in linear time, O(nk), where n is the number of integers and k is the number of digits in the integers.

![0011-radix (1)](images/radix_sort.gif)

Here's an example of radix sort being used to sort a list of integers:

Input: [170, 45, 75, 90, 802, 24, 2, 66]

1. Start with the least significant digit (LSD), which is the units digit in this case.
    Sort the numbers based on the units digit: [2, 24, 45, 66, 75, 90, 170, 802]
2. Move on to the next digit to the left, which is the tens digit.
    Sort the numbers based on the tens digit: [2, 24, 45, 66, 75, 90, 170, 802]
3. Repeat the process for the hundreds digit.
    Sort the numbers based on the hundreds digit: [2, 24, 45, 66, 75, 90, 170, 802]
4. Repeat the process for the thousands digit.
    Sort the numbers based on the thousands digit: [2, 24, 45, 66, 75, 90, 170, 802]

Output: [2, 24, 45, 66, 75, 90, 170, 802]

Note that the numbers are sorted in increasing order, starting from the least significant digit.

https://youtu.be/y4rh9o58h8A
https://youtu.be/6YyflHO9GdE


### Quick Sort

Quick sort is a divide-and-conquer algorithm for sorting an array or list of elements. The basic idea is to pick a "pivot" element from the array and partition the other elements into two sub-arrays, according to whether they are less than or greater than the pivot. The sub-arrays are then sorted recursively. Here's an example to illustrate the process:

Imagine a group of people and the goals is to sort them in alphabetical order by their last names. Is possible to use the quicksort algorithm to do this.

1. Choose a pivot person, perhaps the first person in the group.
2. Partition the group into two subgroups: one group with people whose last names come before the pivot person's last name in the alphabet, and another group with people whose last names come after the pivot person's last name in the alphabet.
3. Recursively apply steps 1 and 2 to each subgroup until the subgroups are small enough to be sorted using a simpler algorithm, such as insertion sort.
Concatenate the sorted subgroups in order to obtain the final sorted group.

Another example:

Suppose we have an array [4, 5, 3, 7, 2]. We choose the pivot to be 4. We then partition the rest of the array into two sub-arrays: elements less than 4 [3, 2], and elements greater than 4 [5, 7]. We sort the sub-arrays recursively: [2, 3] and [5, 7]. Finally, we combine the sorted sub-arrays with the pivot to get [2, 3, 4, 5, 7], which is the fully sorted array.

![image](images/quick_sort.png)


The average time complexity of quick sort is O(n log n), where n is the number of elements in the array. This is because, on average, each partition splits the array roughly in half, leading to log n levels of recursion. At each level, O(n) time is spent on partitioning, so the total time complexity is O(n log n). In the worst case, if the pivot is always chosen poorly, such as always choosing the largest or smallest element, the time complexity can degrade to O(n^2). However, this worst case is rare in practice, and can be mitigated by using random pivot selection or other techniques.

https://youtu.be/XE4VP_8Y0BU

### Merge Sort

![image](images/quick_sort.png)

Merge sort is a divide-and-conquer algorithm that sorts an array by recursively dividing the array into smaller sub-arrays, sorting those sub-arrays, and then merging the sub-arrays back together in a sorted manner.

Imagine two stacks of papers with information on them and the goal is to merge them into a single, sorted stack. Is possible to use the merge sort algorithm to do this.

1. Divide each stack into two sub-stacks of approximately equal size.
2. Recursively apply step 1 to each sub-stack until each sub-stack contains only one piece of paper.
3. Merge the sub-stacks pairwise, sorting the papers as you go.
Continue merging pairs of sub-stacks until you have a single sorted stack.

Merge sort has a time complexity of O(n * log n) in the average case and the best case, where n is the number of elements in the array. It is a stable sorting algorithm, meaning that the relative order of equal elements is preserved, and it can sort both ascending and descending.
