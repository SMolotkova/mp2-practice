#pragma once

#include <iostream>
#include "TVector.h"
#include "TMatrix.h"
#include "Exceptions.h"

using namespace std;

void Creating()
{
	cout << "Testing of vectors:" << endl;
	cout << "Constructor with parameters(2):" << endl;
	TVector<double> Vector1(3, 0);
	cout << "Enter Vector1 of 3 elements" << endl;
	cin >> Vector1;
	cout << "Vector1 is:" << Vector1 << endl;
	cout << "Constructor with parameter(1):" << endl;
	TVector<double> Vector2(3);
	cout << "Enter Vector2 of 3 elements:" << endl;
	cin >> Vector2;
	cout << "Vector2 is:" << Vector2 << endl;
}
void Copy_and_Deleting()
{
	TVector<double> Vector2(3);
	cout << "Enter Vector2 of 3 elements:" << endl;
	cin >> Vector2;
	TVector<double> CopyVector(Vector2);
	cout << "This vector is copy of Vector2:" << CopyVector << endl;
}
void Equality()
{
	cout << "Equal vectors" << endl;
	TVector<double> Vector1(3);
	cout << "Vector1 is (1,2,3) enter it :" << endl;
	cin >> Vector1;
	TVector<double> Vector2(3);
	cout << "Vector2 is (13,22,11) enter it :" << endl;
	cin >> Vector2;
	Vector1 = Vector2;
	cout << "Vector1 = Vector2:" << Vector1 << endl;

	cout << "For vectors with different sizes: " << endl;
	TVector<double> Vector3(5);
	cout << "Vector3 is (1,2,3,4,5) enter :" << endl;
	cin >> Vector3;
	Vector1 = Vector3;
	cout << "Vector1 = Vector3 : " << Vector1 << endl;
}
void Length()
{
	int l;
	cout << "Enter vector size" << endl;
	cin >> l;
	TVector<double> Vector1(l);
	cout << "Enter Vector1 of " << l << " elements" << endl;
	cin >> Vector1;
	cout << "Length of Vector1 is:" << Vector1.length() << endl;
}
void Sum_Diff()
{
	TVector<double> Vector1(3);
	cout << "Enter Vector1 of 3 elements" << endl;
	cin >> Vector1;
	TVector<double> Vector3(4);
	cout << "Enter Vector3 of 4 elements" << endl;
	cin >> Vector3;
	TVector<double> Vector2(3);
	cout << "Enter Vector2 of 3 elements:" << endl;
	cin >> Vector2;
	cout << "Sum with number:" << endl << "Enter number:" << endl;
	double number;
	cin >> number;
	Vector2 = Vector2 + number;
	cout << "Vector2+" << number << "=" << Vector2 << endl;
	cout << "Difference with number:" << endl << "Enter number:" << endl;
	int nnumber;
	cin >> nnumber;
	Vector2 = Vector2 - nnumber;
	cout << "Vector2-" << nnumber << "=" << Vector2 - nnumber << endl;
	cout << "Vector2+Vector1:" << Vector2 + Vector1 << endl;
	cout << "Vector2-Vector1:" << Vector2 - Vector1 << endl;
	try
	{
		cout << "Vector1+Vector3:" << endl;
		Vector1 = Vector1 + Vector3;
	}
	catch (DifferentSizeOfVectors& e)
	{
		cout << e.what();
	}
	try
	{
		cout << "Vector1+Vector3:" << endl;
		Vector1 = Vector1 - Vector3;
	}
	catch (DifferentSizeOfVectors& e)
	{
		cout << e.what();
	}

}
void Multiplication()
{
	TVector<double> Vector1(3);
	cout << "Enter Vector1 of 3 elements" << endl;
	cin >> Vector1;
	TVector<double> Vector3(4);
	cout << "Enter Vector3 of 4 elements" << endl;
	cin >> Vector3;
	TVector<double> Vector2(3);
	cout << "Enter Vector2 of 3 elements:" << endl;
	cin >> Vector2;

	cout << "Multiplication with number:" << endl << "Enter number:" << endl;
	int number;
	cin >> number;
	Vector2 = Vector2 * number;
	cout << "Vector2*:" << number << "=" << Vector2 << endl;

	cout << "Multiplication with vector:" << endl;
	TVector<double>VectorRes(3);
	VectorRes = Vector2 * Vector1;
	cout << "Vector2*Vector1: =" << Vector2 << endl;

	try
	{
		cout << "Vector1*Vector3" << endl;
		Vector1 = Vector1 * Vector3;
	}
	catch (DifferentSizeOfVectors& e)
	{
		cout << e.what();
	}
}
void Bool()
{
	TVector<double> Vector1(3);
	cout << "Enter Vector1 of 3 elements" << endl;
	cin >> Vector1;
	TVector<double> Vector3(4);
	cout << "Enter Vector3 of 4 elements" << endl;
	cin >> Vector3;
	TVector<double> Vector2(3);
	cout << "Enter Vector2 of 3 elements:" << endl;
	cin >> Vector2;

	if (Vector1 == Vector2)
		cout << "Vector1=Vector2" << endl;
	if (Vector1 != Vector2)
		cout << "Vector1 != Vector2 " << endl;
	if (Vector3 == Vector2)
		cout << "true" << endl;
	if (Vector3 != Vector2)
		cout << "Vector3 != Vector 2" << endl;
}
void Index()
{
	TVector<double> Vector1(3);
	cout << "Enter Vector1 of 3 elements" << endl;
	cin >> Vector1;

	try
	{
		int d;
		cout << "Enter number of element:" << endl;
		cin >> d;
		cout << "Element" << d << "is: " << Vector1[d] << endl;
	}
	catch (NoElements& n)
	{
		cout << n.what();
	}
}

