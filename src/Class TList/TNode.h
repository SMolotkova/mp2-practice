#pragma once
#include <iostream>

template<class TData, class TKey>
class TNode
{
public:
	TData* pData;
	TKey key;
	TNode* pNext;

	TNode(TNode*);
	TNode(TKey, TData*, TNode*);
	TNode();
	TNode(TData*, TKey);
	TNode(const TNode&);
	~TNode();
};

template<class TData, class TKey>
TNode<TData, TKey>::TNode() : pData(nullptr), key(0), pNext(nullptr) {}

template<class TData, class TKey>
TNode<TData, TKey>::TNode(TData* _pData, TKey _key) : pData(_pData), key(_key), pNext(0) {}

template<class TData, class TKey>
TNode<TData, TKey>::TNode(const TNode<TData, TKey> &node) : pData(node.pData), key(node.key), pNext(node.pNext) {}

template<class TData, class TKey>
TNode<TData, TKey>::~TNode()
{
	key = 0;
	delete[] pData;
	pNext = nullptr;
}

template<class TData, class TKey>
TNode<TData,TKey>::TNode(TKey _key, TData* _pData, TNode* _node)
{
	key = _key;
	pData =  _pData;
	pNext = _node;
}

template<class TData, class TKey>
TNode<TData, TKey> :: TNode(TNode<TData, TKey>* tmp)
{
	key = tmp->key;
	pData = new TData;
	*pData = *tmp->pData;
	pNext = tmp->pNext;
}