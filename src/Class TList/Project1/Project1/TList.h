#pragma once
#include "TNode.h"

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
	TList(TNode<TData, TKey>*);
	TList(const TList&);
	~TList();
	bool IsEnd() const;
	void Next();
	void Reset();
	TNode<TData, TKey>* Search(TKey);
	void Back(TData*, TKey);
	void Push(TData*, TKey);
	void InsertAfter(TKey, TData*, TKey);
	void InsertBefore(TKey, TData*, TKey);
	void Remove(TKey);
};

template<class TData, class TKey>
TList<TData, TKey>::TList(): pFirst(0), pPrev(0), pCurr(0), pNext(0){}

template<class TData, class TKey>
TList<TData, TKey>::TList(TNode<TData, TKey>* list)
{
	pFirst = list;
	pPrev = nullptr;
	pCurr = pFirst;
	pNext = pFirst->pNext;
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
	this ->Reset();
}

template<class TData, class TKey>
TList<TData, TKey>::~TList()
{
	Reset();
	while (!list.IsEnd())
	{
		pCurr.Remove(pFirst->key);
	}
}

template<class TData, class TKey>
bool TList<TData, TKey>:: IsEnd() const
{
	return pCurr = nullptr;
}

template<class TData, class TKey>
void TList<TData, TKey>::Reset()
{
	pPrev = nullptr;
	pCurr = pFirst;
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
void TList<TData, TKey>::Back(TData* _data, TKey _key)
{
	/*if (IsEnd())
	{
		pPrev->pNext = new TNode<TData, TKey>(_key, _data);
	}*/
	TNode<TData, TKey>* tmpFirst = pFirst;
	TNode<TData, TKey>* tmpPrev = pPrev;
	TNode<TData, TKey>* tmpCurr = pCurr;
	TNode<TData, TKey>* tmpNext = pNext;

	while (!IsEnd())
		Next();
	pPrev->pNext = new TNode<TData, TKey>(_key, _data)
	pPrev = tmpPrev;
	pCurr = tmpCurr;
	pNext = tmpNext;
}

template<class TData, class TKey>
TNode<TData, TKey>* TList<TData, TKey>::Search(TKey _key)
{
	while ((pFirst != nullptr) && (pFirst->key != _key))
		pFirst = pFirst->pNext;
	return pFirst;
}