#include "../dynamic-array.h"
#include "../dynamic-array.cpp"

#include <gtest/gtest.h>

TEST(DynamicArray, TestSize)
{
	data_structures::DynamicArray<int> dynamic_array;

	const int size = 5;
	int values[size] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < size; i++)
	{
		dynamic_array.Add(values[i]);
	}
	
	EXPECT_TRUE(dynamic_array.Size() == size);
}

TEST(DynamicArray, TestRemoveAtOverrunOverException)
{
	data_structures::DynamicArray<int> dynamic_array;
	EXPECT_ANY_THROW(dynamic_array.RemoveAt(5));
}

TEST(DynamicArray, TestRemoveAt)
{
	data_structures::DynamicArray<int> dynamic_array;

	const int size = 5;
	int values[size] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < size; i++)
	{
		dynamic_array.Add(values[i]);
	}

	dynamic_array.RemoveAt(1);

	EXPECT_TRUE(dynamic_array.Size() == size - 1);
}

TEST(DynamicArray, TestRemoveAtAndGetValue)
{
	data_structures::DynamicArray<int> dynamic_array;

	const int size = 5;
	int values[size] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < size; i++)
	{
		dynamic_array.Add(values[i]);
	}

	EXPECT_TRUE(dynamic_array.RemoveAt(1) == 2);
}

TEST(DynamicArray, SizeEqualsOne)
{
	data_structures::DynamicArray<int> dynamic_array;
	dynamic_array.Add(1);
	EXPECT_TRUE(dynamic_array.Size() == 1);
}

TEST(DynamicArray, ResizeToEight)
{
	data_structures::DynamicArray<int> dynamic_array;
	dynamic_array.Add(1); // max size = 1
	dynamic_array.Add(2); // max size = 2
	dynamic_array.Add(3); // max size = 4
	dynamic_array.Add(4); 
	dynamic_array.Add(5); // max size = 8

	
	EXPECT_TRUE(dynamic_array.MaxSize() == 8);
}