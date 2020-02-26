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
	TList(const TList<TData, TKey>& copyList);
	~TList();

	bool IsEnd()const;

	void Next();
	void Reset();

	TNode<TData, TKey>* Search(TKey);
	void Back(TData*, TKey);
	void Push(TData*, TKey);
	void InsertAfter(TKey, TData*, TKey);
	void InsertBefore(TKey, TData*, TKey);
	void Remove(TKey _key);


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
	TNode<TData, TKey> *notnode = pFirst;
	TNode<TData, TKey> *next;
	while (notnode != nullptr)
	{
		next = notnode->pNext;
		delete notnode;
		notnode = next;
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
}

template<class TData, class TKey>
void TList<TData, TKey>::Next()
{
	if (IsEnd())
		throw "End of list!";
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
		{
			Next();
		}
		pPrev->pNext = new TNode<TData, TKey>(_key, _pData);
		pCurr = cpCurr;
		pPrev = cpPrev;
		if (cpNext = nullptr)
			pNext = pPrev->pNext;
		else
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
	while (!IsEnd() && !isFound)
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
	if (pFirst == nullptr)
	{
		pFirst = new TNode<TData, TKey>(_key, _pData);
		pCurr = pFirst;
		return;
	};
	TNode<TData, TKey>* node = new TNode<TData, TKey>(_key, _pData, pFirst);
	if (pCurr == pFirst)
		pPrev = node;
	pFirst = node;
}

template<class TData, class TKey>
void TList<TData, TKey>::InsertAfter(TKey _key, TData* _pData, TKey newKey)
{
	TNode<TData, TKey>* tmppCurrent = pCurr;
	TNode<TData, TKey>* tmppNext = pNext;
	TNode<TData, TKey>* tmppPrev = pPrev;
	this->Reset();
	TNode<TData, TKey>* node_search = Search(_key);

	if (!node_search)
	{
		throw "Key does not exist!";
	}

	while (pCurr != node_search)
		this->Next();

	TNode<TData, TKey>* node = new TNode<TData, TKey>(newKey, _pData, pNext);
	pCurr->pNext = node;

	if (tmppCurrent == pCurr)
	{
		pNext = node;
	}
	else
	{
		pNext = tmppNext;
	}
	if (tmppCurrent == pNext)
	{
		pPrev = node;
	}
	else
	{
		pPrev = tmppPrev;
	}

	pCurr = tmppCurrent;
}

template<class TData, class TKey>
void TList<TData, TKey>::InsertBefore(TKey key, TData* _pData, TKey newKey)
{
	TNode<TData, TKey>* pprev = pPrev;
	TNode<TData, TKey>* pcurr = pCurr;
	TNode<TData, TKey>* pnext = pNext;
	TNode<TData, TKey>* searchnode = new TNode<TData, TKey>();
	searchnode = pFirst;

	/*if (searchnode->key == nullptr)
	{
		throw "Not found";
		return;
	}*/
	TNode<TData, TKey>* node_search = Search(key);

	if (!node_search)
	{
		throw "Key does not exist!";
	}
	while ((searchnode->pNext->key != key) && (searchnode != nullptr))
	{
		searchnode = searchnode->pNext;
	}
	if (searchnode != nullptr)
	{
		if (searchnode != pFirst)
		{
			TNode<TData, TKey>* tmp = new TNode<TData, TKey>(newKey, _pData, searchnode->pNext);
			searchnode->pNext = tmp;
		}
		else
		{
			TNode<TData, TKey>* tmp = new TNode<TData, TKey>(newKey, _pData, pFirst);
			pFirst = tmp;
		}
		pPrev = pprev;
		pCurr = pcurr;
		pNext = pnext;
	}
};


template<class TData, class TKey>
void TList<TData, TKey>::Remove(TKey _key)
{
	if (pFirst == nullptr)
		throw "Error";
	if (pFirst->key == _key)
	{
		TNode<TData, TKey>*next = pFirst->pNext;
		if (pCurr == pFirst)
			pCurr = next;
		if (pPrev == pFirst)
			pPrev = nullptr;
		delete pFirst;
		pFirst = next;
		return;
	}
	TNode<TData, TKey>* prev = pFirst;
	while ((prev->pNext != nullptr) && (prev->pNext->key != _key))
	{
		prev = prev->pNext;
	}
	if (prev->pNext == nullptr)
		throw "Error find";
	TNode<TData, TKey>* next = prev->pNext->pNext;
	if (pCurr == prev->pNext)
	{
		pCurr = next;
		if (next == NULL)
		{
			throw "Error";
		}
		else
		pNext = next->pNext;

	}
	if (pNext == prev->pNext)
		pNext = next;
	if (pPrev == prev)
		pPrev = prev;
	if (pCurr == next)
		throw "Error";
	delete prev->pNext;
	prev->pNext = next;

};
