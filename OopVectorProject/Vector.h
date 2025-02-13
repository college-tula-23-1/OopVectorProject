#pragma once
#include "VectorIterator.h"

template <typename T>
class Vector
{
	T* items;
	int size;
	int capacity;

	void NewCapacity();

public:
	Vector() : items{ nullptr },
		size{},
		capacity{} {}
	
	Vector(int value) 
		: items{ new T[value + value / 2] },
		size{ value },
		capacity{ value + value / 2 } {}

	~Vector() { delete[] items; }

	void PushBack(T value);
	void PushFront(T value);
	void Insert(int index, T value);

	T PopBack();
	T PopFront();
	T Remove(int index);

	int Size();
	int Capacity();

	T Item(int index);
	void Item(int index, T value);

	T& At(int index);
	T& operator[](int index);

	VectorIterator<T> Iterator();
};

#include "Vector.inl"

