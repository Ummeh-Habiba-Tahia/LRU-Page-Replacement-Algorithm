#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

// Function to implement LRU page replacement algorithm
int lru(vector<int>& pages, int capacity) {
    list<int> lruList; // List to store page numbers in order of their recent use
    unordered_map<int, list<int>::iterator> pageMap; // Map to store page numbers and their corresponding iterators in the list
    int pageFaults = 0; // Counter to track page faults

    // Traverse through each page
    for (int page : pages) {
        // If page is not in memory
        if (pageMap.find(page) == pageMap.end()) {
            // If memory is full, remove the least recently used page
            if (lruList.size() == capacity) {
                int lruPage = lruList.back();
                lruList.pop_back();
                pageMap.erase(lruPage);
            }
            // Add the new page to memory and mark it as the most recently used
            lruList.push_front(page);
            pageMap[page] = lruList.begin();
            pageFaults++;
        } else {
            // If page is already in memory, move it to the front of the list to mark it as the most recently used
            lruList.erase(pageMap[page]);
            lruList.push_front(page);
            pageMap[page] = lruList.begin();
        }
    }
    return pageFaults;
}

int main() {
    // Example usage
    vector<int> pages = {7, 0, 1, 2, 0, 3, 0, 4, 2, 3, 0, 3, 0, 3, 2, 1, 2, 0,1, 7, 0, 1 };
    int capacity = 3; // Number of frames

    int pageFaults = lru(pages, capacity);

    cout << "Total page faults using LRU: " << pageFaults << endl;

    return 0;
}

