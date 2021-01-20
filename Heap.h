//Programmer: Travis Gopaul
//Date: 11/22/20
//Heap.h
//Header file for heap data structure

#ifndef HEAP_H
#define HEAP_H

class Heap
{
	private:
		int arr[100]={};	//maximum space for heap
		int heapSize;		//sixe of heap

		int parent(int);	//return index of parent of i
		int leftChild(int);	//return indew of left child of i
		int rightChild(int);	//return index of right child of i
		void heapify(int);	//builds heap from given index i onward
		void buildHeap();	//builds heap from beginning of array
	
	public:
		Heap();			//Heap constructor
		void insert(int);	//insert new data in the heap
		void heapSort();	//sorts array
		int extractMax();	//extract maximum value from the Heap
		int  maximum();		//return the maximum value in the Heap
		void printHeap();	//print out array in heap format
		bool isEmpty();		//determine if heap is empty
};

#endif
