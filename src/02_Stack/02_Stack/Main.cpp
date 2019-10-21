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

	cout << "\t\t\t\tMY CALCULATOR\n" << "Enter your expression:";

	getline(cin, your_expression);
	cout << "\n  Postfix Form is: " << myCalculator::PostfixForm(your_expression) << endl;
	int amount = myCalculator::Calculate(myCalculator::PostfixForm(your_expression));
	cout << "Reasult is: "<< amount;
	int f;
	cin >> f;
}