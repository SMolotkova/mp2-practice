#pragma once

#include "Stack.h"
#include <string>

using namespace std;

class myCalculator
{
private:
	static int Priority(char operation);
	static bool Compare_of_signs(char tmp, TStack<char>& sign);
public:
	static string PostfixForm(string your_expression);
	static double Calculate(string postfix_form);
};
