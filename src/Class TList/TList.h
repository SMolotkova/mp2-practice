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
	TList(const TNode<TData, TKey>* pNodeElem);
	TList(const TList& copyList);
	~TList();

	bool IsEnd()const;

	void Next();
	void Reset();

	TNode<TData, TKey>* Search(TKey);
	void Back(TData*, TKey);
	void Push(TData*, TKey);
	void InsertAfter(TKey, TData*, TKey);
	void InsertBefore(TKey, TData*, TKey);
	void Remove(TKey);


	friend ostream& operator << (ostream& out, TList<TData, TKey>& list)
	{
		list.Reset();
		while (!list.IsEnd())
		{
			out << list.pCurr->key << "-" << *(list.pCurr->pData) << endl;
			list.Next();
		}
		list.Reset();
		return out;
	}
};

template<class TData, class TKey>
TList<TData, TKey>::TList() : pFirst(nullptr), pPrev(nullptr), pCurr(nullptr), pNext(nullptr) {}

template<class TData, class TKey>
TList<TData, TKey>::TList(const TNode<TData, TKey>* pNodeElem)
{

	TNode<TKey, TData> *node = pNodeElem;
	pFirst = new TNode<TKey, TData>(node->key, node->pData);
	pCurr = pFirst;
	node = node->pNext;
	while (node != nullptr)
	{
		pCurr->pNext = new TNode<TKey, TData>(node->key, node->pData);
		pCurr = pCurr->pNext;
		node = node->pNext;
	}	
	Reset();
}

template<class TData, class TKey>
TList<TData, TKey>::TList(const TList<TData, TKey>& copyList)
{
	TNode<TKey, TData> *node = copyList.pFirst;
	pFirst = new TNode<TKey, TData>(node->key, node->pData);
	pCurr = pFirst;
	node = node->pNext;
	while (node != nullptr)
	{
		pCurr->pNext = new TNode<TKey, TData>(node->key, node->pData);
		pCurr = pCurr->pNext;
		node = node->pNext;
	}
	Reset();
}

template<class TData, class TKey>
TList<TData, TKey>::~TList()
{
	while (pFirst != nullptr)
	{
		pNext = pFirst->pNext;
		delete (pFirst->pData);
		delete pFirst;
		pFirst = pNext;
	}
}

template<class TData, class TKey>
bool TList<TData, TKey>::IsEnd()const
{
	return (pCurr == nullptr);
}

template<class TData, class TKey>
void TList<TData, TKey>::Reset()
{
	pCurr = pFirst;
	pPrev = nullptr;
	if (pFirst == nullptr)
	{
		pNext = nullptr;
		return;
	}
	pNext = pFirst->pNext;
	return;
}

template<class TData, class TKey>
void TList<TData, TKey>::Next()
{
	if (IsEnd()) return;
	pPrev = pCurr;
	pCurr = pNext;
	if (pNext != nullptr)
	{
		pNext = pNext->pNext;
	}
	else
	{
		pNext = nullptr;
	}
}

template<class TData, class TKey>
void TList<TData, TKey>::Back(TData* _pData, TKey _key)
{
	if (pFirst == nullptr)
	{
		pFirst = new TNode<TData, TKey>(_key, _pData);
		Reset();
	}
	else
	{
		TNode<TData, TKey> *cpCurr = pCurr, *cpPrev = pPrev, *cpNext = pNext;
		while (!IsEnd())
			Next();
		pPrev->pNext = new TNode<TData, TKey>(_key, _pData);
		pCurr = cpCurr;
		pPrev = cpPrev;
		pNext = cpNext;
	}	
}

template<class TData, class TKey>
TNode<TData, TKey>* TList<TData, TKey>::Search(TKey key)
{
	TNode<TData, TKey> *cpCurr = pCurr, *cpPrev = pPrev, *cpNext = pNext;
	TNode<TData, TKey>* searchedNode = nullptr;
	bool isFound = false;
	Reset();
	while (!IsEnd() || !isFound)
	{
		if (pCurr->key == key)
		{
			searchedNode = pCurr;
			isFound = true;
		}
		Next();
	}
	pCurr = cpCurr;
	pPrev = cpPrev;
	pNext = cpNext;
	return searchedNode;
}

template<class TData, class TKey>
void TList<TData, TKey>::Push(TData* _pData, TKey _key)
{
	TNode<TKey, TData>* node = new TNode<TData, TKey>(_key, _pData, pFirst);
	if (pCurr == pFirst)
	{
		pPrev = node;
	}
	pFirst = node;
}

template<class TData, class TKey>
void TList<TData, TKey>::InsertAfter(TKey key, TData* _pData, TKey newKey)//dodelat
{
	if (pCurr != pFirst)
		Reset();
	while (!IsEnd() && (pCurr->key != key))
		Next();
	TNode<TData, TKey>* node = new TNode<TData, TKey>(newKey, _pData);
	pCurr->pNext = node;
	node->pNext = pNext;
	Reset();
}

template<class TData, class TKey>
void TList<TData, TKey>::InsertBefore(TKey key, TData* _pData, TKey newKey)//dodelat
{
	if (Search(key) != nullptr)
	{
		if (pPrev == nullptr) Push(_pData, newKey);
		else
		{
			pPrev->pNext = new TNode<TKey, TData>;
			pPrev = pPrev->pNext;
			pPrev->pNext = pCurr;
			pPrev->key = newKey;
			pPrev->pData = new TData;
			*(pPrev->pData) = *_pData;
		}
	}
	return;
};

template<class TData, class TKey>
void TList<TData, TKey>::Remove(TKey _key)//dodelat
{
	if (pCurr != pFirst)
		Reset();
	while (!IsEnd() && (pCurr->key != _key))
		Next();
	if (pCurr == pFirst)
		pFirst = pCurr->pNext;
	else
		pPrev->pNext = pCurr->pNext;
	delete[] pCurr;
	pCurr = nullptr;
	Reset();
	return;
}
