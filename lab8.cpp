//Programmer: Travis Gopaul
//Date: 11/23/20
//lab8.cpp
//Driver program for Heap data structure

#include "Heap.h"
#include <iostream>

using namespace std;

int main()
{
	char menuSelection;
	Heap heap;		//heap object created with default values
do
{
	cout << "Integer Heap Program" << endl;
	cout << "====================" << endl;
	cout << "1. Insert element into the heap" << endl;
	cout << "2. Maximum value" << endl;
	cout << "3. Extract maximum element from the heap" << endl;
	cout << "4. Print heap" << endl;
	cout << "5. Heap sort, print sorted results and exit" << endl;

	cin >> menuSelection;

	while(menuSelection < '1' && menuSelection > '5')	//input validation
	{
		cout << "Please make valid selection." << endl;
		cin >> menuSelection;
	}//end while

	if(menuSelection == '1')
	{
		system("clear");
		int value;	//variable to store user input
		cout << "Enter value to insert into the heap:" << endl;
		cin >> value;	//store user input 
		heap.insert(value);	//call insert function passing user input as parameter
	}//end if 1

	if(menuSelection == '2')
        {
		system("clear");
		if(heap.isEmpty())
                	cout << "Error, heap underflow" << endl;
		else
			cout << "The maximum value in the heap is: " << heap.maximum() << endl; //call maximum function that returns max value in the heap
	}//end if 2

        if(menuSelection == '3')
        {
		system("clear");
		if(heap.isEmpty())
			cout << "Error, heap underflow" << endl;
		else
			cout << heap.extractMax() << " has been extracted from the heap" << endl;
	}//end if 3

        if(menuSelection == '4')
        {
		system("clear");
		heap.printHeap();
	}//end if 4

}//end do
while(menuSelection != '5');	//end do while 

heap.heapSort();//when 5 is selected, call heap sort, print list and exit.
heap.printHeap();

return 0;
}//end main
