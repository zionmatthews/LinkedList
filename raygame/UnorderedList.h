#pragma once
#include <iostream>
#include "List.h"
template<typename T>
class UnorderedList : public List<T> 
{
public:
	bool search(const T&);
	void insertFirst(const T&);
	void insertLast(const T&);
	void deleteNode(const T&);
	void clear();
};

template<typename T>
bool UnorderedList<T>::search(const T& infoToSearch)
{
	if (this->m_first->info == infoToSearch) return true;
	if (this->m_last->info == infoToSearch) return true;
	for (auto i = this->begin(); i != this->end(); i++)
	{
		if (*i == infoToSearch) return true;
	}
	return false;
}

template<typename T>
void UnorderedList<T>::deleteNode(const T& infoToDelete)
{
	Node<T>* iter = &(*this->m_first);

	if (this->m_first->info == infoToDelete)
	{
		this->m_first = iter->next;
		delete iter;
		this->mCount--;
		return;
	}
	if (this->m_last->info == infoToDelete)
	{
		iter = &(*this->m_last);
		this->m_last = iter->previous;
		delete iter;
		this->mCount--;
		return;
	}

	int spotInList = 1;
	for (auto i = this->begin(); i != this->end(); i++)
	{
		if ((*i) == infoToDelete && spotInList != 0 && spotInList != this->Length())
		{
			iter->next->previous = iter->previous;
			iter->previous->next = iter->next;
			delete iter;
			this->mCount--;
			break;
		}
		else
		{
			spotInList++;
			iter = &(*iter->next);
		}
	}
}

template<typename T>
void UnorderedList<T>::clear()
{
	for (auto i = this->begin(); i != this->end(); i++)
	{
		this->deleteNode(*i);
	}
}

template<typename T>
void UnorderedList<T>::insertFirst(const T& tempInfo)
{
	Node<T>* newNode = new Node<T>;
	newNode->info = tempInfo;

	if (this->isListEmpty())
	{
		this->m_first = newNode;
		this->m_last = newNode;
		this->mCount++;
		return;
	}
	newNode->next = this->m_first;
	this->m_first->previous = newNode;
	this->m_first = newNode;
	newNode->previous = nullptr;
	this->mCount++;
}

template<typename T>
void UnorderedList<T>::insertLast(const T& tempInfo)
{
	Node<T>* newNode = new Node<T>;
	newNode->info = tempInfo;

	if (this->m_last == nullptr)
	{
		this->m_first = newNode;
		this->m_last = newNode;
		this->mCount++;
		return;
	}
	this->m_last->next = newNode;
	newNode->previous = this->m_last;
	this->m_last = newNode;
	newNode->next = nullptr;
	this->mCount++;
}