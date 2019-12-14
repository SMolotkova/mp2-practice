#include <iostream>
#include <string>

#include "Stack.h"
#include "Header.h"

using namespace std;

void main()
{
	string your_expression;
	string postfix_form;
	double result;
	int pause;

	cout << "\t\t\t\tMY CALCULATOR\n" << "Enter your expression:";
	getline(cin, your_expression);

	try
	{
		if (myCalculator:: Errors(your_expression) == true)
			postfix_form = myCalculator::Postfix(your_expression);
		cout << "Postfix form is: " << postfix_form << '\n';
		char* operands;
		double* values;
		int count_of_operands;

		myCalculator::GettingValues(postfix_form, operands, values, count_of_operands);
		result = myCalculator::Calculate(postfix_form, operands, values, count_of_operands);

		cout << "The result is " << result << '\n';
		delete[] operands;
		delete[] values;
	}
	catch (const char* error_line)
	{
		cout << error_line << endl;
	}
	cin >> pause;
}
