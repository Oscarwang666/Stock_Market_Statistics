#pragma once
template<class T>
class LinkNode
{
private:
	T data;
	LinkNode<T>* next;
	bool hasNext;
public:
	LinkNode<T>(T data);
	LinkNode<T>(T data, LinkNode<T>* next);
	T getData();
	bool getHasNext();
	void setHasNext(bool next);
	void setData(T data);
	LinkNode<T>* getNext();
	void setNext(LinkNode<T>* next);
};
/**
Constructor. Creates a linknode with data as the data
Pre: data - any data
Post:
Return: A new LinkNode
*/
template<class T>
LinkNode<T>::LinkNode(T data)
{
	LinkNode::data = data;
	LinkNode::next = nullptr;
	LinkNode::hasNext = false;
}
/**
Constructor. Creates a linknode with data as the data and next as the next
Pre: data - any data
	 next - ptr to another LinkNode
Post:
Return: A new LinkNode with next already set up
*/
template<class T>
LinkNode<T>::LinkNode(T data, LinkNode * next)
{
	this->data = data;
	this->next = next;
	hasNext = true;
}
/**
Sets the next attribute of the linknode
Pre: next - ptr to another LinkNode
Post: this->next = next
*/
template<class T>
void LinkNode<T>::setNext(LinkNode* next)
{
	this->next = next;
	hasNext = true;
}
/**
Gets the data stored in the LinkNode
Pre:
Post:
Return: Data stored in the LinkNode
*/
template<class T>
T LinkNode<T>::getData()
{
	return data;
}
/**
Gets whether the LinkNode has a next node
Pre:
Post:
Return: Whether the LinkNode has a next node
*/
template<class T>
bool LinkNode<T>::getHasNext()
{
	return hasNext;
}
/**
Sets whether the LinkNode has a next or not.
This is usually done automatically but there are edge cases where it is necessary.
Pre: next - boolean whether the node has next or not
Post: hasNext = next
Return:
*/
template<class T>
void LinkNode<T>::setHasNext(bool next)
{
	hasNext = next;
}
/**
Sets the data in the LinkNode.
Pre: data - any data
Post: this->data = data
Return:
*/
template<class T>
void LinkNode<T>::setData(T data)
{
	this->data = data;
}
/**
Gets a pointer to the next node
Pre: Pointer has a next node
Post:
Return: Pointer to next node. If it has no next node, returns nullptr.
*/
template<class T>
LinkNode<T>* LinkNode<T>::getNext()
{
	return next;
}
