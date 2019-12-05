#pragma once
#include <iostream>

template <class T, class V>
class BSTNode
{
private:
	T key;    
	V value;  
	BSTNode<T, V>* p;
	BSTNode<T, V>* left;
	BSTNode<T, V>* right;
public:

	BSTNode<T, V>(T key, V value);
	BSTNode<T, V>(BSTNode<T, V>* left, BSTNode<T, V>* right, BSTNode<T, V>* parent, T key, V value);

	BSTNode<T, V>* getLeft();
	BSTNode<T, V>* getRight();
	BSTNode<T, V>* getParent();

	void setKey(T key);
	void setValue(V value);

	void setRight(BSTNode<T, V>* b);
	void setLeft(BSTNode<T, V>* b);
	void setParent(BSTNode<T, V>* b);

	bool hasLeft();
	bool hasRight();
	bool hasParent();

	T getKey();
	V getValue();
};
/**
Key-value pair constructor
Pre: key - data to use as key
	 value - data to use as value
Post: BSTNode initialized
Returns: A new BSTNode with no left, right, or parent
**/
template <class T, class V>
BSTNode<T, V>::BSTNode(T key, V value)
{
	p = left = right = nullptr;
	this->key = key;
	this->value = value;
}

/**
Key-value pair constructor
NOTE: Any of the BSTNodes can be nullptr and expected behaviour will be preserved
Pre: key - data to use as key
	 value - data to use as value
	 left - BSTNode to be this node's left
	 right - BSTNode to be this node's right
	 parent - BSTNode to be this node's parent
Post: BSTNode initialized
Returns: A new BSTNode with a defined left, right, or parent
**/
template <class T, class V>
BSTNode<T, V>::BSTNode(BSTNode<T, V>* left, BSTNode<T, V>* right, BSTNode<T, V>* parent, T key, V value)
{
	this->left = left;
	this->right = right;
	p = parent;
	this->key = key;
	this->value = value;
}

/**
Set the right of this node
Pre: b - node to set as right
Post: right = b
Returns:
**/
template <class T, class V>
void BSTNode<T, V>::setRight(BSTNode<T, V>* b)
{
	right = b;
}

/**
Set the left of this node
Pre: b - node to set as left
Post: left = b
Returns:
**/
template <class T, class V>
void BSTNode<T, V>::setLeft(BSTNode<T, V>* b)
{
	left = b;
}

/**
Set the parent of this node
Pre: b - node to set as parent
Post: parent = b
Returns:
**/
template <class T, class V>
void BSTNode<T, V>::setParent(BSTNode<T, V>* b)
{
	p = b;
}

/**
Returns whether this node has a left child
Pre:
Post:
Returns: true if this node has a left child
**/
template <class T, class V>
bool BSTNode<T, V>::hasLeft()
{
	return !left = nullptr;
}

/**
Returns whether this node has a right child
Pre:
Post:
Returns: true if this node has a right child
**/
template <class T, class V>
bool BSTNode<T, V>::hasRight()
{
	return !right = nullptr;
}

/**
Returns whether this node has a parent
Pre:
Post:
Returns: true if this node has a parent (ie. false if it is the root node)
**/
template <class T, class V>
bool BSTNode<T, V>::hasParent()
{
	return !p = nullptr;
}

/**
Return this node's key
Pre:
Post:
Returns: this node's key
**/
template <class T, class V>
T BSTNode<T, V>::getKey()
{
	return key;
}

/**
Return this node's value
Pre:
Post:
Returns: this node's value
**/
template <class T, class V>
V BSTNode<T, V>::getValue()
{
	return value;
}

/**
Returns a pointer to this node's left child
Pre:
Post:
Returns: pointer to this node's right child node
		 nullptr if not initialized
**/
template <class T, class V>
BSTNode<T, V>* BSTNode<T, V>::getLeft()
{
	return left;
}

/**
Returns a pointer to this node's right child
Pre:
Post:
Returns: pointer to this node's right child node
		 nullptr if not initialized
**/
template <class T, class V>
BSTNode<T, V>* BSTNode<T, V>::getRight()
{
	return right;
}

/**
Returns a pointer to this node's parent
Pre:
Post:
Returns: pointer to this node's parent
		 nullptr if root
**/
template <class T, class V>
BSTNode<T, V>* BSTNode<T, V>::getParent()
{
	return p;
}

/**
Sets this node's key
Pre: key - key to set as
Post: key is set to key
Returns:
**/
template <class T, class V>
void BSTNode<T, V>::setKey(T key)
{
	this->key = key;
}

/**
Sets this node's value
Pre: value - value to set as
Post: value is set to value
Returns:
**/
template <class T, class V>
void BSTNode<T, V>::setValue(V value)
{
	this->value = value;
}