//***************************************************************************//
//**
//**  Simple Heap implementation - With solution
//**    Copyright 2016 - Aaron S. Crandall
//** 
//** Lucy Tran
//** 10-24-16
//** Microassignment 4
//** Changed: AdjustHeap
//***************************************************************************//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
#include <vector>
#include <stdexcept>      // std::out_of_range
using namespace std;

template<typename T>
class Heap
{
private:
	vector<T> _items;

	void buildHeap()
	{
		for (int i = _items.size() / 2; i >= 0; i--)
		{
			adjustHeap(i);
		}
	}


	//Percolates the item specified at by index down into its proper location within a heap.
	// Used for dequeue operations and array to heap conversions
	void adjustHeap(int index)
	{
		int leftChildIndex = index * 2 + 1;
		int rightChildIndex = index * 2 + 2;
		int newIndex = 0;
		
		//End of heap, right child not found
		if (rightChildIndex >= _items.size() && leftChildIndex >= _items.size()) {
			return;
		}
		//Left child found = Last child
		else if (rightChildIndex >= _items.size() && leftChildIndex < _items.size()) {
				newIndex = leftChildIndex;
		}

		//Not at the end of the heap: obtain the child with the minimum value
		else if (rightChildIndex < _items.size()) {
			//Left child value <= right child value
			if (_items[leftChildIndex] <= _items[rightChildIndex]) {
				newIndex = leftChildIndex; //Lesser child
			}
			//Left child value > right child value
			else {
				newIndex = rightChildIndex; //Lesser child
			}
		}

		//We want the minimum value at the top
		//If Current item > lesser of the two children
			//Swap
		if (_items[index] > _items[newIndex]) {
			T temp = 0;

			temp = _items[newIndex]; //Put value of lesser child into temp
			/*Swap items*/
			_items[newIndex] = _items[index]; //Current item bubbled down
			_items[index] = temp; //lesser of the two children moved up

			adjustHeap(newIndex); //Repeat until properties of heap satisfied
		}
	}


public:
	Heap()
	{
	}

	Heap(const vector<T> &unsorted)
	{
		for (int i = 0; i < unsorted.size(); i++)
		{
			_items.push(unsorted[i]);
		}
		buildHeap();
	}

	//Adds a new item to the heap
	void insert(T item)
	{

		//calculate positions
		int current_position = _items.size();
		int parent_position = (current_position - 1) / 2;

		//insert element (note: may get erased if we hit the WHILE loop)
		_items.push_back(item);

		//get parent element if it exists
		T *parent = nullptr;
		if (parent_position >= 0)
		{
			parent = &_items[parent_position];
		}

		//only continue if we have a non-null parent
		if (parent != nullptr)
		{
			//bubble up
			while (current_position > 0 && item < *parent)
			{
				_items[current_position] = *parent; //swap
				current_position = parent_position; //position changed
				parent_position = (current_position - 1) / 2;
				if (parent_position >= 0)
				{
					parent = &_items[parent_position]; //pointer
				}
			}

			//after finding the correct location, we can finally place our item
			_items[current_position] = item;
		}
	}


	//Returns the top-most item in our heap without actually removing the item from the heap
	T& getFirst()
	{
		if (size() > 0)
			return _items[0];
		else
			throw std::out_of_range("No elements in Heap.");
	}


	//Removes the top-most item from the heap and returns it to the caller
	T deleteMin()
	{
		int last_position = _items.size() - 1;
		T last_item = _items[last_position];
		T top = _items[0]; //temp for first item
		_items[0] = last_item;
		_items.erase(_items.begin() + last_position);

		//percolate down
		adjustHeap(0);
		return top;
	}


	// Returns true if heap is empty, false otherwise
	bool isEmpty() const
	{
		return _items.size() == 0;
	}


	// Return size (N) of the Heap
	int size() const
	{
		return _items.size();
	}

	// Simple debugging print out
	void printAll() const
	{
		for (int i = 0; i < _items.size(); i++)
		{
			cout << "  [x] Heap element [" << i << "]. key=" << _items[i] << endl;
		}
	}
};

#endif
