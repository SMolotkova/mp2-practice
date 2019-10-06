#pragma once
#include "TVector.h"
#include<math.h>
#include<iostream>
using namespace std;

template<typename ValueType>
class TMatrix : public TVector<TVector<ValueType> >
{
public:
	TMatrix(int size);
	TMatrix(const TMatrix& tmp);
	TMatrix(const TVector<TVector<ValueType> >& tmp);
	~TMatrix();

	TMatrix& operator=(const TMatrix& tmp);//const;
	TMatrix operator+(const ValueType a);
	TMatrix operator-(const ValueType a);
	TMatrix operator*(const ValueType a);
	TMatrix operator+(const TMatrix& tmp);
	TMatrix operator-(const TMatrix& tmp);
	TMatrix operator*(const TMatrix& tmp);
	TVector<ValueType> operator*(const TVector<ValueType>& tmp);
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
		{
			/*for (int j = 0; j < m.arr[i].StartIndex(); j++)
			{
				out << "0, ";
			}*/

			out << m.arr[i] << "\n";
		}
		return out;
	}
};

template<typename ValueType>//конструктор с параметром
TMatrix<ValueType>::TMatrix(int _size) : TVector<TVector<ValueType> >(_size)
{
	this->size = _size;
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = TVector<ValueType>(this->size - i, i);
	}
}

template<typename ValueType>//конструктор копирования ??????
TMatrix<ValueType>::TMatrix(const TMatrix& tmp) : TVector<TVector<ValueType> >(tmp)
{
	this->size = tmp.size;
	//(this->arr) = new TVector<ValueType>[tmp.size];
	for (int i = 0; i < tmp.size; i++)
		this->arr[i] = TVector<ValueType>(tmp.arr[i]);
}

template<typename ValueType> //вектор векторов ??????
TMatrix<ValueType>::TMatrix(const TVector<TVector<ValueType> >& tmp) : TVector<TVector<ValueType> >(tmp)
{
	if ((sqrt(tmp.size * 8 + 1) - 1) % 2 == 1)
		throw DifferentSizeOfVectors();
	this->size = (sqrt(tmp.size * 8 + 1) - 1) / 2;
	int s = 0;
	for (int i = 0; i < this->size; i++)
	{
		this->arr[i] = TVector<ValueType>(this->size - i, i);
		for (int j = 0; j < this->size - i; j++)
			this->arr[i][j] = tmp.arr[s++];//[][] 
	}

}

template<typename ValueType>
TMatrix<ValueType>::~TMatrix()
{

}

template<typename ValueType>
TMatrix<ValueType>& TMatrix<ValueType>::operator=(const TMatrix& tmp)//const
{
	if (*this == tmp)
		return *this;
	if (this->size != tmp.size)
	{
		this->size = tmp.size;
		delete this->arr;
		this->arr = new TVector<ValueType>[tmp.size];
	}
	for (int i = 0; i < this->size; i++)
		this->arr[i] = tmp.arr[i];
	return *this;
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator+(const ValueType a)
{
	TMatrix<ValueType> rez(this->size);
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
		throw DifferentSizeMatrix();
	TMatrix<ValueType> rez = TMatrix<ValueType>(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] + tmp.arr[i];
	return rez;
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator-(const TMatrix& tmp)
{
	if (this->size != tmp.size)
		throw DifferentSizeMatrix();
	TMatrix<ValueType> rez = TMatrix<ValueType>(this->size);
	for (int i = 0; i < this->size; i++)
		rez.arr[i] = this->arr[i] - tmp.arr[i];
	return rez;
}

template<typename ValueType>
bool TMatrix<ValueType>::operator==(const TMatrix& tmp)const
{
	if (this->size != tmp.size)
		return false;
	for (int i = 0; i < this->size; i++)
		if (this->arr[i] != tmp.arr[i])
			return false;
	return true;
}

template<typename ValueType>
bool TMatrix<ValueType>::operator!=(const TMatrix& tmp)const
{
	return (!(*this == tmp));
}

template<typename ValueType>
TMatrix<ValueType> TMatrix<ValueType>::operator*(const TMatrix& tmp) ///!!!!!!!!!!!!!!!!!!!!!!!!!!!
{
	if (this->size != tmp.size)
		throw DifferentSizeMatrix();
	TMatrix<ValueType> rez(this->size);
	rez = rez * 0;
	for (int i = 0; i < this->size; i++)
		for (int j = this->arr[i].startindex; j < this->size; j++)
			for (int k = i; k <= j; k++)
				rez.arr[i][j - i] += this->arr[i][k - i] * tmp.arr[k][j - k];
	return rez;
}
template<typename ValueType>
TVector<ValueType> TMatrix<ValueType>::operator*(const TVector<ValueType>& tmp)
{
	if (this->size != tmp.size)
		throw DifferentSizeMatrix();
	TVector<ValueType> rez(this->size);
	rez = rez * 0;
	for (int i = 0; i < this->size; i++)
		for (int j = 0; j < this->arr[i].size; j++)
			rez[i] += this->arr[i][j] * tmp[i + j];
	return rez;
}
