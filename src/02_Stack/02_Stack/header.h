#pragma once
#include "Stack.h"
#include <string>

using namespace std;


class myCalculator
{
	static int Priority(char sign);
public:
	static string Postfix(string your_expression);
	static void GettingValues(string, char*& operands, double*&, int&);
	static double Calculate(string str, char* let, double* val, int n);
	static bool Errors(string your_expression);
};


int myCalculator::Priority(char sign)
{
	switch (sign)
	{
	case '*':
		return 3;
	case '/':
		return 3;
	case '+':
		return 2;
	case '-':
		return 2;
	case '(':
		return 1;
	default:
		cout << "Wrong Operation!" << sign;
		break;
	}
}


string myCalculator::Postfix(string your_expression)
{
	int n = 0;
	TStack<char> operands(20);
	TStack<char> operations(20);
	for (int i = 0; i < your_expression.length(); i++)
	{
		if (your_expression[i] == '(')
			operations.Push(your_expression[i]);
		if (isalpha(your_expression[i]))
		{
			operands.Push(your_expression[i]);
		}
		if ((your_expression[i] == '*') || (your_expression[i] == '/') || (your_expression[i] == '+') || (your_expression[i] == '-'))
		{
			if (!operations.IsEmpty())
				if (Priority(operations.Top()) >= Priority(your_expression[i]))
				{
					operands.Push(operations.Top());
					operations.Pop();
				}
			operations.Push(your_expression[i]);
		}
		if (your_expression[i] == ')')
		{
			while (operations.Top() != '(')
			{
				operands.Push(operations.Top());
				operations.Pop();
			}
			operations.Pop();
		}
	}
	while (!operations.IsEmpty())
	{
		operands.Push(operations.Top());
		operations.Pop();
	}

	char tmp[20];
	int i = 0;
	while (!operands.IsEmpty())
	{
		tmp[i] = operands.Top();
		operands.Pop();
		i++;
	}
	for (int j = i; j < 20; j++)
		tmp[j] = '\0';


	string postfix_form = string(tmp);
	for (int j = 0; j < i / 2; j++)
		swap(postfix_form[j], postfix_form[i - j - 1]);
	return postfix_form;
}


void myCalculator::GettingValues(string postfix_form, char*& operands, double*& values, int& count_of_operands)
{
	count_of_operands = 0;
	for (int i = 0; i < postfix_form.length(); i++)
	{
		if (isalpha(postfix_form[i]))
		{
			count_of_operands++;
		}
	}
	//cout << "Number of operands is : "<< count_of_operands << endl;

	int diff_letter;
	operands = new char[count_of_operands];
	values = new double[count_of_operands];
	count_of_operands = 0;
	for (int i = 0; i < postfix_form.length(); i++)
	{
		if (isalpha(postfix_form[i]))
		{
			diff_letter = 0;
			for (int j = 0; j < count_of_operands; j++)
				if (postfix_form[i] == operands[j])
					diff_letter++;
			if (diff_letter == 0)
			{
				operands[count_of_operands] = postfix_form[i];
				count_of_operands++;
			}
		}
	}
	for (int i = 0; i < count_of_operands; i++)
	{
		cout << "Enter value of  "<< operands[i] << ":" << endl;
		cin >> values[i];
	}
}

double myCalculator::Calculate(string postfix_form, char* operands, double* values, int count_of_operands)
{
	TStack<double> stack(postfix_form.length());

	char tmp;
	double a = 0, b = 0, sum = 0;
	for (int i = 0; i < postfix_form.length(); i++)
	{
		tmp = postfix_form[i];
		if (isalpha(tmp))
		{
			for (int j = 0; j < count_of_operands; j++)
				if (tmp == operands[j])
				{
					stack.Push(values[j]);
					break;
				}
		}
		if (tmp == '*')
		{
			b = stack.Top();
			stack.Pop();
			a = stack.Top();
			stack.Pop();
			sum = a * b;
			stack.Push(sum);
		}
		if (tmp == '+')
		{
			b = stack.Top();
			stack.Pop();
			a = stack.Top();
			stack.Pop();
			sum = a + b;
			stack.Push(sum);
		}
		if (tmp == '-')
		{
			b = stack.Top();
			stack.Pop();
			a = stack.Top();
			stack.Pop();
			sum = a - b;
			stack.Push(sum);
		}
		if (tmp == '/')
		{
			b = stack.Top();
			stack.Pop();
			a = stack.Top();
			stack.Pop();
			if(b == 0)
				throw "Wrong Division!\n";
			sum = a / b;
			stack.Push(sum);
		}
	}
	return sum;
}

bool myCalculator::Errors(string your_expression)
{
	if (your_expression.length() == 0)
		throw "Empty line";

	if (your_expression[0] == ')')
		throw "You started with a wrong bracket )";

	int count_of_right_brackets = 0, count_of_left_brackets = 0, count_of_operands = 0, count_of_operations = 0;

	for (int i = 0; i < your_expression.length(); i++)
	{
		if (your_expression[i] == '(')
		{
			if (i != 0)
				if (your_expression[i - 1] == ')')
					throw "Brackets together )(";
			count_of_right_brackets++;
		}
		if (your_expression[i] == ')')
		{
			if (i != 0)
				if (your_expression[i - 1] == '(')
					throw "Brackets together ()";
			count_of_left_brackets++;
		}
		if (isalpha(your_expression[i]))
			count_of_operands++;
		if ((your_expression[i] == '*') || (your_expression[i] == '/') || (your_expression[i] == '+') || (your_expression[i] == '-'))
			count_of_operations++;
	}
	if ((count_of_right_brackets > count_of_left_brackets) || (count_of_left_brackets > count_of_right_brackets))
		throw "You forget bracket";
	if (count_of_operations >= count_of_operands)
		throw "Not enough operands";
	if ((count_of_operations + 1) != count_of_operands)
		throw "Wrong number of operands or operations";
	return true;
}

