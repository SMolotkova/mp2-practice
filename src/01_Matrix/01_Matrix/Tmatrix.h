#pragma once
#include "TVector.h"
#include<iostream>
using namespace std;
template<typename ValueType>
class TMatrix : public TVector<TVector<ValueType> >
{
public:
	TMatrix(int size = 3);
	TMatrix(const TMatrix& tmp);
	TMatrix(const TVector<TVector<ValueType> >& tmp);
	~TMatrix();

	TMatrix& operator=(const TMatrix& tmp)const;
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

			out << m.arr[i]<<"\n";
		}
		return out;
	}
};

template<typename ValueType>//конструктор с параметром
TMatrix<ValueType>::TMatrix(int size) : TVector<TVector<ValueType> >(size)
{
	this->size = size;
	for (int i = 0; i < size; i++) 
	{
		this->arr[i] = TVector<ValueType>(size - i, i);
	}
}

template<typename ValueType>//конструктор копирования
TMatrix<ValueType>::TMatrix(const TMatrix& tmp) : TVector<TVector<ValueType> >(tmp)
{
	/*this->size = tmp.size;
	(this->arr) = new TVector<ValueType>[tmp.size];
	for (int i = 0; i < tmp.size; i++)
		this->arr[i] = tmp.arr[i];*/
}

template<typename ValueType> //вектор векторов
TMatrix<ValueType>::TMatrix(const TVector<TVector<ValueType> >& tmp) : TVector<TVector<ValueType> >(tmp)
{
	/*for (int i = 0; i < this->size; i++)
		if (tmp[i].Size() != this->size - i)
			throw DifferentSizeMatrix();*/

}

template<typename ValueType>
TMatrix<ValueType>::~TMatrix()
{

}

template<typename ValueType>
TMatrix<ValueType>& TMatrix<ValueType>::operator=(const TMatrix& tmp)const
{
	if (*this == tmp)
	{
		return *this;
	}
	delete[] this->arr;
	this->size = tmp.size;
	this->arr = new TVector<ValueType>[tmp.size];
	for (int i = 0; i < size; i++)
	{
		this->arr[i] = tmp.arr[i];
	}
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
bool TMatrix<ValueType>::operator==(const TMatrix<ValueType>& tmp)const
{
	if (this->size != tmp.size)
		throw DifferentSizeMatrix();
	for (int i = 0; i < tmp.size; i++)
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
	TMatrix<ValueType> rez = TMatrix<ValueType>(tmp);
	for (int i = 0; i < rez.size; i++)
	{
		int untilRow = 1;
		int index = tmp.arr[i].StartIndex();
		for (int j = index; j < rez.size; j++)
		{
			rez.arr[i][j] = ValueType(0);
			for (int k = 0; k < untilRow; k++)
				rez.arr[i][j] = rez.arr[i][j] + this->arr[i][k + i] * tmp.arr[k + i][j];
			untilRow++;
		}
	}
	return rez;
}
template<typename ValueType>
TVector<ValueType> TMatrix<ValueType>::operator*(const TVector<ValueType>& tmp)
{
	//int size = tmp.getSize();
	if (this->size != tmp.size)
		throw DifferentSizeOfVectors();
	TVector<ValueType> rez(size);
	for (int i = 0; i < size; i++)
	{
		rez[i] = ValueType(0);
		int index = this->arr[i].StartIndex();
		for (int j = index; j < size; j++)
			rez[i] = rez[i] + this->arr[i][j] * tmp[j];
	}
	return rez;
}