#pragma once
#include "Node.h"

template<typename T>
class Iterator
{
private:
	//variable for node
	Node<T>* currentNode;

public:
	//turns to the  next node in the list
	Iterator<T> operator++(int);

	//turns to the  previous node  in the list
	Iterator<T> operator--(int);

	//gives data
	T operator*();

	//default deconstructor
	Iterator();
	~Iterator();

	//creates a pointer to the current node
	Iterator(Node<T>* ptr);

	//checks for a equal node
	bool operator==(const Iterator<T>&)const;
	//checks for a unequal  node
	bool operator!=(const Iterator<T>&)const;
};


template<typename T>
Iterator<T> Iterator<T>::operator++(int)
{
	
	if (currentNode->next != nullptr)
	{
		currentNode = currentNode->next;
		
		return *this;
	}
	return nullptr;
}


template<typename T>
Iterator<T> Iterator<T>::operator--(int)
{
	
	if (currentNode->previous != nullptr)
	{
		currentNode = currentNode->previous;
		
		return *this;
	}
	return nullptr;
}


template<typename T>
T Iterator<T>::operator*()
{	
	return currentNode->info;
}


template<typename T>
Iterator<T>::Iterator()
{
	currentNode = nullptr;
}


template<typename T>
inline Iterator<T>::~Iterator()
{

}


template<typename T>
Iterator<T>::Iterator(Node<T>* ptr)
{
	currentNode = ptr;
}


template<typename T>
bool Iterator<T>::operator==(const Iterator<T>& currentIterator) const
{
	if (currentNode != nullptr && currentIterator.currentNode != nullptr && &currentNode->info == &currentIterator.currentNode->info) return true;
	else return false;
}

template<typename T>
bool Iterator<T>::operator!=(const Iterator<T>& currentIterator) const
{
	if (currentNode != nullptr && currentIterator.currentNode != nullptr && &currentNode->info != &currentIterator.currentNode->info) return true;
	else return false;
}
