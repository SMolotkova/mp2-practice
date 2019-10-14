#include "Header.h"
#include "Stack.h"
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
		cout << "Wrong Operation!";
		break;
	}
}
bool myCalculator::Compare_of_signs(char tmp, TStack<char>& sign)
{
	if (Priority(sign.arr[sign.top - 1]) < Priority(tmp))
		return true;//move to another stack
	else
		return false;//left here
}
char*  myCalculator::PostfixForm(char* your_expression, int &lengs_of_postfix_form)
{
	TStack<char> Signs(10);
	TStack<char> Operands(10);
	const char* expression = your_expression;
	char expression_size = strlen(your_expression);//может не чар?

	for (int i = 0; i < expression_size; i++)
	{
		//if sign came
		if ((your_expression[i] == '*') || (your_expression[i] == '/') ||
			(your_expression[i] == '+') || (your_expression[i] == '-'))
		{
			if (Compare_of_signs(your_expression[i], Signs)) // compare of top signs
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


		if (your_expression[i] == ')')
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
		Operands.Push(Signs.Pop());
	char tmp[10];
	for (int i = 0; i < Operands.size; i++)
		tmp[i] = Operands.arr[i];
	cout << "Postfix form is: " << tmp << endl;

	lengs_of_postfix_form = Operands.top;

	return tmp;
}
double myCalculator :: Calculate(char PostfixForm[], int lengs_of_postfix_form)
{
	int Post[10];
	for (int i = 0; i < lengs_of_postfix_form; i++)
		Post[i] = PostfixForm[i];

	TStack<float> Signs(10);
	TStack<char> Operands(10);
	char length = lengs_of_postfix_form;
	float a = 0, b = 0;
	float count = 0;

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