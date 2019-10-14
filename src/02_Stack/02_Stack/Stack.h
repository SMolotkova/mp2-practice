#pragma once
#include "Exceptions.h"
#include <iostream>
using namespace std;

template<class ValueType>
class TStack
{
public:
	int size;
	int top;
	ValueType* arr;

	TStack(int max);
	TStack(const TStack& stack);
	~TStack();

	bool IsFull()const;
	bool IsEmpty()const;

	void Push(ValueType next);
	ValueType Pop();

	ValueType& operator[](int index);
	int GetTop()const;

	/*friend ostream& operator<<(ostream& os, const Stack& tmp)
	{
		for (int i = 0; i < tmp.top; i++)
			os << tmp.arr[i];
		return os;
	};*/
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
	if (top == size)
		return true;
	return false;
}

template<class ValueType>
bool TStack<ValueType>::IsEmpty()const
{
	if (top == 0)
		return true;
	return false;
}

template<class ValueType>
void TStack<ValueType>::Push(ValueType next)
{
	if (IsFull())
		throw FullStack();
	arr[top++] = next;
}

template<class ValueType>
inline ValueType TStack<ValueType>::Pop()
{
	if (IsEmpty())
		throw EmptyStack();
	return arr[--top];
}

template<class ValueType>
ValueType& TStack<ValueType>::operator[](int index)
{
	if ((index < 0) || (index >= size))
		throw WrongIndex();

	return arr[index];
};

template<class ValueType>
int TStack<ValueType>::GetTop()const
{
	return top;
};

//------------------------For Calculating----------------------------

//int Priority(char operation)
//{
//	switch (operation)
//	{
//	case '*': 
//		return 1;
//		break;
//	case '/': 
//		return 1;
//		break;
//	case '+': 
//		return 2;
//		break;
//	case '-': 
//		return 2;
//		break;
//	default: 
//		cout << "Wrong Operation!";
//		break;
//	}
//}

//bool Compare_of_signs(char tmp, TStack<char>& sign)
//{
//	if (Priority(sign.arr[sign.top - 1]) < Priority(tmp))
//		return true;//move to another stack
//	else 
//		return false;//left here
//};
//char* PostfixForm(char* your_expression, int &lengs_of_postfix_form)
//{
//	TStack<char> Signs(10);
//	TStack<char> Operands(10);
//	const char* expression = your_expression;
//	char expression_size = strlen(your_expression);//может не чар?
//
//	for (int i = 0; i < expression_size; i++)
//	{
//		//if sign came
//		if ((your_expression[i] == '*') || (your_expression[i] == '/') ||
//			(your_expression[i] == '+') || (your_expression[i] == '-'))
//		{
//			if (Compare_of_signs(your_expression[i], Signs)) // compare of top signs
//			{
//				while (Signs.top != 0)
//					Operands.Push(Signs.Pop());
//				Signs.Push(your_expression[i]);
//			}
//			else
//				Signs.Push(your_expression[i]);
//		}
//
//		if (your_expression[i] == '(')
//			Signs.Push(your_expression[i]);
//
//		//if a letter came
//		if (isalpha(your_expression[i]))//если текущий символ строки буква
//			Operands.Push(your_expression[i]);
//
//		
//		if (your_expression[i] == ')')
//			while (Signs.top != 0)
//			{
//				if (Signs.arr[Signs.top - 1] != '(')
//					Operands.Push(Signs.Pop());
//				else
//				{
//					Signs.Pop();
//					break;
//				}
//			}
//	};
//	//at the end
//	while (!Signs.IsEmpty())
//		Operands.Push(Signs.Pop());
//	char tmp[10];
//	for (int i = 0; i < Operands.size; i++)
//		tmp[i] = Operands.arr[i];
//	cout <<"Postfix form is: " << tmp << endl;
//
//	lengs_of_postfix_form = Operands.top; 
//	
//	return tmp;
//};
//float Calculate(char PostfixForm[], int lengs_of_postfix_form)
//{
//	int Post[10];
//	for (int i = 0; i < lengs_of_postfix_form; i++)
//		Post[i] = PostfixForm[i];
//
//	TStack<float> Signs(10);
//	TStack<char> Operands(10);
//	char length = lengs_of_postfix_form;
//	float a = 0, b = 0;
//	float count = 0;
//
//	for (int i = 0; i < length; i++)
//	{
//		int flag = 0;
//		int j = 0;
//		if (isalpha(Post[i]))
//		{
//			for (j = 0; j < Operands.top; j++)
//				if (Operands[j] == Post[i])
//				{
//					flag = 1;
//					break;
//				}
//			if (flag == 0)
//			{
//				Operands.Push(Post[i]);
//				cout << "\n  " << Operands[Operands.top - 1] << " = ";
//				cin >> a;
//				Signs.Push(a);
//			}
//			else Signs.Push(Signs.arr[j]);
//		}
//		if ((Post[i] == '*') || (Post[i] == '/') ||
//			(Post[i] == '+') || (Post[i] == '-'))
//		{
//			a = Signs.Pop();
//			b = Signs.Pop();
//			if (Post[i] == '*') count = b * a;
//			if (Post[i] == '+') count = b + a;
//			if (Post[i] == '-') count = b - a;
//			if (Post[i] == '/')
//			{
//				if (a == 0)
//					throw WrongDivision();
//					count = b / a;
//			}
//			Signs.Push(count);
//		}
//	}
//	return Signs.arr[Signs.top - 1];
//}

