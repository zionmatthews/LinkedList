#pragma once
#include "Node.h"
#include "Iterator.h"

//holds data
template<typename T>
class List {
protected:
	//Keeps track of list
	int mCount;

	//the first and last of list
	Node<T>* m_last;
	Node<T>* m_first;

public:
	//set everything in list 
	void initializeList();

	//checks to see if list is empty
	bool isListEmpty();

	//used to keep tract of how long the list is
	int length();

	//first spot of the list
	T front();
	//last spot of the list
	T back();

	//Searches for the node 
	virtual bool search(const T&) = 0;

	//adds a node to the beginning of the list
	virtual void insertFirst(const T&) = 0;

	//adds a node to the end of the list
	virtual void insertLast(const T&) = 0;

	//deletes a node
	virtual void deleteNode(const T&) = 0;

	//iterates through the list starting with the beginning
	Iterator<T> begin();
	//iterates through the list starting with the beginning
	Iterator<T> end();

	//default constructor
	List();
	//default deconstructor
	~List();

private:
	//copies contents of list
	void copyList(List<T>&);
};

template<typename T>
void List<T>::initializeList()
{
	m_first = nullptr;
	m_last = nullptr;
	mCount = 0;
}

template<typename T>
bool List<T>::isListEmpty()
{
	if (m_first == nullptr) return true;
	else return false;
}

template<typename T>
int List<T>::length()
{
	return mCount;
}

template<typename T>
T List<T>::front()
{
	return m_first->info;
}

template<typename T>
T List<T>::back()
{
	return m_last->info;
}

template<typename T>
Iterator<T> List<T>::begin()
{
	return Iterator<T>(m_first);;
}

template<typename T>
Iterator<T> List<T>::end()
{
	return Iterator<T>(m_last);
}

template<typename T>
List<T>::List()
{
	initializeList();
}

template<typename T>
List<T>::~List()
{

}

template<typename T>
void List<T>::copyList(List<T>& listToCopy)
{
	this->m_first = &(*listToCopy->m_first);
	this->m_last = &(*listToCopy->m_last);
	mCount = listToCopy.length();
	delete listToCopy;
}