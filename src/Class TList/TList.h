#pragma once
#include <iostream>
#include "TNode.h"

using namespace std;

template<class TData, class TKey>
class TList
{
private:
	TNode<TData, TKey>* pFirst;
	TNode<TData, TKey>* pPrev;
	TNode<TData, TKey>* pCurr;
	TNode<TData, TKey>* pNext;
public:
	TList();
	TList(const TNode<TData, TKey>*);
	TList(const TList&);
	~TList();

	bool IsEnd();

	void Next();
	void Reset();

	TNode<TData, TKey>* Search(TKey);
	void Back(TData*, TKey);
	void Push(TData*, TKey);
	void InsertAfter(TKey, TData*, TKey);
	void InsertBefore(TKey, TData*, TKey);
	void Remove(TKey);


	void Print()
	{
		/*TNode<TData, TKey>* Curr = pFirst;
		while (Curr)
		{
			cout << Curr->key << "-" << *Curr->pData << endl;
			Curr = Curr->pNext;
		}*/
		
		TNode<TData, TKey>* Curr = pFirst;
		while (!IsEnd())
		{
			cout << Curr->key <<"-"<< *Curr->pData << ' ';
			Next();
		}
		//cout << *pCurr->pData;
		//return;
	}

};

template<class TData, class TKey>
TList<TData, TKey>::TList() : pFirst(0), pPrev(0), pCurr(0), pNext(0) {}

template<class TData, class TKey>
TList<TData, TKey>::TList(const TNode<TData, TKey>* list)
{
	pFirst = list;
	pPrev = nullptr;
	pCurr = pFirst;
	pNext = nullptr;
}

template<class TData, class TKey>
TList<TData, TKey>::TList(const TList<TData, TKey>& list)
{
	pFirst = new TNode<TData, TKey>(list.pFirst);
	pCurr = pFirst;
	pPrev = nullptr;
	list.Reset();
	list.Next();
	while (!list.IsEnd())
	{
		pCurr = new TNode< TData, TKey>(list.pCurr);
		pCurr = pCurr->pNext;
		list.Next();
	}
	this->Reset();
}

template<class TData, class TKey>
TList<TData, TKey>::~TList()
{
	if (pCurr != pFirst)
		Reset();
	while (!IsEnd())
	{
		//pCurr.Remove(pFirst->key);
		Next();
		delete[] pPrev;
	}
	delete[] pCurr;
}

template<class TData, class TKey>
bool TList<TData, TKey>::IsEnd()
{
	return pCurr = nullptr;
}

template<class TData, class TKey>
void TList<TData, TKey>::Reset()
{
	pCurr = pFirst;
	pPrev = nullptr;
	if (pFirst != 0)
		pNext = pCurr->pNext;
	else
		pNext = nullptr;
}

template<class TData, class TKey>
void TList<TData, TKey>::Next()
{
	if (IsEnd())
		throw "Empty!";
	pPrev = pCurr;
	pCurr = pNext;
	if (pCurr != 0)
		pNext = pCurr->pNext;
}

template<class TData, class TKey>
void TList<TData, TKey>::Back(TData* _pData, TKey _key)
{
	Reset();
	while (!IsEnd())
		Next();

	TNode<TData, TKey>* node = new TNode<TData, TKey>(_pData, _key);
	pCurr->pNext = node;
	Reset();
}

template<class TData, class TKey>
TNode<TData, TKey>* TList<TData, TKey>::Search(TKey _key)
{
	/*while ((pFirst != nullptr) && (pFirst->key != _key))
		pFirst = pFirst->pNext;
	return pFirst;*/
	while (!IsEnd())
	{
		if (pCurr->key == _key)
		{
			Reset();
			return pCurr;
		};
		Next();
	}

	Reset();
	return nullptr;
}

template<class TData, class TKey>
void TList<TData, TKey>::Push(TData* _pData, TKey _key)
{
	Reset();
	TNode<TData, TKey>* node = new TNode<TData, TKey>(_key, _pData, pFirst);
	pNext = pFirst;
	pFirst = node;
	pCurr = pFirst;
	Reset();
}

template<class TData, class TKey>
void TList<TData, TKey>::InsertAfter(TKey key, TData* _pData, TKey newKey)
{
	Reset();

	TNode<TData, TKey>* node = Search(key);
	if (node == nullptr)
		throw "  Key didn't find";

	TNode<TData, TKey>* _node = new TNode<TData, TKey>( _pData, key);
	pPrev = pCurr;
	pCurr = node;

	Reset();
	return;
}

template<class TData, class TKey>
void TList<TData, TKey>::InsertBefore(TKey key, TData* _pData, TKey newKey)
{
	Reset();

	if (IsEnd())
	{
		Push( _pData, newKey);
		return;
	}

	TNode<TKey, TData>* node = Search(key);
	if (node == nullptr)
		throw "  Key didn't find";

	TNode<TData, TKey>* _node = new TNode<TData, TKey>(key, _pData, pCurr);
	pNext = pCurr;
	pPrev->pNext = _node;
	pCurr = _node;

	Reset();
	return;
};

template<class TData, class TKey>
void TList<TData, TKey>::Remove(TKey key)
{
	Reset();

	if (!pFirst)
		throw "  List is Empty";

	if (pFirst->key == key)
	{
		delete pFirst;
		pFirst = pNext;
		return;
	}

	TNode<TKey, TData>* node = Search(key);

	if (node == nullptr)
		throw "  Key didn't find";

	pPrev->pNext = pNext;
	delete node;

	Reset();
	return;
};
