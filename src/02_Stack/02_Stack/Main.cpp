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
	int lengs_of_postfix_form = 0;
	double amount = 0;
	char* strUser = new char[20];
	cout <<"\t\t\t\tMY CALCULATOR\n"<< "Enter your expression:";
	cin.getline(strUser, 20);
	char tmp[10];
	char* post = myCalculator :: PostfixForm(strUser, lengs_of_postfix_form);
	for (int i = 0; i < lengs_of_postfix_form; i++)
		tmp[i] = post[i];
	try
	{
		amount = myCalculator :: Calculate(tmp, lengs_of_postfix_form);
	}
	catch (WrongDivision& s)
	{
		cout << s.what() << endl;
	};
	cout << "\n  Result = " << amount;
	cin.get();
	int d;
	cin >> d;
}