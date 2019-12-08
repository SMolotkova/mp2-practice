#include <iostream>
#include <string>
#include "Stack.h"
#include "Exceptions.h"
using namespace std;

class myCalculator 
{
private:
	static int Priority(const char sign);//определение приоретета операций
	static bool Comparison(char expression, TStack<char>& top);//сравнение приоритетов
	static bool IsItOperation(const char);//определение операция это или нет
public:
	static string PostfixForm(string);//образование постфиксной формы
	static double Calculate(string postfix_form, char* operands, double* values, int count_of_operands);//возвращает результат подсчета
	static void GettingOperands(string postfix_form, char* &operands, double* &values, int &count_of_operands);
};


int myCalculator::Priority(const char sign) 
{
	switch (sign) 
	{
	case '+': return 2;
	case '-': return 2;
	case '*': return 1;
	case '/': return 1;
	default: return 3;
	}
}
bool myCalculator::Comparison(char expression, TStack<char>& top) 
{	
	return (Priority(top.Top()) < Priority(expression));
};

bool myCalculator::IsItOperation(const char sign) 
{
	return ((sign == '*') || (sign == '/') || (sign == '+') || (sign == '-'));
}

void myCalculator::GettingOperands(string p_f, char*& operands, double*& values, int& count) {
	for (int i = 0; i < p_f.length(); i++) 
	{
		if (isalpha(p_f[i])) 
		{
			count++;
		}
	}
	int current_count_of_operands = 0;
	double value = 0;
	operands = new char[count];
	values = new double[count];
	for (int i = 0; i < p_f.length(); i++) 
	{
		if (isalpha(p_f[i])) 
		{
			int flag = 0;
			for (int j = 0; j < current_count_of_operands; j++) 
			{
				if (operands[j] == p_f[i]) 
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0) 
			{
				operands[current_count_of_operands] = p_f[i];
				cout << "Enter value of " << p_f[i] << endl;
				cin >> value;
				values[current_count_of_operands] = value;
				current_count_of_operands++;
			}
		}
	}
}


string myCalculator::PostfixForm(string exp) {
	if (exp.length() == 0) 
	{
		throw "Wrong string!\n";
	}
	TStack<char> stack1(exp.length() + 1);//операции
	TStack<char> stack2(exp.length() + 1);//операнды
	for (int i = 0; i < exp.length(); i++) 
	{
		char sign = static_cast<char>(exp[i]);
		if (sign == ' ') 
		{
			continue;
		}
		if (IsItOperation(sign)) 
		{
			if (stack1.IsEmpty()) 
			{
				stack1.Push(sign);
				continue;
			}
			if (Comparison(sign, stack1)) 
			{
				while (!stack1.IsEmpty()) 
				{
					stack2.Push(stack1.Top());
					stack1.Pop();
				}
				stack1.Push(sign);
			}
			else
				stack1.Push(sign);
		}

		if (sign == '(') 
		{
			stack1.Push(sign);
		}
		if (isalpha(sign)) 
		{
			stack2.Push(sign);
		}
		if (sign == ')') 
		{
			int left_bracket_flag = 0;
			while (!stack1.IsEmpty()) 
			{
				if (stack1.Top() != '(') 
				{
					stack2.Push(stack1.Top());
					stack1.Pop();
					continue;
				}
				stack1.Pop();
				left_bracket_flag = 1;
				break;
			}
			if ((left_bracket_flag != 1) && (stack1.IsEmpty())) 
			{
				throw "Error";
			}
		}

	}
	while (!stack1.IsEmpty()) 
	{
		stack2.Push(stack1.Top());
		stack1.Pop();
	}
	string postfix_form;

	while (!stack2.IsEmpty()) 
	{
		postfix_form += stack2.Top();
		stack2.Pop();
	}

	for (int i = 0; i < postfix_form.length() / 2; i++)
		swap(postfix_form[i], postfix_form[postfix_form.length() - 1 - i]);

	return postfix_form;
}

double myCalculator::Calculate(string p_f, char* operands, double* values, int count)
{
	TStack<double> resulting_mas(p_f.length());
	for (int i = 0; i < p_f.length(); i++) {
		char sign = static_cast<char>(p_f[i]);
		if (isalpha(sign)) {
			for (int j = 0; j < count; j++) {
				if (operands[j] == sign) {
					resulting_mas.Push(values[j]);
					break;
				}
			}
			continue;
		}
		else
		{
			double first = resulting_mas.Top();
			resulting_mas.Pop();
			double second = resulting_mas.Top();
			resulting_mas.Pop();
			double result;

			switch (sign) {
			case '+':
				result = second + first;
				break;
			case '-':
				result = second - first;
				break;
			case '*':
				result = second * first;
				break;
			case '/':
				if (first == 0)
					throw "Wrong Division!\n";
				result = second / first;
				break;
			}

			resulting_mas.Push(result);
		}
	}
	return resulting_mas.Top();
};


