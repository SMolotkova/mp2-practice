#pragma once
template <typename T>
class TVector
{
protected:
	int size;
	T* arr;
	int startindex;
public:
	TVector(int _size);
	TVector(int _size, int _startindex);
	TVector(const TVector& tmp);
	~TVector();

	T length()const;
	TVector& operator = (const TVector& tmp)const;
	TVector operator + (const T a);
	TVector operator == (const TVector& tmp)const;
	friend istream operator >> (istream&, TVector& tmp);
	friend ostream operator << (ostream&, TVector& tmp);
};
template <typename T>
TVector<T> :: operator = (const TVector& tmp)const
{
	if (this == tmp)
		return *this;
	if (size != tmp.size)
	{
		delete[] arr;
		size = tmp.size;
		arr = new T[size];
	}
	memcpy(arr, typeof(T)*size);
	return *this;
}