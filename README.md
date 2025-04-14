
# C++ Data Structures Library

This repository contains a C++ implementation of three fundamental data structures: **Singly Linked List**, **Doubly Linked List**, and **Dynamic Array**. Each data structure is implemented as a templated class, allowing for flexible use with any data type. The project includes a comprehensive test suite to verify the functionality of each data structure. It is designed to be lightweight, easy to understand, and suitable for educational purposes or as a foundation for more complex applications.

## Features

- **Singly Linked List (`LinkedList`)**: A linear collection of nodes where each node points to the next. Supports operations like adding/removing elements at the beginning, end, or specific index, finding elements, and printing the list.
- **Doubly Linked List (`DoubleLinkedList`)**: Similar to the singly linked list but with bidirectional traversal, as each node points to both the next and previous nodes. Includes the same operations as the singly linked list.
- **Dynamic Array (`DynamicArray`)**: A resizable array that automatically doubles in capacity when full. Supports adding/removing elements at the beginning, end, or specific index, finding elements, and printing the array.
- **Test Suite**: A `main.cpp` file with test scenarios for each data structure, using assertions to verify correctness.

## Files

- `LinkedList.h`: Implementation of the singly linked list.
- `DoubleLinkedList.h`: Implementation of the doubly linked list.
- `DynamicArray.h`: Implementation of the dynamic array.
- `main.cpp`: Test suite for all data structures, demonstrating their functionality.


## Supported Operations

For all data structures:
- `addToFirst(T data)`: Add an element to the beginning.
- `addToLast(T data)`: Add an element to the end.
- `addToIndex(T data, int index)`: Add an element at a specific index.
- `removeFromFirst()`: Remove the first element.
- `removeFromLast()`: Remove the last element.
- `removeFromIndex(int index)`: Remove an element at a specific index.
- `findElement(T element)`: Return the index of the first occurrence of an element, or -1 if not found.
- `print()`: Print all elements.



This project is licensed under the BeerWare License. See the https://pl.wikipedia.org/wiki/Beerware for details.
