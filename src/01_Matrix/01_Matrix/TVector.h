#pragma once
#include<iostream>
#include <math.h>
#include "Exceptions.h"
using namespace std;
template<typename ValueType>
class TVector
{
//protected:
public:
	int size;
	ValueType* arr;
	int startindex;
//public:
	TVector(int _size = 3, int _startindex = 0);
	TVector(const TVector& tmp);
	~TVector();

	TVector<ValueType>& operator=(const TVector<ValueType>& tmp);
	double length() const;
	TVector<ValueType> operator+(const ValueType a);
	TVector<ValueType> operator-(const ValueType a);
	TVector<ValueType> operator*(const ValueType a);
	TVector<ValueType> operator+(const TVector<ValueType>& tmp);
	TVector<ValueType> operator-(const TVector& tmp);
	ValueType operator*(const TVector<ValueType>& tmp);
	bool operator==(const TVector<ValueType>& tmp)const;
	bool operator!=(const TVector<ValueType>& tmp)const;

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
		out << "[";
		for (int i = 0; i < v.size; i++)
		{
			out << v.arr[i];
			/*for (int q = 0; q < v.size-1; q++)
			{
				out << ",";
			}*/
		}
		out << "]";
		return out;
	}

	int StartIndex() const;
	int Size() const;
};

template<typename ValueType>
TVector<ValueType>::TVector(int _size, int _startindex)
{
	//if (size == 0)
	//	throw NoElements();
	//size = _size;
	//startindex = _startindex;
	//arr = new ValueType[size];
	size = _size;
	arr = new ValueType[size];
	startindex = _startindex;
	for (int i = 0; i < size; i++)
		arr[i] = 0;
}

template<typename ValueType>
TVector<ValueType>::TVector(const TVector& tmp)
{
	size = tmp.size;
	startindex = tmp.startindex;
	arr = new ValueType[size];
	for (int i = 0; i < size; i++)
		arr[i] = tmp.arr[i];
}

template<typename ValueType>
TVector<ValueType>::~TVector()
{
	startindex = 0;
	size = 0;
	delete[] arr;
	/*if (size > 0)
		delete[] arr;*/
}

template<typename ValueType>
TVector<ValueType>& TVector<ValueType>::operator=(const TVector<ValueType>& tmp)
{
	if (*this == tmp)
		return *this;
	if (size != tmp.size)
	{
		delete[] arr;
		arr = new ValueType[size];
		size = tmp.size;
	}
	startindex = tmp.startindex;
	memcpy(arr, tmp.arr, sizeof(ValueType) * size);
	return *this;
}

template<typename ValueType>
double TVector<ValueType>::length() const
{
	ValueType rez = 0;
	for (int i = 0; i < size; i++)
		rez += arr[i] * arr[i];
	return sqrt(rez);
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(const ValueType a)
{
	TVector<ValueType> rez = TVector(size);
	for (int i = 0; i < size; i++)
		rez.arr[i] = arr[i] + a;
	return rez;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator-(const ValueType a)
{
	TVector<ValueType> rez = TVector(size);
	for (int i = 0; i < size; i++)
		rez.arr[i] = arr[i] - a;
	return rez;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator*(const ValueType a)
{
	TVector<ValueType> rez = TVector(size);
	for (int i = 0; i < size; i++)
		rez.arr[i] = arr[i] * a;
	return rez;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(const TVector<ValueType>& tmp)
{
	if (size != tmp.size)
		throw DifferentSizeOfVectors();
	TVector<ValueType> rez = TVector(size);
	for (int i = 0; i < size; i++)
		rez.arr[i] = arr[i] + tmp.arr[i];
	return rez;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator-(const TVector<ValueType>& tmp)
{
	if (size != tmp.size)
		throw DifferentSizeOfVectors();
	TVector<ValueType> rez = TVector(size);
	for (int i = 0; i < size; i++)
		rez.arr[i] = arr[i] - tmp.arr[i];
	return rez;
}

template<typename ValueType>
ValueType TVector<ValueType>::operator*(const TVector<ValueType>& tmp)
{
	if (size != tmp.size)
		throw DifferentSizeOfVectors();
	ValueType rez = 0;
	for (int i = 0; i < size; i++)
		rez += arr[i] * tmp.arr[i];
	return rez;
}

template<typename ValueType>
bool TVector<ValueType>::operator==(const TVector<ValueType>& tmp)const
{
	if (size != tmp.size)
		return false;
	for (int i = 0; i < size; i++)
		if (arr[i] != tmp.arr[i])
			return false;
	return true;
}

template<typename ValueType>
bool TVector<ValueType>::operator!=(const TVector<ValueType>& tmp)const
{
	return !(*this == tmp);
}

template<typename ValueType>
ValueType& TVector<ValueType>::operator[] (int i)
{
	if ((i < 0) || (i >= size))
		throw NoElements();
	return arr[i];
}

template<typename ValueType>
const ValueType& TVector<ValueType>::operator[] (int i) const
{
	if ((i < 0) || (i >= size))
		throw NoElements();
	return arr[i];
}

template<typename ValueType>
int TVector<ValueType>::StartIndex() const
{
	return startindex;
}

template<typename ValueType>
int TVector<ValueType>::Size() const
{
	return size;
}