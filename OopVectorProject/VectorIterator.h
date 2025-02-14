#pragma once

#include "Vector.h"

template <typename T>
class Vector;

template <typename T>
class VectorIterator
{
	Vector<T>* vector;
	int index;
public:
	VectorIterator(Vector<T>* vector)
		: vector{ vector }, index{ 0 } {}

	void Reset();
	void Next();
	bool IsEnd();
	T Current();

	VectorIterator<T> operator++();
	VectorIterator<T> operator++(int);

	VectorIterator<T> operator+(int steps);
};

template<typename T>
inline void VectorIterator<T>::Reset()
{
	index = 0;
}

template<typename T>
inline void VectorIterator<T>::Next()
{
	if (index < vector->Size())
		index++;
}

template<typename T>
inline bool VectorIterator<T>::IsEnd()
{
	return index >= vector->Size();
}

template<typename T>
inline T VectorIterator<T>::Current()
{
	return vector->At(index);
}

template<typename T>
VectorIterator<T> VectorIterator<T>::operator++()
{
	Next();
	return *this;
}

template<typename T>
inline VectorIterator<T> VectorIterator<T>::operator++(int)
{
	auto it = *this;
	Next();
	return it;
}

template<typename T>
inline VectorIterator<T> VectorIterator<T>::operator+(int steps)
{
	index += steps;
	return *this;
}
