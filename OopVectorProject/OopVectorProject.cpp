#include <iostream>
#include "Vector.h"

void VectorExample()
{
    Vector<int> v;

    for (int i{}; i < 10; i++)
    {
        v.PushBack((i + 1) * 100);
        std::cout << "item: " << (i + 1) * 100
            << " size: " << v.Size()
            << " capacity: " << v.Capacity() << "\n";
    }

    for (int i{}; i < v.Size(); i++)
        std::cout << v.At(i) << " ";
    std::cout << "\n";
    //v.At(3) = 5000;

    v.PushFront(-100);

    for (int i{}; i < v.Size(); i++)
        std::cout << v.At(i) << " ";
    std::cout << "\n";

    v.Insert(4, 5000);

    for (int i{}; i < v.Size(); i++)
        std::cout << v.At(i) << " ";
    std::cout << "\n";

    for (int i{}; i < 10; i++)
    {
        std::cout << "pop item: " << v.PopFront()
            << " size: " << v.Size()
            << " capacity: " << v.Capacity() << "\n";
    }
}

int main()
{
    //VectorExample();

    Vector<int> v;

    for (int i{}; i < 10; i++)
    {
        v.PushBack((i + 1) * 100);
        std::cout << "item: " << (i + 1) * 100
            << " size: " << v.Size()
            << " capacity: " << v.Capacity() << "\n";
    }

    auto it = v.Iterator();
    for (it; !it.IsEnd(); it.Next())
        std::cout << it.Current() << " ";
    std::cout << "\n";

    for (it.Reset(); !it.IsEnd(); it.Next())
        std::cout << it.Current() << " ";
    std::cout << "\n";
}
