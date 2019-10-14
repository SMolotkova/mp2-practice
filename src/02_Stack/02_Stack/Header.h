#pragma once

#include "Stack.h"

using namespace std;

class myCalculator
{
private:
	static int Priority(char operation);
	static bool Compare_of_signs(char tmp, TStack<char>& sign);
public:
	static char* PostfixForm(char* your_expression, int &lengs_of_postfix_form);
	static double Calculate(char PostfixForm[], int lengs_of_postfix_form);
};
