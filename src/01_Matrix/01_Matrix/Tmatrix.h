#pragma once
#include "TVector.h"
#include<iostream>
using namespace std;
template<typename VauleType>
class TMatrix : public TVector<Tvector<VauleType>>
{
public:
	TMatrix(int _size);
	TMatrix(const TMatrix& tmp);
	TMatrix(const TVector& tmp);
	~TMatrix();

	TMatrix& operator=(const TMatrix& tmp)const;
	TMatrix operator+(const VauleType a);
	TMatrix operator-(const VauleType a);
	TMatrix operator*(const VauleType a);
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

	friend ostream& operator<<(ostream& out, const TMatrix& m)//!!!!!
	{
		for (int i = 0; i < m.size; i++)
			out << m.arr[i] << endl;
		return out;
	}
};

	template<typename VauleType>
	TMatrix<VauleType>::TMatrix(int _size)
	{
		this->size = _size;
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = new TVector<VauleType>(this->size - i, i);
		}
	}

	template<typename VauleType>
	TMatrix<VauleType>::TMatrix(const TMatrix& tmp)
	{
		this->size = tmp.size;
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = new TVector<VauleType>(this->size - i, i);
			this->arr[i] = tmp.arr[i];
		}
	}

	template<typename VauleType>
	TMatrix<VauleType>::TMatrix(const TVector<VauleType>& tmp)
	{
		if ((sqrt(tmp.size * 8 + 1) - 1) % 2 == 1)
			throw "!size";
		this->size = (sqrt(tmp.size * 8 + 1) - 1) / 2;
		int s = 0;
		for (int i = 0; i < this->size; i++)
		{
			this->arr[i] = TVector<VauleType>(this->size - i, i);
			for (int j = 0; j < this->size - i; j++)
				this->arr[i].arr[j] = tmp.arr[s++];
		}
	}

	template<typename VauleType>
	TMatrix<VauleType>::~TMatrix()
	{
		for (int i = 0; i < this->size; i++)
			delete[] this->arr[i];
		this->size = 0;
	}

	template<typename VauleType>
	TMatrix<VauleType>& TMatrix<VauleType>::operator=(const TMatrix& tmp)const
	{
		if (*this == tmp)
			return *this;
		if (this->size != tmp.size)
		{
			delete[] this->arr;
			this->size = tmp.size;
			this->arr = new TVector<VauleType>[this->size];
		}
		for (int i = 0; i < this->size; i++)
			this->arr[i] = tmp.arr[i];
		return *this;
	}

	template<typename VauleType>
	TMatrix<VauleType> TMatrix<VauleType>::operator+(const VauleType a)
	{
		TMatrix<VauleType> rez = TMatrix<VauleType>(this->size);
		for (int i = 0; i < this->size; i++)
			rez.arr[i] = this->arr[i] + a;
		return rez;
	}

	template<typename VauleType>
	TMatrix<VauleType> TMatrix<VauleType>::operator-(const VauleType a)
	{
		TMatrix<VauleType> rez = TMatrix<VauleType>(this->size);
		for (int i = 0; i < this->size; i++)
			rez.arr[i] = this->arr[i] - a;
		return rez;
	}

	template<typename VauleType>
	TMatrix<VauleType> TMatrix<VauleType>::operator*(const VauleType a)
	{
		TMatrix<VauleType> rez = TMatrix<VauleType>(this->size);
		for (int i = 0; i < this->size; i++)
			rez.arr[i] = this->arr[i] * a;
		return rez;
	}

	template<typename VauleType>
	TMatrix<VauleType> TMatrix<VauleType>::operator+(const TMatrix& tmp)
	{
		if (this->size != tmp.size)
			throw "!size";
		TMatrix<VauleType> rez = TMatrix<VauleType>(this->size);
		for (int i = 0; i < this->size; i++)
			rez.arr[i] = this->arr[i] + tmp.arr[i];
		return rez;
	}

	template<typename VauleType>
	TMatrix<VauleType> TMatrix<VauleType>::operator-(const TMatrix& tmp)
	{
		if (this->size != tmp.size)
			throw "!size";
		TMatrix<VauleType> rez = TMatrix<VauleType>(this->size);
		for (int i = 0; i < this->size; i++)
			rez.arr[i] = this->arr[i] - tmp.arr[i];
		return rez;
	}

	template<typename VauleType>
	bool TMatrix<VauleType>::operator==(const TMatrix& tmp)const
	{
		if (this->size != tmp.size)
			throw "!size";
		for (int i = 0; i < this->size; i++)
			if (this->arr[i] != tmp.arr[i])
				return false;
		return true;
	}

	template<typename VauleType>
	bool TMatrix<VauleType>::operator!=(const TMatrix& tmp)const
	{
		if (this->size != tmp.size)
			throw "!size";
		for (int i = 0; i < this->size; i++)
			if (this->arr[i] != tmp.arr[i])
				return true;
		return false;
	}

	/*template<typename VauleType>
	TMatrix<VauleType> TMatrix<VauleType>::operator*(const TMatrix& tmp)/////////////////////////////////
	{
		if (this->size != tmp.size)
			throw "!size";
		TMatrix<VauleType> rez = TMatrix<VauleType>(tmp);
		res = res * 0;
		/*for (int i = 0; i < this->size; i++)
		{
		for (int j = this->arr[i].startindex; j < this->size; j++)
		{

		res.arr[i].arr[j - arr[i].startindex] += this->arr[i].arr[]
		}
		}
	}

	template<typename VauleType>
	TVector<VauleType> TMatrix<VauleType>::operator*(const TVector<VauleType>& tmp)
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
