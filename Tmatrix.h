#pragma once
#pragma once
#include "TVector.h"
#include<iostream>
using namespace std;
template<typename ValueType>
class TMatrix : public TVector<TVector<ValueType> >
{
public:
	TMatrix(int _size = 10);
	TMatrix(const TMatrix& tmp);
	TMatrix(const TVector<TVector<ValueType> >& tmp);
	~TMatrix();

	TMatrix& operator=(const TMatrix& tmp)const;
	TMatrix operator+(const ValueType a);
	TMatrix operator-(const ValueType a);
	TMatrix operator*(const ValueType a);
	TMatrix operator+(const TMatrix& tmp);
	TMatrix operator-(const TMatrix& tmp);
	//TMatrix operator*(const TMatrix& tmp);
	//TVector operator*(const TVector& tmp);
	bool operator==(const TMatrix& tmp)const;
	bool operator!=(const TMatrix& tmp)const;

	friend istream& operator>>(istream& in, TMatrix& m)
	{
		for (int i = 0; i < m.size; i++)
			in >> m.arr[i];
		return in;
	}

	friend ostream& operator<<(ostream& out, const TMatrix& m)
	{
		for (int i = 0; i < m.size; i++)
			out << m.arr[i] << endl;
		return out;
	}
};

template<typename ValueType>
TMatrix<ValueType>::TMatrix(int _size) : TVector<TVector<ValueType> >(_size)
{
	this->size = _size;
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = TVector<ValueType>(this->size - i, i);
	}
}

template<typename ValueType>
TMatrix<ValueType>::TMatrix(const TMatrix<ValueType>& tmp)
{
	this->size = tmp.size;
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = TVector<ValueType>(this->size - i, i);
		this->arr[i] = tmp.arr[i];
	}
}

template<typename ValueType>
TMatrix<ValueType>::TMatrix(const TVector<TVector<ValueType> >& tmp)
{
	if ((sqrt(tmp.size * 8 + 1) - 1) % 2 == 1)
		throw "!size";
	this->size = (sqrt(tmp.size * 8 + 1) - 1) / 2;
	int s = 0;
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = TVector<ValueType>(this->size - i, i);
		for (int j = 0; j < this->size - i; j++)
			this->arr[i].arr[j] = tmp.arr[s++];
	}
}

template<typename ValueType>
TMatrix<ValueType>::~TMatrix()
{

}

template<typename ValueType>
TMatrix<ValueType>& TMatrix<ValueType>::operator=(const TMatrix& tmp)const
{
	if (*this == tmp)
		return *this;
	if (this->size != tmp.size)
	{
		delete[] this->arr;
		this->size = tmp.size;
		this->arr = TVector<ValueType>[this->size];
	}
	for (int i = 0; i < this->size; i++)
		this->arr[i] = tmp.arr[i];
	return *this;
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(const ValueType a)
{
	TMatrix<ValueType> rez = TMatrix<ValueType>(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] + a;
	return rez;
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator-(const ValueType a)
{
	TMatrix<ValueType> rez = TMatrix<ValueType>(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] - a;
	return rez;
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator*(const ValueType a)
{
	TMatrix<ValueType> rez = TMatrix<ValueType>(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] * a;
	return rez;
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(const TMatrix& tmp)
{
	if (this->size != tmp.size)
		throw "!size";
	TMatrix<ValueType> rez = TMatrix<ValueType>(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] + tmp.arr[i];
	return rez;
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator-(const TMatrix& tmp)
{
	if (this->size != tmp.size)
		throw "!size";
	TMatrix<ValueType> rez = TMatrix<ValueType>(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] - tmp.arr[i];
	return rez;
}

template<typename ValueType>
bool TMatrix<ValueType>::operator==(const TMatrix<ValueType>& tmp)const //!!!!!!!!
{
	if (this->size != tmp.size)
		throw "!size";
	for (int i = 0; i < this->size; i++)
		if (this->arr[i] != tmp.arr[i])
			return false;
	return true;
}

template<typename ValueType>
bool TMatrix<ValueType>::operator!=(const TMatrix& tmp)const
{
	if (this->size != tmp.size)
		throw "!size";
	for (int i = 0; i < this->size; i++)
		if (this->arr[i] != tmp.arr[i])
			return true;
	return false;
}

/*template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator*(const TMatrix& tmp)/////////////////////////////////
{
	if (this->size != tmp.size)
		throw "!size";
	TMatrix<ValueType> rez = TMatrix<ValueType>(tmp);
	res = res * 0;
	/*for (int i = 0; i < this->size; i++)
	{
	for (int j = this->arr[i].startindex; j < this->size; j++)
	{
	res.arr[i].arr[j - arr[i].startindex] += this->arr[i].arr[]
	}
	}
}
template<typename ValueType>
TVector<ValueType> TMatrix<ValueType>::operator*(const TVector<ValueType>& tmp)
{
	if (this->size != tmp.size)
		throw "!size";
	TVector rez = TMatrix(this->size);
	for (int i = 0; i < this->size; i++)
	{
		rez.arr[i] = this->arr[i] * tmp;
	}
	return rez;
}*/
