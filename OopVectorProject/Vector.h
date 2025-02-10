#pragma once
class Vector
{
	int* items;
	int size;
	int capacity;

	void NewCapacity();

public:
	Vector() : items{ nullptr },
		size{},
		capacity{} {}
	
	Vector(int value) : items{ new int[value + value / 2] },
		size{ value },
		capacity{ value + value / 2 } {}

	~Vector() { delete[] items; }

	void PushBack(int value);
	void PushFront(int value);
	void Insert(int index, int value);

	int PopBack();
	int PopFront();
	int Remove(int index);

	int Size();
	int Capacity();

	int Item(int index);
	void Item(int index, int value);

	int& At(int index);
};

