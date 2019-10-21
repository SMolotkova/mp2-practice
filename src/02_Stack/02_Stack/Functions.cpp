#include "Header.h"
#include "Stack.h"
#include "Exceptions.h"
#include <string>
#include <iostream>

using namespace std;

int myCalculator :: Priority(char operation) // maybe by if
{
	switch (operation)
	{
	case '*':
		return 1;
		break;
	case '/':
		return 1;
		break;
	case '+':
		return 2;
		break;
	case '-':
		return 2;
		break;
	default:
		cout << "Wrong operation!";
		break;
	}
}
bool myCalculator::Compare_of_signs(char tmp, TStack<char>& sign)
{
	if (Priority(sign.arr[sign.top - 1]) < Priority(tmp))//Priority(sign.Pop())<...
		return true;//move to another stack
	else
		return false;//left here
}
string  myCalculator::PostfixForm(string your_expression)
{
	TStack<char> Signs(your_expression.length() + 1);
	TStack<char> Operands(your_expression.length() + 1);
	int expression_size = your_expression.length();//пробовать в инт

	for (int i = 0; i < expression_size; i++)
	{
		//if sign came
		if ((your_expression[i] == '*') || (your_expression[i] == '/') ||
			(your_expression[i] == '+') || (your_expression[i] == '-'))
		{
			if (your_expression[i] == ' ')//space
				continue;
			if (Signs.IsEmpty())
			{
				Signs.Push(your_expression[i]);
				continue;
			}

			if (Compare_of_signs(your_expression[i], Signs)) // compare of top signs(top and came)
			{
				while (Signs.top != 0)
					Operands.Push(Signs.Pop());
				Signs.Push(your_expression[i]);
			}
			else
				Signs.Push(your_expression[i]);
		}

		if (your_expression[i] == '(')
			Signs.Push(your_expression[i]);

		//if a letter came
		if (isalpha(your_expression[i]))//если текущий символ строки буква
			Operands.Push(your_expression[i]);


		if (your_expression[i] == ')')//НАДО ЛИ МЕНЯТЬ ИЛИ ТАК РАБОТАЕТ
			while (Signs.top != 0)
			{
				if (Signs.arr[Signs.top - 1] != '(')
					Operands.Push(Signs.Pop());
				else
				{
					Signs.Pop();
					break;
				}
			}
	};
	//at the end
	while (!Signs.IsEmpty())
		Operands.Push(Signs.Pop());//НУЖНО ЛИ ТУТ ДОПИСАТЬ 
	string postfix_form;
	while (!Operands.IsEmpty())
	{
		postfix_form += Operands.Pop(); //И ТУТ
	}

	for (int i = 0; i < postfix_form.length() / 2; i++)
		swap(postfix_form[i], postfix_form[postfix_form.length() - 1 - i]);

	return postfix_form;
}
double myCalculator :: Calculate(string postfix_form)
{
	int Post[10];
	for (int i = 0; i < postfix_form.length(); i++)
		Post[i] = postfix_form[i];

	TStack<float> Signs(10);
	TStack<char> Operands(10);
	int length = postfix_form.length();
	int a = 0, b = 0;
	int count = 0;

	for (int i = 0; i < length; i++)
	{
		int flag = 0;
		int j = 0;
		if (isalpha(Post[i]))
		{
			for (j = 0; j < Operands.top; j++)
				if (Operands[j] == Post[i])
				{
					flag = 1;
					break;
				}
			if (flag == 0)
			{
				Operands.Push(Post[i]);
				cout << "\n  " << Operands[Operands.top - 1] << " = ";
				cin >> a;
				Signs.Push(a);
			}
			else Signs.Push(Signs.arr[j]);
		}
		if ((Post[i] == '*') || (Post[i] == '/') ||
			(Post[i] == '+') || (Post[i] == '-'))
		{
			a = Signs.Pop();
			b = Signs.Pop();
			if (Post[i] == '*') count = b * a;
			if (Post[i] == '+') count = b + a;
			if (Post[i] == '-') count = b - a;
			if (Post[i] == '/')
			{
				if (a == 0)
					throw WrongDivision();
				count = b / a;
			}
			Signs.Push(count);
		}
	}
	return Signs.arr[Signs.top - 1];
}
