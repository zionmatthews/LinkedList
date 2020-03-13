#pragma once

template<typename T>
class Node
{
public:
	//info for the node
	T info;

	//The node that is next
	Node<T> * next;

	//The node that was last
	Node<T> * previous;

	//default deconstructor
	Node();
	~Node();
};

template<typename T>
inline Node<T>::Node()
{

}

template<typename T>
inline Node<T>::~Node() 
{

}