#pragma once

template<typename T>
class Node
{
public:

	T info;

	Node<T> * next;
	Node<T> * previous;

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