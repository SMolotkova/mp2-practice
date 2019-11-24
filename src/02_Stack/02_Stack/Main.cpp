#include <iostream>
#include <string>
#include "header.h"
#include "stack.h"
#include "exceptions.h"
using namespace std;

void main() 
{
	string your_expression;
	string operands;
	
		cout << "\t\t\t\tMY CALCULATOR\n" << "Enter your expression:";
		getline(cin, your_expression);
		string postfix_form = myCalculator::PostfixForm(your_expression);
		cout << "Postfix form is:" << postfix_form << endl;
		int count = myCalculator::Count(postfix_form);
		double* values = new double[count];
		myCalculator::GettingValues(values, operands, postfix_form, count);
		double result = myCalculator::Calculate(values, operands, postfix_form);
		cout << "Result is: " << result << endl;
	system("pause");
}
