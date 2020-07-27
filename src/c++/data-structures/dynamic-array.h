#pragma once

#include <iostream>

namespace data_structures
{
	template <typename T>
	class DynamicArray
	{
	public:
		DynamicArray()
		{
			max_size_ = 1;
			arr_ = new T[max_size_];
			elements_in_array_ = 0;
		};

		void Add(T elm);
		T Remove(T elm);
		T RemoveAt(int index);
		T Get(int index);
		void Set(int index, T elm);
		
		int Size() { return elements_in_array_; }
		bool IsEmpty() { return elements_in_array_ == 0; };
		bool IsFull() { return elements_in_array_ == max_size_; }
		int MaxSize() { return max_size_; }
		std::string ToString();

	private:
		T* arr_;
		int max_size_; // Max amount of indexs in array
		int elements_in_array_; // Number of occupied indexes
	};
}
