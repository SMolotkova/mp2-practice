#include <iostream>
#include <string>
#include "stack.h"
#include "exceptions.h"
using namespace std;

class myCalculator
{
private:
	static int Priority(const char);//приоретет операций
	static bool Comparison(char, TStack<char>&);//сравнение приоритетов
	static bool IsItOperation(const char);//определение операция это или нет
public:
	static string PostfixForm(string);//создание постфиксной формы
	static void GettingValues(string, char* &, double* &, int &);//ввод значений
	static double Calculate(string, char*, double*, int);//полученное значение

	static int Count(string);//количество операндов в прайвит
	//static double Calculate(double*, string&, string);//полученное значение
	//static void GettingValues(double*, string&, string, int);//ввод значений
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
bool myCalculator::Comparison(char expression, TStack<char>& topElem)
{
	return (Priority(topElem.Top()) < Priority(expression));
}

bool myCalculator::IsItOperation(const char sign)
{
	return ((sign == '*') || (sign == '/') || (sign == '+') || (sign == '-'));
}

int myCalculator::Count(string postfix_form)
{
	int count = 0;
	for (int i = 0; i < postfix_form.length(); i++)
	{
		if (isalpha(postfix_form[i]))
		{
			count++;
		}
	}
	return count;
}
//ввод значений
void myCalculator::GettingValues(double* values, string& operands, string postfix_form, int count)
{
	int current_count_of_operands = 0;
	double value = 0;
	char* new_operands = new char[count];
	double* new_values = new double[count];
	for (int i = 0; i < postfix_form.length(); i++)
	{
		if (isalpha(postfix_form[i]))
		{
			int flag = 0;
			for (int j = 0; j < current_count_of_operands; j++)
			{
				if (new_operands[j] == postfix_form[i])
				{
					flag = 1;
					break;
				}
			}
			if (flag == 0)
			{
				new_operands[current_count_of_operands] = postfix_form[i];
				cout << "Enter value " << postfix_form[i] << endl;
				cin >> value;
				new_values[current_count_of_operands] = value;
				current_count_of_operands++;
			}
		}
	}
	operands.assign(new_operands);
	memcpy(values, new_values, sizeof(double) * count);
}

string myCalculator::PostfixForm(string your_expression)
{
	if (your_expression.length() == 0)
	{
		throw "Wrong string\n";
	}
	TStack<char> stack1(your_expression.length() + 1);//операции
	TStack<char> stack2(your_expression.length() + 1);//операнды
	for (int i = 0; i < your_expression.length(); i++)
	{
		char sign = static_cast<char>(your_expression[i]);
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
					cout << stack1.Top() << endl;
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
				throw " Need ) or (\n";
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


double myCalculator::Calculate(double* values, string& operands, string postfix_form)
{
	TStack<double> result(postfix_form.length());
	for (int i = 0; i < postfix_form.length(); i++)
	{
		char sign = static_cast<char>(postfix_form[i]);
		if (isalpha(sign))
		{
			for (int j = 0; j < operands.length(); j++)
			{
				if (operands[j] == sign)
				{
					result.Push(values[j]);
					break;
				}
			}
			continue;
		}

		double first = result.Top();
		result.Pop();
		double second = result.Top();
		result.Pop();
		double res;

		switch (sign)
		{
		case '+':
			res = second + first;
			break;
		case '-':
			res = second - first;
			break;
		case '*':
			res = second * first;
			break;
		case '/':
			if (first == 0)
				throw "Divisin by 0!\n";
			res = second / first;
			break;
		}

		result.Push(res);
	}
	return result.Top();
};
