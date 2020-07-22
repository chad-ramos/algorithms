#pragma once

#include "dynamic-array.h";

namespace data_structures
{
	template <typename T>
	DynamicArray<T>::DynamicArray()
	{
		max_size_ = 1;
		arr_ = new T[max_size_];
		length_ = 0;
	}

	template <typename T>
	void DynamicArray<T>::Empty()
	{
	}

	template <typename T>
	void DynamicArray<T>::RemoveAt(int index)
	{
		
		
	}

	template <typename T>
	void DynamicArray<T>::Add(T elm)
	{
		if (IsFull())
		{
			max_size_ = max_size_ * 2;

			T* cache = new T[max_size_];

			for (int i = 0; i < length_; ++i)
			{
				cache[i] = arr_[i];
			}

			delete[] arr_;

			arr_ = cache;
		}

		arr_[length_] = elm;
		length_++;
	}

	template <typename T>
	int DynamicArray<T>::Size()
	{
		return length_;
	}

	template <typename T>
	bool DynamicArray<T>::IsFull()
	{
		return length_ == max_size_;
	}
}
