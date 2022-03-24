#pragma once
#include <vector>
using namespace std;

//DO NOT CHANGE THIS PART
typedef int TElem;
#define NULL_TELEM -11111

class Queue
{
private:
	int front, rear;
	int capacity;

	TElem* q;


public:
	
	//default constructor
	Queue();

	//parameter constructor
	Queue(int size);

	//copy constructor
	Queue(const Queue& Q);

	//pushes an element to the end of the queue
	void push(TElem e);

	//returns the element from the front of the queue
	//throws exception if the queue is empty
	TElem top() const;

	//removes and returns the element from the front of the queue
	//throws exception if the queue is empty
	TElem pop();

	//checks if the queue is empty
	bool isEmpty() const;

	//checks if the queue is full
	bool isFull() const;

	//resizes the queue if it is full
	void resize();

	//assignment operator
	Queue operator=(const Queue& Q);

	// destructor
	~Queue();
};
