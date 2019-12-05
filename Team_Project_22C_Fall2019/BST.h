#pragma once
#include "BSTNode.h"
#include "Queue.h"
template <class T, class V>
class BST
{
private:
	BSTNode<T, V>* findMin(BSTNode<T, V>* start);
	BSTNode<T, V>* root = nullptr;
	BSTNode<T, V>* insert(T key, V value, BSTNode<T, V>* start, bool* successFlag);
	BSTNode<T, V>* remove(T key, BSTNode<T, V>* start, bool* successFlag);

	void printPreOrder(BSTNode<T, V>* start);
	void printPostOrder(BSTNode<T, V>* start);
	void printInOrder(BSTNode<T, V>* start);
	void prettyPrint(BSTNode<T, V>* start, int level);

	V search(T key, BSTNode<T, V>* start);

public:
	void printPreOrder();
	void printPostOrder();
	void printInOrder();
	void prettyPrint();

	bool insert(T key, V value);
	bool remove(T key);
	V search(T key);
};
/**
Internal helper to act as a recursive function for insert
Pre: key - key to insert
	 value - value to insert
	 start - recursive start point
	 successFlag - pointer to a boolean to show whether the insertion was successful
Post: The key is inserted in the correct position
Returns: the root node
**/
template <class T, class V>
BSTNode<T, V>* BST<T, V>::insert(T key, V value, BSTNode<T, V>* start, bool* successFlag)
{
	*successFlag = false;
	if (start == nullptr)
	{
		*successFlag = true;
		return new BSTNode<T, V>(key, value);
	}
	else if (key < start->getKey())
		start->setLeft(insert(key, value, start->getLeft(), successFlag));
	else
		start->setRight(insert(key, value, start->getRight(), successFlag));

	return start;
}
/**
Preorder recursive helper
Pre: o - ostream to print to
	 start - recursive start point
Post:
Returns:
**/
template <class T, class V>
void BST<T, V>::printPreOrder(BSTNode<T, V>* start)
{
	if (start != nullptr)
	{
		std::cout << start->getKey() << " " << start->getValue() << "\n";
		printPreOrder(start->getLeft());
		printPreOrder(start->getRight());
	}
}
/**
Postorder recursive helper
Pre: o - ostream to print to
	 start - recursive start point
Post:
Returns:
**/
template <class T, class V>
void BST<T, V>::printInOrder(BSTNode<T, V>* start)
{
	if (start != nullptr)
	{
		printInOrder(start->getLeft());
		std::cout << start->getKey() << " " << start->getValue() << "\n";
		printInOrder(start->getRight());
	}
}
/**
Inorder recursive helper
Pre: o - ostream to print to
	 start - recursive start point
Post:
Returns:
**/
template <class T, class V>
void BST<T, V>::printPostOrder(BSTNode<T, V>* start)
{
	if (start != nullptr)
	{
		printPostOrder(start->getLeft());
		printPostOrder(start->getRight());
		std::cout << start->getKey() << " " << start->getValue() << "\n";
	}
}
/**
Inorder recursive helper
Pre: o - array of pointers to ostreams to print to
	 start - recursive start point
Post:
Returns:
**/
template <class T, class V>
void BST<T, V>::printInOrder()
{
	printInOrder(root);
}
/**
Inorder recursive helper
Pre: o - array of pointers to ostreams to print to
	 start - recursive start point
Post:
Returns:
**/
template <class T, class V>
void BST<T, V>::printPostOrder()
{
	printPostOrder(root);
}
/**
Print preorder
Pre: o - ostream to print to
Post:
Returns:
**/
template <class T, class V>
void BST<T, V>::printPreOrder()
{
	printPreOrder(root);
}
/**
Finds inorder predecessor
Pre: start - location to start search
Post:
Returns: pointer to inorder predecessor
**/
template <class T, class V>
BSTNode<T, V>* BST<T, V>::findMin(BSTNode<T, V>* start)
{
	BSTNode<T, V>* b = start;
	while (b != nullptr && b->getLeft() != nullptr)
		b = b->getLeft();

	return b;
}
/**
Inserts k-v pair
Pre: key - key to insert
	 value - value to insert
Post: k-v pair is inserted in the correct spot
Return: true if success
**/
template <class T, class V>
bool BST<T, V>::insert(T key, V value)
{
	bool success = false;
	root = insert(key, value, root, &success);
	return success;
}

/**
Searches for an item in the tree
Pre: key - key to search for
Post:
Returns: true if key found in tree
**/
template <class T, class V>
V BST<T, V>::search(T key)
{
	return search(key, root);
}
/**
Print the BST in a tree-like format
Pre:  a start node and an interger for trackking the tree's level
Post: recursivlly call it self and display data in a tree-like format
Returns: 
**/
template<class T, class V>
void BST<T, V>::prettyPrint(BSTNode<T, V>* start, int level)
{
	if (start != nullptr)
	{
		if (level == 1)
			std::cout << (char)195 << std::string(2, (char)196);
		else if (level > 1)
		{
			for (int i = 0; i < level - 1; i++)
				std::cout << (char)179 << "   ";
			std::cout << (char)192 << std::string(2, (char)196);
		}
		std::cout << start->getKey() << " " << start->getValue() << "\n";
		prettyPrint(start->getLeft(), level + 1);
		prettyPrint(start->getRight(), level + 1);
	}

}

template<class T, class V>
void BST<T, V>::prettyPrint()
{
	prettyPrint(root, 0);
}
/**
Removes an item in the tree
Pre: key - key to remove
Post: key is removed
Returns: true if key successfully removed
**/
template <class T, class V>
bool BST<T, V>::remove(T key)
{
	bool success = false;
	remove(key, root, &success);
	return success;
}
/**
Recursive helper to search
Pre: key - key to search for
	 start - recursive start point
Post:
Returns: true if key found in tree
**/
template <class T, class V>
V BST<T, V>::search(T key, BSTNode<T, V>* start)
{
	if (start == nullptr)
		return NULL;
	if (start->getKey() == key)
		return start->getValue();
	if (key < start->getKey())
		return search(key, start->getLeft());
	return search(key, start->getRight());
}
/**
Recursive helper to remove
Pre: key - key to remove
	 start - recursive start point
	 successFlag - pointer to fool, true if success
Returns: root node
**/
template <class T, class V>
BSTNode<T, V>* BST<T, V>::remove(T key, BSTNode<T, V>* start, bool* successFlag)
{
	if (start == nullptr)
		return start;

	if (key < start->getKey())
		start->setLeft(remove(key, start->getLeft(), successFlag));
	else if (key > start->getKey())
		start->setRight(remove(key, start->getRight(), successFlag));
	else
	{
		bool isRoot = start == root;
		if (start->getLeft() == nullptr)
		{
			BSTNode<T, V>* b = start->getRight();
			delete start;
			start = nullptr;
			if (isRoot)
				root = b;
			return b;
		}
		else if (start->getRight() == nullptr)
		{
			BSTNode<T, V>* b = start->getLeft();
			delete start;
			start = nullptr;
			if (isRoot)
				root = b;
			return b;
		}
		BSTNode<T, V>* b = findMin(start->getRight());
		start->setKey(b->getKey());
		start->setValue(b->getValue());
		start->setRight(remove(b->getKey(), start->getRight(), successFlag));
	}
	return start;
}

