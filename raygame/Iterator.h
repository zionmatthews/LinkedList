#pragma once
#include "Node.h"
template<typename T>
class Iterator
{
private:

	Node<T>* currentNode;

public:

	Iterator();
	~Iterator();
	Iterator(Node<T>* ptr);
	T operator*();
	Iterator<T> operator++(int);
	Iterator<T> operator--(int);
	bool operator==(const Iterator<T>&)const;
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
	if (currentNode->prevoius != nullptr)
	{
		currentNode = currentNode->prevoius;
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
