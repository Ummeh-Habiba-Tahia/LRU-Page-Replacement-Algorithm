# LRU-Page-Replacement-Algorithm
##Description:

This code implements the LRU (Least Recently Used) page replacement algorithm in C++. The LRU algorithm is used in operating systems for memory management, specifically for managing the pages in a page frame when there are page faults.

Code Breakdown:

1.Include Statements and Namespace:

#include <iostream>: for input and output operations.
#include <list>: to use the std::list container.
#include <vector>: to use the std::vector container.
#include <unordered_map>: to use the std::unordered_map container.
The using namespace std; directive allows the use of standard library names without the std:: prefix.

2.LRU Function:

The lru function takes two parameters: a vector of integers pages representing the sequence of pages to be loaded, and an integer capacity representing the number of page frames available in memory.
A list<int> named lruList is used to store page numbers in the order of their recent use, with the most recently used page at the front and the least recently used page at the back.
An unordered_map<int, list<int>::iterator> named pageMap is used to store page numbers and their corresponding iterators in the list for quick access and update.
An integer pageFaults is initialized to zero to keep track of the number of page faults.

3.Page Replacement Logic:

The function iterates over each page in the pages vector.
If a page is not in the unordered_map pageMap (indicating a page fault):
    If the list lruList is full (i.e., its size equals the capacity), the least recently used page (the back of the list) is removed from both the list lruList and the map pageMap.
    The new page is then added to the front of the list lruList and its iterator is stored in the map pageMap.
    The pageFaults counter is incremented.
If the page is already in the map, it is moved to the front of the list to mark it as the most recently used by:
    Removing its current position in the list using the iterator from the map.
    Adding it to the front of the list.
    Updating its iterator in the map.
    
4.Main Function:

An example sequence of page requests is stored in the pages vector.
The capacity of the page frames is set to 3.
The lru function is called with the pages vector and capacity.
The total number of page faults is printed to the console.

Example Execution:
Given the example page sequence {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 0, 3, 2, 1, 2, 0, 1, 7, 0, 1} and a capacity of 3 page frames, the LRU algorithm will determine how many page faults occur as pages are loaded into memory.

Output:

Total page faults using LRU: 15
