#include <iostream>
#include <ctime>
#include <string>
#include "TList.h"

using namespace std;

int main()
{
	cout << "Testing of List:"<<endl;
	TList<int, int> list;
	int* a = new int[5];
	for (int i = 0; i < 5; i++)
	{
		a[i] = i;
		list.Push(a, i);
	}
	list.Print();
	
		return 0;
}
