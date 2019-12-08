#include <iostream>
#include <ctime>
#include <string>
#include "TList.h"

using namespace std;
void BackTest()
{
	cout << "Testing of Back-function:" << endl;
	TList<double, double> list;
	double* a = new double[10]{ 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; i++)
	{
		list.Back((a + i), i);
		cout << list<<endl;
	}
	cout << list;
};
void CopyingConstructorTest()
{
	cout << "Testing of copying constructor:" << endl;
	cout << "First List is:" << endl;
	TList<double, double> list;
	double* a = new double[10]{ 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; i++)
	{
		list.Back((a + i), i);
	}
	cout << list;
	cout << "Second list s:" << endl;
	TList<double, double> copyList(list);
	cout << copyList;
};
void RemoveTest()
{
	cout << "Testing of Remove-function:" << endl;
	TList<double, double> list;
	double* a = new double[10]{ 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; i++)
	{
		list.Back((a + i), i);
		cout << list << endl;
	}
	cout << "List is:" << endl;
	cout << list;
	list.Remove(1);
	cout << "List after removing element with 1st key:" << endl;
	cout << list;
}
void PushTest()
{
	cout << "Testing of Push-function:" << endl;
	TList<double, double> list;
	double* a = new double[10]{ 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; i++)
	{
		list.Back((a + i), i);
	}
	cout << "List before Push" << endl;
	cout << list;
	cout << "List after Push" << endl;
	double* b = new double[3]{ 1,2,3 };
	list.Push(b, 23);
	cout << list;
};
void InsertAfterTest()
{
	cout << "Testing of InsertAfter-function:" << endl;
	TList<double, double> list;
	double* a = new double[10]{ 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; i++)
	{
		list.Back((a + i), i);
		cout << list << endl;
	}
	cout << "List before InsertA:" << endl;
	cout << list;
	cout << "List after InsertA:" << endl;
	double* b = new double{99};
	list.InsertAfter(8, b, 11);
	cout << list;
};
void InsertBeforeTest()
{
	cout << "Testing of InsertBefore-function:" << endl;
	TList<double, double> list;
	double* a = new double[10]{ 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; i++)
	{
		list.Back((a + i), i);
		cout << list << endl;
	}
	cout << "List before Insert:" << endl;
	cout << list;
	cout << "List after InsertB:" << endl;
	double* b = new double{99};
	list.InsertBefore(2, b, 11);
	cout << list;
};
int main()
{
	int n;
	do
	{

		cout << "Choose" << endl << "1-BackTest" << endl << "2-CopyingConstructorTest" << endl << "3- RemoveTest" << endl << "4- PushTest" << endl << "5-InsertAfterTest" << endl;
		cout << "6-InsertBeforeTest" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
		{
			BackTest();
			break;
		}
		case 2:
		{
			CopyingConstructorTest();
			break;
		}
		case 3:
		{
			RemoveTest();
			break;
		}
		case 4:
		{
			PushTest();
			break;
		}
		case 5:
		{
			InsertAfterTest();
			break;
		}
		case 6:
		{
			InsertBeforeTest();
			break;
		}
		case 7:
		{
			double* a = new double[10]{ 1,2,3,4,5,6,7,8,9,10 };
			for (int i = 0; i < 10; i++)
			{
				cout << a[i];
			};
			int d;
			cin >> d;
			break;
		}
		default:
			cout << "Wrong number";
		}
	} while (n != 7);

}
