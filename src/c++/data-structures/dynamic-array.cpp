#pragma once

#include <stdexcept>
#include "dynamic-array.h";

namespace data_structures
{
	template <typename T>
	void DynamicArray<T>::Add(T elm)
	{
		if (IsFull())
		{
			max_size_ = max_size_ * 2;

			T* cache = new T[max_size_];

			for (int i = 0; i < elements_in_array_; i++)
			{
				cache[i] = arr_[i];
			}

			delete[] arr_;

			arr_ = cache;
		}

		// add to end of the array
		arr_[elements_in_array_] = elm;
		elements_in_array_++;
	}

	template <typename T>
	T DynamicArray<T>::RemoveAt(int index)
	{
		if (elements_in_array_ < 0 || index + 1 > elements_in_array_) {
			throw std::out_of_range("Out of range");
		}
		else {
			T data = arr_[index];
			T* cache = new T[max_size_];

			int new_position = 0;
			for (int i = 0; i < elements_in_array_; i++)
			{
				if (i == index) {
					new_position++;
				}
				cache[i] = arr_[new_position];
				new_position++;
			}

			delete[] arr_;

			arr_ = cache;
			elements_in_array_--;

			return data;
		}
	}

	template <typename T>
	std::string DynamicArray<T>::ToString()
	{
		std::string data = "Dynamic Array: ";

		for (int i = 0; i < elements_in_array_; ++i)
		{
			data += std::to_string(arr_[i]) + " ";
		}

		return data;
	}
}
