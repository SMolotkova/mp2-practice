#pragma once
#include "exceptions.h"
#include <iostream>
using namespace std;

template<class ValueType>
class TStack
{
private:
	int size;
	int top;
	ValueType* arr;

public:
	TStack(int max);
	TStack(const TStack& stack);
	~TStack();

	bool IsFull()const;
	bool IsEmpty()const;

	void Push(ValueType next);
	ValueType Top() const;
	void Pop();
};


template<class ValueType>
TStack<ValueType>::TStack(int max)
{
	size = max;
	top = 0;
	arr = new ValueType[size];
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}

template<class ValueType>
TStack<ValueType>::TStack(const TStack<ValueType>& tmp)
{
	size = tmp.size;
	top = tmp.top;
	arr = new ValueType[size];
	for (int i = 0; i < size; i++)
		arr[i] = tmp.arr[i];
};

template<class ValueType>
TStack<ValueType>::~TStack()
{
	size = 0;
	top = 0;
	delete[] arr;
}

template<class ValueType>
bool TStack<ValueType>::IsFull()const
{
	return (top == size);
}

template<class ValueType>
bool TStack<ValueType>::IsEmpty()const
{
	return (top == 0);
}

template<class ValueType>
void TStack<ValueType>::Push(ValueType next)
{
	if (IsFull())
		throw FullStack();
	arr[top++] = next;
}

template<class ValueType>
ValueType TStack<ValueType>::Top() const
{
	if (IsEmpty())
		throw EmptyStack();
	return arr[top - 1];
}

template<class ValueType>
void TStack<ValueType>::Pop()
{
	if (IsEmpty())
		throw EmptyStack();
	top--;
}
