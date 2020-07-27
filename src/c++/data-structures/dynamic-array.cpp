#pragma once

#include <stdexcept>;
#include "dynamic-array.h";

namespace data_structures
{
	template <typename T>
	T DynamicArray<T>::Get(int index)
	{
		if (index < 0 || index > elements_in_array_)
		{
			throw std::out_of_range("Out of bounds");
		}

		return arr_[index];
	}

	template <typename T>
	void DynamicArray<T>::Set(int index, T elm)
	{
		if (index < 0 || index > elements_in_array_)
		{
			throw std::out_of_range("Out of bounds");
		}

		arr_[index] = elm;
	}

	template <typename T>
	void DynamicArray<T>::Add(T elm)
	{
		if (IsFull())
		{
			max_size_ = max_size_ * 2;

			T* cache = new T[max_size_];

			for (int i = 0; i < elements_in_array_; ++i)
			{
				cache[i] = arr_[i];
			}

			delete[] arr_;

			arr_ = cache;
		}

		arr_[elements_in_array_] = elm;
		elements_in_array_++;
	}

	template <typename T>
	T DynamicArray<T>::Remove(T elm)
	{
		bool found = false;
		T data{};

		T* cache = new T[max_size_];
		for (int i = 0; i < elements_in_array_; ++i)
		{
			if (elm == arr_[i])
			{
				data = arr_[i];
				found = true;
			}
			else
			{
				cache[i] = arr_[i];
			}
		}

		if (found)
		{
			delete[] arr_;
			arr_ = cache;
			elements_in_array_--;
		}

		return data;
	}

	template <typename T>
	T DynamicArray<T>::RemoveAt(int index)
	{
		if (index < 0 || index + 1 > elements_in_array_) {
			throw std::out_of_range("Out of bounds");
		}

		T data = arr_[index];

		T* cache = new T[max_size_];

		int new_position = 0;
		for (int i = 0; i < elements_in_array_; ++i)
		{
			if (i == index) { // If we have a match, skip it
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

	template <typename T>
	std::string DynamicArray<T>::ToString()
	{
		std::string data = "Dynamic Array: ";

		for (int i = 0; i < elements_in_array_; ++i)
		{
			data += std::to_string(arr_[i]) + ", ";
		}

		return data;
	}
}
