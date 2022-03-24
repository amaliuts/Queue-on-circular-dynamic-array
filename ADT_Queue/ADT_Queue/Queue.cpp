#include "Queue.h"
#include <exception>
#include <iostream>

using namespace std;


Queue::Queue() {									//Default Constructor
	this->front = this->rear = -1;
	this->capacity = 20;
	this->q = new TElem[this->capacity];
}
//Theta(1)

Queue::Queue(int size) {							//Parameter constructor
	this->front = this->rear = -1;
	this->capacity = size;
	this->q = new TElem[this->capacity];
}
//Theta(1)

Queue::Queue(const Queue& Q) {						//Copy Constructor
	this->front = Q.front;
	this->rear = Q.rear;
	this->capacity = Q.capacity;
}
//Theta(1)

void Queue::push(TElem elem) {
	if (isFull())
		resize();
	else
		if (isEmpty())
			this->front++;
	this->rear = (this->rear + 1) % this->capacity;
	this->q[this->rear] = elem;
}

TElem Queue::pop() {
	if (isEmpty())
		throw exception();
	TElem popped_elem = this->q[this->front];

	if (this->front == this->rear)						// checks if there is only one element in the queue
		this->front = this->rear = -1;					//empties the queue
	else
		this->front = (this->front + 1) % this->capacity;	//increment the front index to the next position

	return popped_elem;

	//to do downsizing
}
//Theta(1)


TElem Queue::top() const {
	if (isEmpty())
		throw exception();
	return this->q[this->front];
}
//Theta(1)

bool Queue::isEmpty() const {
	return (this->front == -1);
}
//Theta(1)

bool Queue::isFull() const {
	return ((this->rear + 1) % this->capacity == this->front);
}
//Theta(1)

void Queue::resize() {
	TElem* newQueue = new TElem[this->capacity * 2];
	int i = 0, j = this->front;
	do {
		newQueue[i++] = this->q[j];
		j = (j + 1) % this->capacity;
	} while (j != this->front);

	delete[] this->q;
	this->front = 0;
	this->rear = this->capacity - 1;
	this->q = newQueue;
	this->capacity *= 2;
}
//O(this->capacity)

Queue Queue::operator=(const Queue& Q) {		//Assignment Operator
	this->front = Q.front;
	this->rear = Q.rear;
	this->capacity = Q.capacity;
	return *this;
}
//Theta(1)


Queue::~Queue() {								//Destructor
	delete[] this->q;
}
//Theta(1)

