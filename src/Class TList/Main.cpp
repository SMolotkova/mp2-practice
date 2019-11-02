#include <iostream>
#include <ctime>
#include <string>
#include "TList.h"

using namespace std;

void main()
{
	////srand(time(0));
	////TList<string, int> L1;
	////int size;//размер массива pData
	////cout << "Enter Size of pData:\n" << endl;
	////cin >> size;	
	////int *pData = new int[size];
	////for (int i = 0; i != size; i++) 
	////{
	////	pData[size] = (rand() % 10 + 1) / int((rand() % 10 + 1));
	////}
	////L1.Push(pData,1);
	////L1.Push(pData, 2);
	////L1.printList();
	TList<string,int>myList;
	myList.Back(new string("srt1"),1);
	myList.Back(new string("srt2"),2);
	myList.Back(new string("srt3"),3);

	myList.Print();
}