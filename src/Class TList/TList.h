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


	friend ostream& operator << (ostream& out, TList<TData,TKey>& list)
	{
		list.Reset();
		while (!list.IsEnd())
		{
			out << list.pCurr->key << "-" << *list.pCurr->pData << endl;
			list.Next();
		}
		return out;
	}
};

template<class TData, class TKey>
TList<TData, TKey>::TList() : pFirst(nullptr), pPrev(nullptr), pCurr(nullptr), pNext(nullptr) {}

template<class TData, class TKey>
TList<TData, TKey>::TList(const TNode<TData, TKey>* pNodeElem)
{

	TNode<TKey, TData> *node = pNodeElem;
	while (node->pNext != nullptr)
	{
		if (pFirst == nullptr)
		{
			pCurr = new TNode<TKey, TData>(node->key, node->pData);
			pFirst = pCurr;
			pPrev = nullptr;
		}
		else
		{
			pPrev = pCurr;
			pCurr = new TNode<TKey, TData>(node->key, node->pData);
			pPrev->pNext = pCurr;
		}
		node = node->pNext;
	}
	pPrev = pCurr;
	pCurr = new TNode<TKey, TData>(node->key, node->pData);
	pPrev->pNext = pCurr;
	pNext = nullptr;
	Reset();
}

template<class TData, class TKey>
TList<TData, TKey>::TList(const TList<TData, TKey>& copyList)
{
	if (copyList.pCurr != copyList.pFirst)
		throw "";
	TNode<TData, TKey> *node = copyList.pCurr;
	while (node->pNext != nullptr)
	{
		if (pFirst == nullptr)
		{
			pCurr = new TNode<TData, TKey>(node->key, node->pData);
			pFirst = pCurr;
			pPrev = nullptr;
		}
		else
		{
			pPrev = pCurr;
			pCurr = new TNode<TData, TKey>(node->key, node->pData);
			pPrev->pNext = pCurr;
		}
		node = node->pNext;
	}
	pPrev = pCurr;
	pCurr = new TNode<TData,TKey>(node->key, node->pData);
	pPrev->pNext = pCurr;
	pNext = nullptr;
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
//	return (pCurr = nullptr);
	if ((pCurr == nullptr) || (pNext == nullptr))
		return true;
	return false;
}

template<class TData, class TKey>
void TList<TData, TKey>::Reset()
{
	pCurr = pFirst;
	pPrev = nullptr;
	if (!pFirst)
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
	pNext = (this->pNext)->pNext;
}

template<class TData, class TKey>
void TList<TData, TKey>::Back(TData* _pData, TKey _key)
{
	if (pFirst == nullptr)
	{
		pCurr = new TNode<TData, TKey>;
		pFirst = pCurr;
		pFirst->pData = new TData;
		*(pFirst->pData) = *_pData;
		pFirst->key = _key;
		pFirst->pNext = nullptr;
	}
	else
	{
		while (!IsEnd())
			Next();
		pNext = new TNode<TData, TKey>;
		pCurr->pNext = pNext;
		pNext->pData = new TData;
		*(pNext->pData) = *_pData;
		pNext->key = _key;
		pNext->pNext = nullptr;
	}
	Reset();
}

template<class TData, class TKey>
TNode<TData, TKey>* TList<TData, TKey>::Search(TKey key)
{
	while (!IsEnd())
	{
		if (pCurr->key == key)
		{
			Reset();
			return pCurr;
		}
		Next();
	}
	Reset();
	return nullptr;
}

template<class TData, class TKey>
void TList<TData, TKey>::Push(TData* _pData, TKey _key)
{
	TNode<TKey, TData>* node = new TNode<TData, TKey>;
	node->pData = new TData;
	*(node->pData) = *_pData;
	node->key = _key;
	node->pNext = pFirst;
	pFirst = node;
	Reset();
}

template<class TData, class TKey>
void TList<TData, TKey>::InsertAfter(TKey key, TData* _pData, TKey newKey)
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
void TList<TData, TKey>::InsertBefore(TKey key, TData* _pData, TKey newKey)
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
void TList<TData, TKey>::Remove(TKey _key)
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
