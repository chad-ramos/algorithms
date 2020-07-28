#pragma once

#include <iostream>

namespace data_structures
{
	template <typename T>
	class DynamicArray
	{
	public:
		DynamicArray();

		void Add(T elm);
		T Remove(T elm);
		T RemoveAt(int index);
		T Get(int index);
		void Set(int index, T elm);

		int Size();
		bool IsEmpty();;
		bool IsFull();
		int MaxSize();
		std::string ToString();

	private:
		T* arr_;
		int max_size_; // Max amount of indexs in array
		int elements_in_array_; // Number of occupied indexes
	};
}
