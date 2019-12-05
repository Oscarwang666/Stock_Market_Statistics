#pragma once
#include "SinglyLinkedList.h"

template <class T>
class Queue :
	protected SinglyLinkedList<T>
{
public:
	void enqueue(T data);
	T dequeue();
	T getFront();
	T getRear();
	void empty();
	int getCount();
	Queue();
	Queue(T* array, int arraySize);
	Queue(T fill, const int count);
	template<class T>
	friend std::ostream& operator << (std::ostream& os, Queue<T>& q);
};

/**
Constructors: implement parent class's constructors
*/
template <class T>
Queue<T>::Queue() : SinglyLinkedList<T>() {}

template <class T>
Queue<T>::Queue(T* array, int arraySize) : SinglyLinkedList<T>(array, arraySize) {}

template <class T>
Queue<T>::Queue(T fill, const int count) : SinglyLinkedList<T>(fill, count) {}

/**
Adds an element to the back of the queue
Pre: data - data to add to the queue
Post: Element is added to the end of the queue
Returns:
*/
template<class T>
void Queue<T>::enqueue(T data)
{
	SinglyLinkedList<T>::addData(data);
}

/**
Removes the front element from the queue
Pre: Queue is not empty
Post: Element is removed from the queue
Returns: Element removed from the queue
*/
template<class T>
T Queue<T>::dequeue()
{
	T data = SinglyLinkedList<T>::getData(0);
	SinglyLinkedList<T>::deleteData(0);
	return data;
}

/**
Gets the data at the front of the queue
Pre: Non-empty queue
Post:
Returns: Element at the front of the queue
*/
template <class T>
T Queue<T>::getFront()
{
	return SinglyLinkedList<T>::getData(0);
}

/**
Gets the data at the back of the queue
Pre: Non-empty queue
Post:
Returns: Element at the back of the queue
*/
template <class T>
T Queue<T>::getRear()
{
	return SinglyLinkedList<T>::getData(SinglyLinkedList::count - 1);
}

/**
Empties the queue
Pre:
Post: Queue is empty
Returns:
*/
template<class T>
void Queue<T>::empty()
{
	SinglyLinkedList<T>::emptyList();
}

/**
The size of the queue
Pre:
Post:
Returns: The size of the queue
*/
template<class T>
int Queue<T>::getCount()
{
	return SinglyLinkedList<T>::getCount();
}

/**
Prints the list in a nice fashion
Pre:
Post:
Return: std::ostream
*/
template<class T>
std::ostream& operator << (std::ostream& os, Queue<T>& q)
{
	if (q.getCount() > 0)
	{
		for (int i = 0; i < q.getCount() - 1; i++)
		{
			os << q.getData(i) << " <-- ";
		}
		os << q.getData(q.getCount() - 1);
	}
	return os;
}