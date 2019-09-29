#pragma once
#include <iostream>
#include "TVector.h"
#include "Tmatrix.h"
#include "Exceptions.h"
using namespace std;

void Creating()
{
	cout << "Testing of vectors:" << endl;
	cout << "Constructor with parameters(2):" << endl;
	TVector<int> Vector1(3, 2);
	cout << "Enter Vector1 of 3 elements" << endl;
	cin >> Vector1;
	cout << "Vector1 is:" << Vector1 << endl;
	cout << "Constructor with parameter(1):" << endl;
	TVector<int> Vector2(3);
	cout << "Enter Vector2 of 3 elements:" << endl;
	cin >> Vector2;
	cout << "Vector2 is:" << Vector2 << endl;
}
void Copy_and_Deleting()
{
	TVector<int> Vector2(3);
	cout << "Enter Vector2 of 3 elements:" << endl;
	cin >> Vector2;
	TVector<int> CopyVector(Vector2);
	cout << "This vector is copy of Vector2:" << CopyVector << endl;
	CopyVector.~TVector();
}
void Equality()
{
	cout << "Equal vectors" << endl;
	TVector<int> Vector1(3);
	cout << "Vector1 is 1,2,3, enter :" << endl;
	cin >> Vector1;
	TVector<int> Vector2(3);
	cout << "Vector2 is 1,2,3, enter :" << endl;
	cin >> Vector2;
	Vector1 = Vector2;
	cout << "Vector1 is:" << Vector1 << endl;
	cout << "Not equal vectors" << endl;
	TVector<int> Vector3(3);
	cout << "Vector3 is 1,5,11, enter :" << endl;
	cin >> Vector3;
	Vector1 = Vector3;
	cout << "Vector1 is:" << Vector1 << endl;
}
void Length()
{
	int l;
	cout << "Enter vector size" << endl;
	cin >> l;
	TVector<int> Vector1(l);
	cout << "Enter Vector1 of " << l << "elements" << endl;
	cin >> Vector1;
	cout << "Length of Vector1 is:" << Vector1.length() << endl;
}
void Sum_Diff()
{
	TVector<int> Vector1(3);
	cout << "Enter Vector1 of 3 elements" << endl;
	cin >> Vector1;
	TVector<int> Vector3(4);
	cout << "Enter Vector3 of 4 elements" << endl;
	cin >> Vector3;
	TVector<int> Vector2(3);
	cout << "Enter Vector2 of 3 elements:" << endl;
	cin >> Vector2;
	cout << "Sum with number:" << endl << "Enter number:" << endl;
	int number;
	cin >> number;
	Vector2 = Vector2 + number;
	cout << "Vector2+:" << number << "=" << Vector2 << endl;
	cout << "Difference with number:" << endl << "Enter number:" << endl;
	int nnumber;
	cin >> nnumber;
	Vector2 = Vector2 - nnumber;
	cout << "Vector2-:" << nnumber << "=" << Vector2 << endl;
	cout << "Sum with vectors:" << Vector2 + Vector1 << endl;
	cout << "Diff of vectors:" << Vector2 - Vector1 << endl;
	try
	{
		Vector1 = Vector1 + Vector3;
	}
	catch (const char* s)
	{
		cout << s;
	}
	try
	{
		Vector1 = Vector1 - Vector3;
	}
	catch (const char* s)
	{
		cout << s;
	}

}
void Multiplication()
{
	TVector<int> Vector1(3);
	cout << "Enter Vector1 of 3 elements" << endl;
	cin >> Vector1;
	TVector<int> Vector3(4);
	cout << "Enter Vector3 of 4 elements" << endl;
	cin >> Vector3;
	TVector<int> Vector2(3);
	cout << "Enter Vector2 of 3 elements:" << endl;
	cin >> Vector2;

	cout << "Multiplication with number:" << endl << "Enter number:" << endl;
	int number;
	cin >> number;
	Vector2 = Vector2 * number;
	cout << "Vector2*:" << number << "=" << Vector2 << endl;

	cout << "Multiplication with vector:" << endl;
	Vector2 = Vector2 * Vector1;
	cout << "Vector2*Vector1: =" << Vector2 << endl;

	try
	{
		Vector1 = Vector1 * Vector3;
	}
	catch (const char* s)
	{
		cout << s;
	}
}
void Bool()
{
	TVector<int> Vector1(3);
	cout << "Enter Vector1 of 3 elements" << endl;
	cin >> Vector1;
	TVector<int> Vector3(4);
	cout << "Enter Vector3 of 4 elements" << endl;
	cin >> Vector3;
	TVector<int> Vector2(3);
	cout << "Enter Vector2 of 3 elements:" << endl;
	cin >> Vector2;

	if (Vector1 == Vector2)//исключение разные размеры
		cout << "true" << endl;
	if (Vector1 != Vector2)//исключение разные размеры
		cout << "wrong" << endl;

	try
	{
		if (Vector1 == Vector3)
			cout << "true";
	}
	catch (const char* s)
	{
		cout << s;
	}

	try
	{
		if (Vector1 != Vector3)
			cout << "wrong";
	}
	catch (const char* s)
	{
		cout << s;
	}
}
void Index()
{
	TVector<int> Vector1(3);
	cout << "Enter Vector1 of 3 elements" << endl;
	cin >> Vector1;

	cout << Vector1[1];
	try
	{
		cout << Vector1[111];
	}
	catch (const char* s)
	{
		cout << s;
	}
}

int main()
{
	int n;
	do {
		cout << "Choose 1-Creating" << endl << "2-Copy_and_Deleting" << endl << "3-Equality" << endl << "4-Length" << endl << "5-Sum_Diff" << endl << "6-Multiplication" << endl << "7-Bool" << endl << "8-Index" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
		{
			Creating();
			break;
		}
		case 2:
		{
			Copy_and_Deleting();
			break;
		}
		case 3:
		{
			Equality();
			break;
		}
		case 4:
		{
			Length();
			break;
		}
		case 5:
		{
			Sum_Diff();
			break;
		}
		case 6:
		{
			Multiplication();
			break;
		}
		case 7:
		{
			Bool();
			break;
		}
		case 8:
		{
			Index();
			break;
		}
		default:
			cout << "Wrong number";
		}
	} while (n != 8);
}
