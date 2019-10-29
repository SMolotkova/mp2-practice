#include "Stack.h"
#include "Header.h"
#include "Exceptions.h"
#include <cstdio>
#include <iostream>
#include <string>
#include<windows.h>
using namespace std;

void SetStyle_PurpleBlue() { const int NotUsed = system("color 37"); }

int main()
{
	SetStyle_PurpleBlue();
	string your_expression;
	string postfix_form;
	string letters;

	cout << "\t\t\t\tMY CALCULATOR\n" << "Enter your expression:";
	getline(cin, your_expression);

	cout << "\n  Postfix Form is: " << myCalculator::PostfixForm(your_expression) << endl;

	postfix_form = myCalculator::PostfixForm(your_expression);
	try
	{
		double amount = myCalculator::Calculate(postfix_form);
		cout << "Result is: " << amount;
	}
	catch (WrongDivision& e)
	{
		cout << e.what();
	}
	int f;
	cin >> f;
}
