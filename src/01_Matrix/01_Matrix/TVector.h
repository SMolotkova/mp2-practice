#pragma once
#include<iostream>
#include<math.h>
#include "Exceptions.h"
using namespace std;
template<typename ValueType>
class TVector
{
public:
	int size;
	ValueType* arr;
	int startindex;
	TVector();
	TVector(int _size, int _startindex);
	TVector(int _size);
	TVector(const TVector& tmp);
	~TVector();

	TVector& operator=(const TVector& tmp);
	double length() const;
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

	friend istream& operator >> (istream& in, TVector<ValueType>& v)
	{
		for (int i = 0; i < v.size; i++)
			in >> v.arr[i];
		return in;
	}

	friend ostream& operator << (ostream& out, const TVector<ValueType>& v)
	{
		out << "[";
		for (int i = 0; i < v.size; i++)
		{
			out << v.arr[i] << " ";
			/*for (int y = 0; y < v.size-1; y++
			{
				out << ",";
			}*/
		}
		out << "]";
		return out;
	}

	int Startindex() const;
	int Size() const;
};

template<typename T>
TVector<T>::TVector()
{
	//this->size = 0; 
	//this->startindex = 0; 
}

template<typename ValueType>
TVector<ValueType>::TVector(int _size, int _startindex)
{
	this->size = _size;
	this->startindex = _startindex;
	this->arr = new ValueType[this->size];
}

template<typename ValueType>
TVector<ValueType>::TVector(int _size)
{
	this->size = _size;
	this->arr = new ValueType[this->size];
}

template<typename ValueType>
TVector<ValueType>::TVector(const TVector<ValueType>& tmp)
{
	this->size = tmp.size;
	this->startindex = tmp.startindex;
	this->arr = new ValueType[this->size];
	//memcpy(arr, tmp.arr, sizeof(ValueType) * size);
	for (int i = 0; i < this->size; i++)
		this->arr[i] = tmp.arr[i];
}

template<typename ValueType>
TVector<ValueType>::~TVector()
{
	this->size = 0;
	//delete[] arr;
}

template<typename ValueType>
TVector<ValueType>& TVector<ValueType>::operator=(const TVector<ValueType>& tmp)
{
	if (*this == tmp)
		return *this;
	if (this->size != tmp.size)
	{
		//delete[] arr;
		this->size = tmp.size;
		this->arr = new ValueType[this->size];
	}
	this->startindex = tmp.startindex;
	//memcpy(arr, tmp.arr, sizeof(ValueType) * size);
	for (int i = 0; i < this->size; i++)
		this->arr[i] = tmp.arr[i];
	return *this;
}

template<typename ValueType>
double TVector<ValueType>::length() const
{
	ValueType rez = 0;
	for (int i = 0; i < this->size; i++)
		rez += this->arr[i] * this->arr[i];
	return sqrt(rez);
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(const ValueType a)
{
	TVector<ValueType> rez = TVector(size);
	//TVector<ValueType> rez(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] + a;
	return rez;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator-(const ValueType a)
{
	TVector<ValueType> rez = TVector(size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] - a;
	return rez;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator*(const ValueType a)
{
	TVector<ValueType> rez = TVector(size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] * a;
	return rez;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator+(const TVector<ValueType>& tmp)
{
	if (this->size != tmp.size)
		throw DifferentSizeOfVectors();
	TVector<ValueType> rez = TVector(size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] + tmp.arr[i];
	return rez;
}

template<typename ValueType>
TVector<ValueType> TVector<ValueType>::operator-(const TVector<ValueType>& tmp)
{
	if (this->size != tmp.size)
		throw DifferentSizeOfVectors();
	TVector<ValueType> rez = TVector(size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] - tmp.arr[i];
	return rez;
}

template<typename ValueType>
ValueType TVector<ValueType>::operator*(const TVector<ValueType>& tmp)
{
	if (this->size != tmp.size)
		throw DifferentSizeOfVectors();
	ValueType rez = 0;
	for (int i = 0; i < this->size; i++)
		rez += this->arr[i] * tmp.arr[i];
	return rez;
}

template<typename ValueType>
bool TVector<ValueType>::operator==(const TVector<ValueType>& tmp)const
{
	if (this->size != tmp.size)
		return false;
	for (int i = 0; i < tmp.size; i++)
		if (this->arr[i] != tmp.arr[i])
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
	if ((i < 0) || (i >= this->size))
		throw NoElements();
	return this->arr[i];
}

template<typename ValueType>
const ValueType& TVector<ValueType>::operator[] (int i) const
{
	if ((i < 0) || (i >= this->size))
		throw NoElements();
	return this->arr[i];
}

template<typename ValueType>
int TVector<ValueType>::Startindex() const
{
	return startindex;
}

template<typename ValueType>
int TVector<ValueType>::Size() const
{
	return size;
}
