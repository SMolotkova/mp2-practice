#pragma once
#include <exception>
#include <iostream>
using namespace std;
class MyException : public ::exception
{
	virtual const char* what()
	{
		cout << "Wrong size";
	}
};