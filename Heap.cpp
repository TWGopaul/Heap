//Programmer: Travis Gopaul
//Date: 11/22/20
//Heap.cpp
//Member definitions for Heap data structure

#include "Heap.h"
#include <iostream>
using namespace std;

//**************** Private Member Definitions *********************
int Heap::parent(int index)	        //return index of parent of i
{
	if(index % 2 == 0)		//if index is even
		return ((index-1)/2);	//parent index = (index-1) / 2
	else
		return (index/2);	//ese index is odd and parent = index / 2;
}//end parent()

int Heap::leftChild(int index)     //return indew of left child of i
{
	return ((2 * index) + 1);	
}//end leftChild()

int Heap::rightChild(int index)    //return index of right child of i
{
	return ((2 * index) + 2);
}//rightChild()

void Heap::heapify(int index)   //builds heap from given index i onward
{
	int largest;			//variable to hold index of largest element in array
	int left = leftChild(index);		//variable to hold index of the left child
	int right = rightChild(index);		//variable to hold index of the right child

	if ((left < heapSize) && (arr[left] > arr[index]))	//if the left child is in the array and is greater than the index of current element
		largest = left;					//set largest = left
	else
		largest = index;				//else  the current element is the largest and in the correct position
	if ((right < heapSize) && (arr[right] > arr[largest]))	//if right child is in array and is the largest
		largest = right;				//set largest equal to the right child

	if(largest != index)					//if index is not in the right position
	{
		swap(arr[index], arr[largest]);		//swap index with the largest and call heapify again
		heapify(largest);
	}//end if
}//end heapify

void Heap::buildHeap()	//builds heap from beginning of array
{
	for(int i = ((heapSize/2)-1); i >=0; i--)		//run heapify from that leaf to the node
		heapify(i);
}//end buildHeap


//**************** Punblic Member Definitions *********************
Heap::Heap()	//Heap constructor
{
	arr[0] = 4;	//populate array wtih default values
	arr[1] = 12;
	arr[2] = 3;
	arr[3] = 19;
	arr[4] = 23;
	arr[5] = 5;
	arr[6] = 32;
	arr[7] = 11;
	arr[8] = 2;
	arr[9] = 24;

	heapSize = 10;	//set initial heap size to 10, the number of elements in array
	buildHeap();	//call buildHeap to build the heap
}//end Heap()

void Heap::insert(int key)          //insert new data in the heap
{
	heapSize += 1;		//increase heap size by 1
	int i = heapSize -1;	//last element in the array

	while ((i > 0) && (arr[parent(i)] < key))	//while heap isn't empty and the current value's parent is less than new value to insert
	{
		arr[i] = arr[parent(i)];		//copy parent value into current position
		i = parent(i);				//move up to the parent to compare where to insert new value
	}//end while

	arr[i] = key;		//copy the key into the right location; copies into 1st position, arr[0], if heap is empty
}//end insert()

void Heap::heapSort()        //sorts array
{
	int originalSize = heapSize;		//need to track original heap size
	buildHeap();		//build heap
	for(int i = heapSize -1; i > 0; i--)
	{
		swap(arr[0], arr[i]);		//swap the root with the last element of the heap
		heapSize -= 1;			//reduce count of heapSize
		heapify(0);			//heapify the array after switch the first and last element; last element not included since size -= 1
	}//end for

	heapSize = originalSize;		//reset heapsize after sorting iteration
}//end heapSort

int Heap::extractMax()      //extract maximum value from the Heap
{
		int max = arr[0];		//root of heap is max value
		arr[0] = arr[heapSize - 1];	//set new root to be last element
		heapSize -= 1;			//reduce heap size by 1
		heapify(0);			//call heapify to set proper order of heap
		return max;			//return the max value
}//end extractMax

int Heap::maximum()         //return the maximum value in the Heap
{
		int max = arr[0];
		return max;
}//end maximum()
void Heap::printHeap()       //print out array in heap format
{
	if(heapSize < 1)	//if heapSize is < 0 display error
		cout << "Error: heap inderflow" << endl;
	else
	{
		for(int i = 0; i < heapSize; i++)	//iterate through array and print values
		{
			cout << arr[i] << "     " ;
		}//end for
	}//end else
	cout << endl;

}//end printHeap()

bool Heap::isEmpty()
{
	return(heapSize < 1 ? true:false);	//return true if heapSize < 1, else false
}//end isEMpty()
