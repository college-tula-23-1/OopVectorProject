#include "Vector.h"

void Vector::NewCapacity()
{
	capacity = size + ((size) ? size / 2 : 4);

	int* itemsNew = new int[capacity];
	for (int i{}; i < size; i++)
		itemsNew[i] = items[i];

	delete[] items;
	items = itemsNew;
}

void Vector::PushBack(int value)
{
	if (size >= capacity)
	{
		NewCapacity();
	}

	items[size++] = value;
}

void Vector::PushFront(int value)
{
	Insert(0, value);
}

void Vector::Insert(int index, int value)
{
	if (size >= capacity)
	{
		NewCapacity();
	}

	for (int i{ size - 1 }; i >= index; i--)
		items[i + 1] = items[i];
	items[index] = value;
	size++;
}

int Vector::PopBack()
{
	int value = items[--size];

	if (capacity >= size * 2)
	{
		NewCapacity();

	}

	return value;
}

int Vector::Size() { return size; }

int Vector::Capacity() { return capacity; }

int Vector::Item(int index) 
{ 
	if (index >= 0 && index < size)
		return items[index];
	else
		throw -1;
}

void Vector::Item(int index, int value) 
{ 
	if (index >= 0 && index < size)
		items[index] = value;
	else
		throw - 1;
}

int& Vector::At(int index) 
{ 
	if (index >= 0 && index < size)
		return items[index];
	else
		throw - 1;
}
