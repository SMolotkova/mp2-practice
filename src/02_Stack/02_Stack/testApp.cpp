// testApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

template<typename TData>
struct Node
{
    int key;
    TData* pData;
    Node* pNext;
    Node()
        :key(0)
        ,pData(nullptr)
        ,pNext(nullptr)
    {}

    Node(int _key, TData* _pData)
        : key(_key)
        , pData(_pData)
        , pNext(nullptr)
    {}
};
template<typename TData>
class List
{
public:
    List()
        : pFirst(nullptr) 
    {};

    void PrintAll()
    {
        Node<TData>* pCurretElem = pFirst;
        while (pCurretElem != nullptr)
        {
            cout << pCurretElem->key << " " << *pCurretElem->pData << endl;
            pCurretElem = pCurretElem->pNext;
        }
    };
    void InsertEnd(const Node<TData>* const pElem)
    {
        if (pFirst == nullptr)
        {
            pFirst = new Node<TData>(pElem->key,pElem->pData);
            return;
        }
        Node<TData>* pCurrentElem = pFirst;
        while (pCurrentElem->pNext != nullptr)
        {
            pCurrentElem = pCurrentElem->pNext;
        }
        pCurrentElem->pNext = new Node<TData>(pElem->key, pElem->pData);
    }
private:
    Node<TData>* pFirst;
};


int main()
{

    List<string>myList;
    myList.InsertEnd(new Node<string>(1, new string("srt1")));
    myList.InsertEnd(new Node<string>(2, new string("srt2")));
    myList.InsertEnd(new Node<string>(3, new string("srt3")));

    myList.PrintAll();

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