void MCreation()
{
	cout << "Testing of matrix:" << endl;
	TMatrix<double> Matrix1(3);
	cout << "Enter Matrix1:" << endl;
	cin >> Matrix1;
	cout << "Matrix1 1 is:" << endl << Matrix1;
	int m;
	cin >> m;
}
void MAdd_Diff_Number()
{
	cout << "Adding Number 2:" << endl;
	TMatrix<double> Matrix1(3);
	cout << "Enter Matrix1:" << endl;
	cin >> Matrix1;
	cout << "Matrix1 + 2 is :" << endl << Matrix1 + 2;
	cout << "Matrix1 - 2 is :" << endl << Matrix1 - 2;
	int m;
	cin >> m;
}
void Matrix_Number_Multiplication()
{
	cout << "Matrix Multiplication:" << endl;
	cout << "NormaL situation :" << endl;
	TMatrix<double> Matrix1(3);
	cout << "Enter Matrix1:" << endl;
	cin >> Matrix1;
	TMatrix<double> Matrix2(3);
	cout << "Enter Matrix2:" << endl;
	cin >> Matrix2;
	cout << "Matrix1*Matrix2: \n" << Matrix1 * Matrix2 << endl;
	cout << "Matrix1*3: \n" << Matrix1 * 3 << endl;
	cout << "Exception situation:" << endl;
	try
	{
		cout << "Matrix Multiplication:" << endl;
		TMatrix<double> Matrix1(3);
		cout << "Enter Matrix1(3*3):" << endl;
		cin >> Matrix1;
		TMatrix<double> Matrix2(2);
		cout << "Enter Matrix2(2*2):" << endl;
		cin >> Matrix2;
		cout << "Matrix1*Matrix2:" << Matrix1 * Matrix2 << endl;
	}
	catch (DifferentSizeMatrix& n)
	{
		cout << n.what();
	}

}
void MAdd_Diff_Matrix()
{
	cout << "Matrix Adding:" << endl;
	cout << "NormaL situation :" << endl;
	TMatrix<double> Matrix1(3);
	cout << "Enter Matrix1(3*3):" << endl;
	cin >> Matrix1;
	TMatrix<double> Matrix2(3);
	cout << "Enter Matrix2(3*3):" << endl;
	cin >> Matrix2;
	cout << "Matrix1+Matrix2:" << endl << Matrix1 + Matrix2;
	cout << "Exception situation:" << endl;
	try
	{
		cout << "MDiff:" << endl;
		TMatrix<double> Matrix1(3);
		cout << "Enter Matrix1(3*3):" << endl;
		cin >> Matrix1;
		TMatrix<double> Matrix2(2);
		cout << "Enter Matrix2(2*2):" << endl;
		cin >> Matrix2;
		cout << "Matrix1+Matrix2: \n" << endl << Matrix1 + Matrix2 << endl;
		cout << "Matrix1-Matrix2 \n" << endl << Matrix1 - Matrix2 << endl;
	}
	catch (DifferentSizeMatrix& n)
	{
		cout << n.what();
	}

}
void MandV()
{
	cout << "Matrix * Vector:" << endl;
	cout << "NormaL situation :" << endl;
	TMatrix<double> Matrix1(3);
	cout << "Enter Matrix1(3*3):" << endl;
	cin >> Matrix1;
	TVector<double> Vector1(3);
	cout << "Enter Vector1 of 3 elements" << endl;
	cin >> Vector1;
	TVector<double>result(3);
	result = Matrix1 * Vector1;
	cout << "Matrix1*Vector1:\n" << endl << result << endl;
	try
	{
		cout << "Exception situation:" << endl;
		TMatrix<double> Matrix2(3);
		cout << "Enter Matrix2(3*3):" << endl;
		cin >> Matrix2;
		TVector<double> Vector2(4);
		cout << "Enter Vector2 of 4 elements" << endl;
		cin >> Vector1;
		cout << "Matrix2*Vector2:\n" << endl << Matrix2 * Vector2;
	}
	catch (DifferentSizeMatrix& n)
	{
		cout << n.what();
	}

}
int main()
{
	int n;
	do
	{

		cout << "Choose" << endl << "1-Creating" << endl << "2-Copy_and_Deleting" << endl << "3-Equality" << endl << "4-Length" << endl << "5-Sum_Diff" << endl;
		cout << "6-Multiplication" << endl << "7-Bool" << endl << "8-Index" << endl;
		cout << "9-MCreation" << endl << "10-MAdd_Diff_Number" << endl << "11- Matrix_Number_Multiplication" << endl << "12-MAdd_Diff_Matrix" << endl << "13-MandV" << endl;
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
			cout << "Length";
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
		case 9:
		{
			MCreation();
			break;
		}
		case 10:
		{
			MAdd_Diff_Number();
			break;
		}
		case 11:
		{
			Matrix_Number_Multiplication();
			break;
		}
		case 12:
		{
			MAdd_Diff_Matrix();
			break;
		}
		case 13:
		{
			MandV();
			break;
		}
		default:
			cout << "Wrong number";
		}
	} while (n != 13);
}
