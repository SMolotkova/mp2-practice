#pragma once
#include <string>
#include <exception>
using namespace std;
class FullStack : public exception
{
	const string what_Str = "Stack is full!\n";
public:
	const char* what() const
	{
		return what_Str.c_str();
	}
};

class EmptyStack : public exception
{
	const string what_Str = "Stack is Empty!\n";
public:
	const char* what() const
	{
		return what_Str.c_str();
	}
};
class WrongDivision : public exception
{
	const string what_Str = "You can't divide by 0! \n";
public:
	const char* what() const
	{
		return what_Str.c_str();
	}
};
class WrongIndex : public exception
{
	const string what_Str = "Wrong index!\n";
public:
	const char* what() const
	{
		return what_Str.c_str();
	}
};