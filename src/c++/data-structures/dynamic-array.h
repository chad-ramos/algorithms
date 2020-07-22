#pragma once

#include <iostream>

namespace data_structures
{
	template <typename T>
	class DynamicArray
	{
	public:
		DynamicArray();
	

		void Empty();
		void RemoveAt(int index);
		void Add(T elm);
		int Size();
		bool IsFull();
		
	private:
		T *arr_;
		int max_size_; // Max amount of indexs in array
		int length_; // Number of occupied indexes
	};
}
