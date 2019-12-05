#pragma once
#include "LinkNode.h"
#include <iostream>
//SortType enum for use in the getSortType() function
enum SortType
{
	UNSORTED,
	ASCENDING,
	DESCENDING,
	BOTH
};

template<class T>
class SinglyLinkedList
{
private:
	int count;
	LinkNode<T>* head;
	LinkNode<T>* tail;
public:

	void newList(T fill, const int count);
	void addData(T data);
	void addData(T data, int index);
	void deleteData(int index);
	T getData(int index);
	int findIndex(T data);
	int getCount();
	void emptyList();

	SortType getSortType();

	SinglyLinkedList();
	SinglyLinkedList(T* array, const int arraySize);
	SinglyLinkedList(T fill, const int count);
	~SinglyLinkedList();
	template<class T>
	friend std::ostream& operator << (std::ostream& os, const SinglyLinkedList<T>& l);

	T operator[] (int index);
};

/**
Constructor. Creates an empty SinglyLinkedList
Pre:
Post: empty SinglyLinkedList
Return: empty SinglyLinkedList
*/
template<class T>
SinglyLinkedList<T>::SinglyLinkedList()
{
	count = 0;
	head = nullptr;
	tail = nullptr;
}

/**
Constructor. Creates a SinglyLinkedList from an array
Pre: array - array pointer
	 arraySize - size of array
Post: SinglyLinkedList initialized with elements of the array
Return: SinglyLinkedList with elements of the array
*/
template<class T>
SinglyLinkedList<T>::SinglyLinkedList(T* array, const int arraySize)
{
	if (arraySize == 1)
		head = tail = new LinkNode<T>(array[0]);
	else
	{
		head = new LinkNode<T>(array[0]);
		LinkNode<T>* prev = head;
		for (int i = 1; i < arraySize; i++)
		{
			LinkNode<T>* cur = new LinkNode<T>(array[i]);
			prev->setNext(cur);
			prev = cur;
		}
		tail = prev;
	}
	count = arraySize;
}

/**
Constructor. Creates a SinglyLinkedList filled with a single data
Pre: fill - any data
	 count - amount to fill
Post: SinglyLinkedList initialized filled with a single data
Return: SinglyLinkedList filled with a single data
*/
template<class T>
SinglyLinkedList<T>::SinglyLinkedList(T fill, const int count)
{
	LinkNode<T>* l = head;
	LinkNode<T>* n = nullptr;
	for (int i = 0; i < count; i++)
	{
		if (l->getHasNext())
			n = l->getNext();
		delete l;
		l = n;
	}
	if (count == 1)
		head = tail = new LinkNode<T>(fill);
	else
	{
		head = new LinkNode<T>(fill);
		LinkNode<T>* prev = head;
		for (int i = 1; i < count; i++)
		{
			LinkNode<T>* cur = new LinkNode<T>(fill);
			prev->setNext(cur);
			prev = cur;
		}
		tail = prev;
	}
	SinglyLinkedList::count = count;
}

/**
Destructor
Pre:
Post: LinkedList is destroyed. All LinkNodes are deleted. head and tail are set to nullptr
Return:
*/
template<class T>
SinglyLinkedList<T>::~SinglyLinkedList()
{
	LinkNode<T>* l = head;
	LinkNode<T>* n = nullptr;
	for (int i = 0; i < count; i++)
	{
		if (l->getHasNext())
			n = l->getNext();
		delete l;
		l = n;
	}
}

/**
Creates a SinglyLinkedList filled with a single data. Overrides the current SinglyLinkedList.
Pre: fill - any data
	 count - amount to fill
Post: SinglyLinkedList initialized filled with a single data
Return:
*/
template<class T>
void SinglyLinkedList<T>::newList(T fill, const int count)
{
	LinkNode<T>* l = head;
	LinkNode<T>* n = nullptr;
	for (int i = 0; i < count; i++)
	{
		if (l->getHasNext())
			n = l->getNext();
		delete l;
		l = n;
	}
	if (count == 1)
		head = tail = new LinkNode<T>(fill);
	else
	{
		head = new LinkNode<T>(fill);
		LinkNode<T>* prev = head;
		for (int i = 1; i < count; i++)
		{
			LinkNode<T>* cur = new LinkNode<T>(fill);
			prev->setNext(cur);
			prev = cur;
		}
		tail = prev;
	}
	SinglyLinkedList::count = count;
}

/**
Adds data to the end of the list
Pre: data - any data
Post: count is increased by 1. Tail is set to the new data. The new data is added to the list.
Return:
*/
template<class T>
void SinglyLinkedList<T>::addData(T data)
{
	if (count == 0)
		head = tail = new LinkNode<T>(data);
	else
	{
		LinkNode<T>* n = new LinkNode<T>(data);
		tail->setNext(n);
		tail = n;
	}
	count++;
}

