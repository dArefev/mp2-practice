#ifndef TSTACK_H
#define TSTACK_H
#include "TList.h"
#include <iostream>
using namespace std;

template <typename T>
class TStack
{
private:
	TList<T>*elems;
public:
	TStack();
	~TStack();
	TStack(const TStack<T>& a);
	void Push(T a);
	T Pop();
	bool IsFull()const;
	bool IsEmpty()const;
};



template <typename T>
TStack<T>::TStack()
{
	elems = new TList<T>();
};

template <typename T>
TStack<T>::~TStack()
{
	delete elems;
};

template <typename T>
TStack<T>::TStack(const TStack<T>& a)
{
	elems = new TList(*(a.elems));
};

template <typename T>
void TStack<T>::Push(T a)
{
	if (IsFull())
		throw "Error! Stack is full";
	elems->insert_start(a);
};

template <typename T>
T TStack<T>::Pop()
{
	if (IsEmpty())
		throw "Error! Stack is empty";
	T key = elems->Top()->Key;
	elems->Remove(key);
	return key;
};

template <typename T>
bool TStack<T>::IsEmpty()const
{
	return elems->Top() == 0;
};

template <typename T>
bool TStack<T>::IsFull()const
{
	T Key = -1;
	try
	{
		elems->insert_start(Key);
		elems->Remove(Key);
	}
	catch (...) { return true; }
	return false;

};

#endif
