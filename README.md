# Simple Heap

> For this micro assignment, you must implement the following function found inside Heap.h.
> > Note that our heap is a min-heap (smallest items at the top)!

* void adjustHeap(int index)

> This function causes the item at the supplied index to "percolate down" the heap until the min-heap property is satisfied. Adjust heap is called on deleteMin operations; see the deleteMin function inside Heap class to see how adjustHeap is called. 

> Note that we're being good programmers and allowing the heap to percolate down at any point, not just the root! Doing so allows us to evoke the percolate down functionality in other situations (e.g. buildHeap).

# Grading
> Your submission will be graded based on the following:

* [10] Your solution builds, does not cause any runtime issues, and passes all test cases

=====
10/10
=====