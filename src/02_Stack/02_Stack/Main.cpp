#include <iostream>
#include <string>
#include "Header.h"
#include "Stack.h"
#include "Exceptions.h"
using namespace std;

void main() 
{
	string your_expression;
	cout << "\t\t\t\tMY CALCULATOR\n" << "Enter your expression:";
	cout << "Enter your expression" << endl;
		getline(cin, your_expression);
		try
		{
			string postfix_form = myCalculator::PostfixForm(your_expression);
			cout << "Postfix form is:" << endl << postfix_form << endl;
			int count = 0;
			char* operands;
			double* values;
			myCalculator::GettingOperands(postfix_form, operands, values, count);
			double result = myCalculator::Calculate(postfix_form, operands, values, count);
			cout << "The result is: " << result << endl;
		}
		catch (const char* a)
		{
			cout << a << endl;
		}
		int c = 0;
		cin >> c;
}