/**
Inserts before given index
Pre: data - any data
	 index - where to insert the array. < count
Post: count is increased by 1. The new data is added to the list at the given index.
Return:
*/
template<class T>
void SinglyLinkedList<T>::addData(T data, int index)
{
	if (count == 0 && index == 0)
	{
		head = tail = new LinkNode<T>(data);
		count++;
	}
	else if (index >= count)
		throw("Index out of bounds!");
	else if (index == 0)
	{
		LinkNode<T>* n = new LinkNode<T>(data);
		n->setNext(head);
		head = n;
		count++;
	}
	else if (index == count - 1)
	{
		LinkNode<T>* n = new LinkNode<T>(data);
		tail->setNext(n);
		tail = n;
		count++;
	}
	else
	{
		LinkNode<T>* n = new LinkNode<T>(data);
		LinkNode<T>* c = head;
		for (int i = 1; i < index; i++)
			c = c->getNext();
		n->setNext(c->getNext());
		c->setNext(n);
		count++;
	}
}

/**
Deletes data at given index
Pre: index - where to delete the data from
Post: count is decreased by 1. The data at the index is removed from the list
Return:
*/
template<class T>
void SinglyLinkedList<T>::deleteData(int index)
{
	if (index >= count)
		throw("Index out of bounds!");
	else if (count == 1)
	{
		delete head;
		head = tail = nullptr;
		count = 0;
	}
	else if (index == 0)
	{
		LinkNode<T>* c = head;
		head = head->getNext();
		delete c;
		count--;
	}
	else if (index < count - 1)
	{
		LinkNode<T>* c = head;
		LinkNode<T>* n;
		for (int i = 1; i < index; i++)
			c = c->getNext();
		n = c->getNext();
		c->setNext(n->getNext());
		delete n;
		count--;
	}
	else
	{
		delete tail;
		LinkNode<T>* c = head;
		for (int i = 2; i < count; i++)
			c = c->getNext();
		tail = c;
		c->setHasNext(false);
		count--;
	}
}

/**
Gets the data of a node at a given index
Pre: an initailized list
	 index - index to get the data from
Post:
Return: data at given index
*/
template<class T>
T SinglyLinkedList<T>::getData(int index)
{
	if (index >= count)
		throw("Index out of bounds!");
	LinkNode<T>* n = head;
	for (int i = 0; i < index; i++)
		n = n->getNext();
	return n->getData();
}

/**
Gets the index of a node with the given data
Pre: an initailized list
	 data - any data to search for in the list
Post:
Return: index of given data
		-1 if data is not found
*/
template<class T>
int SinglyLinkedList<T>::findIndex(T data)
{
	LinkNode<T>* n = head;
	for (int i = 0; i < count; i++)
	{
		if (n->getData() == data)
			return i;
		n = n->getNext();
	}
	return -1;
}

/**
Gets the count of the list
Pre:
Post:
Return: the count of the list
*/
template<class T>
int SinglyLinkedList<T>::getCount()
{
	return count;
}

/**
Empties the list
Pre:
Post: The list is empty
Return:
*/
template<class T>
void SinglyLinkedList<T>::emptyList()
{
	if (count == 0)
		return;
	if (count == 1)
	{
		delete head;
		count = 0;
		return;
	}
	LinkNode<T>* cur = head;
	LinkNode<T>* next = head->getNext();
	while (cur->getHasNext())
	{
		delete cur;
		cur = next;
		next = next->getNext();
	}
	head = tail = nullptr;
	count = 0;
}

/**
Gets the SortType of the list
Pre:
Post:
Return: a SortType
*/
template<class T>
SortType SinglyLinkedList<T>::getSortType()
{
	if (count > 1)
	{
		bool desc = true;
		bool asc = true;

		LinkNode<T>* n = head->getNext();
		T prev = head->getData();
		T cur = n->getData();
		while (n->getHasNext())
		{
			if (prev > cur)
				asc = false;
			if (prev < cur)
				desc = false;
			n = n->getNext();
			prev = cur;
			cur = n->getData();
		}
		if (desc && asc)
			return SortType::BOTH;
		if (desc)
			return SortType::DESCENDING;
		if (asc)
			return SortType::ASCENDING;
		return SortType::UNSORTED;
	}
	return SortType::BOTH;
}

/**
Gets the data at a given index
Pre: an initialized list
	 index - where to look for the data
Post:
Return: data at the given index
*/
template<class T>
T SinglyLinkedList<T>::operator[] (int index)
{
	if (index >= count)
		throw("Index out of bounds!");
	return getData(index);
}

/**
Prints the list in a nice fashion
Pre:
Post:
Return: std::ostream
*/
template<class T>
std::ostream& operator << (std::ostream& os, const SinglyLinkedList<T>& l)
{
	if (l.count > 0)
	{
		LinkNode<T> cur = *l.head;
		char arrow = 175;
		while (cur.getHasNext())
		{
			os << cur.getData() << " --> ";
			cur = *cur.getNext();
		}
		os << cur.getData();
	}
	return os;
}