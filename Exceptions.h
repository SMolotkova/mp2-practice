#pragma once
#pragma once
#include <string>
#include <exception>
using namespace std;
class DifferentSizeOfVectors : public exception
{
	const string what_Str = "Different size of vectors!\n";
public:
	const char* what() const
	{
		return what_Str.c_str();
	}
};

class DifferentSizeOfMatrix : public exception
{
	const string what_Str = "Different Size of matrix!\n";
public:
	const char* what() const
	{
		return what_Str.c_str();
	}
};
class NoElements : public exception
{
	const string what_Str = "Element doesn't exist!\n";
public:
	const char* what() const
	{
		return what_Str.c_str();
	}
};
