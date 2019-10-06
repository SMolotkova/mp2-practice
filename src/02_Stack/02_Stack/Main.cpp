#include "Stack.h"
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int lengs_of_postfix_form = 0;
	float amount = 0;
	char* strUser = new char[20];
	cout << " Enter: your expression ";
	cin.getline(strUser, 20);
	char tmp[10];
	char* post = PostfixForm(strUser, lengs_of_postfix_form);
	for (int i = 0; i < lengs_of_postfix_form; i++)
		tmp[i] = post[i];
	try
	{
		amount = Calculate(tmp, lengs_of_postfix_form);
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
