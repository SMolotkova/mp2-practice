#include <string>
#include <iostream>
#include "Header.h"
#include "Stack.h"
#include "Exceptions.h"


using namespace std;


int myCalculator::Priority(char operation) // maybe by if
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
	if (Priority(sign.Top()) < Priority(tmp))
		return true;
	else
		return false;
}
string  myCalculator::PostfixForm(string your_expression)
{
	TStack<char> Signs(your_expression.length() + 1);
	TStack<char> Operands(your_expression.length() + 1);
	int expression_size = your_expression.length();

	for (int i = 0; i < expression_size; i++)
	{
		if ((your_expression[i] == '*') || (your_expression[i] == '/') ||
			(your_expression[i] == '+') || (your_expression[i] == '-'))
		{
			if (your_expression[i] == ' ')
				continue;
			if (Signs.IsEmpty())
			{
				Signs.Push(your_expression[i]);
				continue;
			}

			if (Compare_of_signs(your_expression[i], Signs))
			{
				while (!Signs.IsEmpty())
					Operands.Push(Signs.Top());
				Signs.Pop();
				Signs.Push(your_expression[i]);
			}
			else
				Signs.Push(your_expression[i]);
		}

		if (your_expression[i] == '(')
			Signs.Push(your_expression[i]);

		if (isalpha(your_expression[i]))
			Operands.Push(your_expression[i]);

		if (your_expression[i] == ')')
		{
			int flag = 0;
			while (!Signs.IsEmpty())
			{
				if (Signs.Top() != '(')
				{
					Operands.Push(Signs.Top());
					Signs.Pop();
					continue;
				}
				Signs.Pop();
				flag = 1;
				break;
			};
			if ((Signs.IsEmpty()) && (flag != 1))
				throw WrongIndex();
		};
	};

	while (!Signs.IsEmpty())
	{
		Operands.Push(Signs.Top());
		Signs.Pop();
	}
	string postfix_form;
	while (!Operands.IsEmpty())
	{
		postfix_form += Operands.Top();
		Operands.Pop();
	}

	for (int i = 0; i < postfix_form.length() / 2; i++)
		swap(postfix_form[i], postfix_form[postfix_form.length() - 1 - i]);

	return postfix_form;
}
//double myCalculator::Calculate(string postfix_form)
//{
//	int Post[10];
//	for (int i = 0; i < postfix_form.length(); i++)
//		Post[i] = postfix_form[i];
//
//	TStack<float> Signs(10);
//	TStack<char> Operands(10);
//	int length = postfix_form.length();
//	int a = 0, b = 0;
//	int count = 0;
//
//	for (int i = 0; i < length; i++)
//	{
//		int flag = 0;
//		int j = 0;
//		if (isalpha(Post[i]))
//		{
//			for (j = 0; j < Operands.TopPop(); j++)
//				if (Operands[j] == Post[i])
//				{
//					flag = 1;
//					break;
//				}
//			if (flag == 0)
//			{
//				Operands.Push(Post[i]);
//				cout << "\n  " << Operands.TopPop() << " = ";
//				cin >> a;
//				Signs.Push(a);
//			}
//			else
//			{
//				Signs.Push(Signs.TopPop());
//				Signs.Pop();
//			}
//		}
//		if ((Post[i] == '*') || (Post[i] == '/') ||
//			(Post[i] == '+') || (Post[i] == '-'))
//		{
//			a = Signs.TopPop();
//			b = Signs.TopPop();
//			if (Post[i] == '*') count = b * a;
//			if (Post[i] == '+') count = b + a;
//			if (Post[i] == '-') count = b - a;
//			if (Post[i] == '/')
//			{
//				if (a == 0)
//
//					throw WrongDivision();
//
//				count = b / a;
//			}
//			Signs.Push(count);
//		}
//	}
//	return Signs.TopPop();
//}
//double myCalculator::Calculate(string postfix_form)
//{
//	перекладываем постф форму в стек
//	TStack<char> Stack(20);
//	for (int i = 0; i < postfix_form.length(); i++)
//		Stack.Push(postfix_form[i]);
//
//	TStack<double> Res(20);
//	double n, a = 0, b = 0, sum = 0;
//	Stack.top = Stack.arr[postfix_form.length()];
//	int stack_size = postfix_form.length();//узнаем размер стека, вернуть вершину по ее индексу,индексу топа
//	for (int i = 0; i < stack_size; i++)
//	{
//		if (isalpha(Stack.Top()))
//		{
//			cout << Stack.Top() << '\n';//вводим букву,которая последняя
//			cin >> n;
//			Res.Push(n);
//		}
//		/*if (Stack.Top() == '*')
//		{
//			sum = (Res.Top()) * (Res.Top());
//			Res.Push(sum);
//		}
//		if (Stack.Top() == '+')
//		{
//			cout << "asd";
//			sum = Res.Top() + Res.Top();
//			Res.Push(sum);
//		}
//		if (Stack.Top() == '-')
//		{
//			b = Res.Top();
//			a = Res.Top();
//			sum = a - b;
//			Res.Push(sum);
//		}
//		if (Stack.Top() == '/')
//		{
//			b = Res.Top();
//			a = Res.Top();
//			sum = a / b;
//			Res.Push(sum);
//		}*/
//		Stack.Pop();
//	}
//	return sum;
//}
double myCalculator::Calculate(string postfix_form)
{
	//узнаемсколько букв
	int count = 0;
	for (int i = 0; i < postfix_form.length(); i++)
		if (isalpha(postfix_form[i]))
			count++;
	string Letters;
	int* Numbers = new int[count];
	int topLetters = 0;
	int val = 0;
	char* letters = new char[count];
	int* numbers = new int[count];
	
	for (int i = 0; i < postfix_form.length(); i++)
		if (isalpha(postfix_form[i]))
		{
			int flag = 0;
			for (int j = 0; j < topLetters; j++)
				if (letters[j] == postfix_form[i])
				{
					flag = 1;
					break;
				}
			if (flag == 0)
			{
				letters[topLetters] = postfix_form[i];
				cout << "\n  " << letters[topLetters] << " = ";
				cin >> val;
				numbers[topLetters++] = val;
			}
		}
	Letters.assign(letters);
	memcpy(Numbers, numbers, sizeof(int) * count);

	TStack<float> Value(25);

	//?????? ??????????? ??????
	for (int i = 0; i < postfix_form.length(); i++)
	{
		if (isalpha(postfix_form[i]))
			for (int j = 0; j < Letters.length(); j++)
				if (Letters[j] == postfix_form[i])
				{
					Value.Push(Numbers[j]);
					break;
				}
		if ((postfix_form[i] == '*') || (postfix_form[i] == '/') ||
			(postfix_form[i] == '+') || (postfix_form[i] == '-'))
		{
			int a = Value.Top();
			Value.Pop();
			int b = Value.Top();
			Value.Pop();

			if (postfix_form[i] == '*') Value.Push(b * a);
			if (postfix_form[i] == '/')
			{
				if (a == 0)
					throw  WrongDivision();
				else Value.Push(b / a);
			};
			if (postfix_form[i] == '+') Value.Push(b + a);
			if (postfix_form[i] == '-') Value.Push(b - a);
		}
	}
	return Value.Top();
}
