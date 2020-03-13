#pragma once
#include <iostream>
#include "List.h"

template<typename T>
class UnorderedList : public List<T> {
public:
	//returns true if node is found
	bool search(const T&);

	//adds a node to the beginning of the list
	void insertFirst(const T&);

	//adds a node to the end of the list
	void insertLast(const T&);

	//deletes a node
	void deleteNode(const T&);

	//clears everything
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
		if (this->length() == 1)
		{
			this->m_first = nullptr;
			this->m_last = nullptr;
			delete iter;
			this->mCount--;
			return;
		}
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
		if ((*i) == infoToDelete && spotInList != 0 && spotInList != this->length())
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
		for (int i = this->mCount; i > 0; i--)
		{
			Node<T>* iter = this->m_first;
			Node<T>* iterNext = nullptr;

			if (iter->next != nullptr)
			{
				iterNext = iter->next;
			}

			this->deleteNode(iter->info);

			if (iterNext != nullptr)
			{
				iter = iterNext;
			}
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