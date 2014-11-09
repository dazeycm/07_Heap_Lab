07_HeapLab
==============

Implement a heap in C++

Requirements
------------

1. `add` and `remove` should be O(log n), except for `grow` which can be O(n)
2. Do not leak memory

Reading
=======
"Open Data Structures," Chapter 10, just the intro and section 1. http://opendatastructures.org/ods-cpp/10_Heaps.html

Questions
=========

#### 1. Which of the above requirements work, and which do not? For each requirement, write a brief response.

1. `Add` and `remove` should be O(log n) since we're using calculations to find the left/right children and parents. `grow` is doing its thing at a snails pace.
2. Memory isn't being spilled all over the place.

#### 2. Exercises 10.1 and 10.2 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
10.1 - 3 9 4 17 26 8 6 19 69 32 93 55 50 16 7
10.2 - 9 17 16 19 26 50 55 55 93 69 32

#### 3. Exercise 10.4 from http://opendatastructures.org/ods-cpp/10_3_Discussion_Exercises.html
The child can be found using the equation d * i + number of which child you want (1 for far left, 2 for second... d for far right)
The parent can be found using the equation (i - 1)/d

#### 4. What is one question that confused you about this exercise, or one piece of advice you would share with students next semester?

There is a swap method that will swap two pairs, so you don't have to create one yourself. Also, make sure you're comparing the first value in each pair. There is a way to access it in the pair class. 
