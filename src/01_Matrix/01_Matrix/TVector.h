#pragma once
#include<iostream>
#include<math.h>
#include <exception>
using namespace std;
template<typename ValueType>
class TVector
{
protected:
	int size;
	ValueType* arr;
	int startindex;
public:
	TVector(int _size, int _startindex);
	TVector(int _size);
	TVector(const TVector& tmp);
	~TVector();

	TVector& operator=(const TVector& tmp)const;
	ValueType length() const;
	TVector operator+(const ValueType a);
	TVector operator-(const ValueType a);
	TVector operator*(const ValueType a);
	TVector operator+(const TVector& tmp);
	TVector operator-(const TVector& tmp);
	ValueType operator*(const TVector& tmp);
	bool operator==(const TVector& tmp)const;
	bool operator!=(const TVector& tmp)const;

	ValueType& operator[] (int i);
	const ValueType& operator[] (int i) const;

	friend istream& operator >> (istream& in, TVector& v)
	{
		for (int i = 0; i < v.size; i++)
			in >> v.arr[i];
		return in;
	}

	friend ostream& operator << (ostream& out, const TVector& v)
	{
		for (int i = 0; i < v.size; i++)
			out << v.arr[i] << " ";
		return out;
	}
};

template<typename VauleType>
TVector<VauleType>::TVector(int _size, int _startindex)
{
	size = _size;
	startindex = _startindex;
	arr = new VauleType[size];
}

template<typename VauleType>
TVector<VauleType>::TVector(int _size)
{
	size = _size;
	arr = new VauleType[size];
}

template<typename VauleType>
TVector<VauleType>::TVector(const TVector& tmp)
{
	size = tmp.size;
	startindex = tmp.startindex;
	arr = new VauleType[size];
	memcpy(tmp.arr, arr, sizeof(VauleType) * size);
}

template<typename VauleType>
TVector<VauleType>::~TVector()
{
	size = 0;
	delete[] arr;
}

template<typename VauleType>
TVector<VauleType>& TVector<VauleType>::operator=(const TVector& tmp)const
{
	if (*this == tmp)
		return *this;
	if (size != tmp.size)
	{
		delete[] arr;
		size = tmp.size;
		arr = new VauleType[size];
	}
	memcpy(tmp.arr, arr, sizeof(VauleType) * size);
	return *this;
}

template<typename ValueType>
ValueType TVector<ValueType>::length() const
{
	ValueType rez = 0;
	for (int i = 0; i < size; i++)
		rez += arr[i] * arr[i];
	return sqrt(rez);
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(const ValueType a)
{
	TVector rez = TVector(size);
	for (int i = 0; i < size; i++)
		rez.arr[i] = arr[i] + a;
	return rez;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator-(const ValueType a)
{
	TVector rez = TVector(size);
	for (int i = 0; i < size; i++)
		rez.arr[i] = arr[i] - a;
	return rez;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator*(const ValueType a)
{
	TVector rez = TVector(size);
	for (int i = 0; i < size; i++)
		rez.arr[i] = arr[i] * a;
	return rez;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(const TVector& tmp)
{
	if (size != tmp.size)
		throw "!size";
	TVector rez = TVector(size);
	for (int i = 0; i < size; i++)
		rez.arr[i] = arr[i] + tmp.arr[i];
	return rez;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator-(const TVector& tmp)
{
	if (size != tmp.size)
		throw "!size";
	TVector rez = TVector(size);
	for (int i = 0; i < size; i++)
		rez.arr[i] = arr[i] - tmp.arr[i];
	return rez;
}

template<typename ValueType>
ValueType TVector<ValueType>::operator*(const TVector& tmp)
{
	if (size != tmp.size)
		throw "!size";
	ValueType rez = 0;
	for (int i = 0; i < size; i++)
		rez += arr[i] * tmp.arr[i];
	return rez;
}

template<typename ValueType>
bool TVector<ValueType>::operator==(const TVector& tmp)const
{
	if (size != tmp.size)
		throw "!size";
	for (int i = 0; i < size; i++)
		if (arr[i] != tmp.arr[i])
			return false;
	return true;
}

template<typename ValueType>
bool TVector<ValueType>::operator!=(const TVector& tmp)const
{
	if (size != tmp.size)
		throw "!size";
	for (int i = 0; i < size; i++)
		if (arr[i] != tmp.arr[i])
			return true;
	return false;
}

template<typename ValueType>
ValueType& TVector<ValueType>::operator[] (int i)
{
	if ((i < 0) || (i >= size))
		throw "No elem";
	return arr[i];
}

template<typename ValueType>
const ValueType& TVector<ValueType>::operator[] (int i) const
{
	if ((i < 0) || (i >= size))
		throw "No elem";
	return arr[i];
}
