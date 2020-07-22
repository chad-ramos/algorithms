#include "../dynamic-array.h"
#include "../dynamic-array.cpp"

#include <gtest/gtest.h>

TEST(DynamicArray, TestSize)
{
	data_structures::DynamicArray<int> dynamic_array;

	const int size = 5;
	int values[size] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < size - 1; i++)
	{
		dynamic_array.Add(values[1]);
		EXPECT_TRUE(dynamic_array.Size() == i + 1);
	}
}


TEST(DynamicArray, TestRemoveAt)
{
	data_structures::DynamicArray<int> dynamic_array;

	const int size = 5;
	int values[size] = { 1, 2, 3, 4, 5 };

	int current_index = 0;
	for (; current_index < size - 1; current_index++)
	{
		dynamic_array.Add(values[1]);
	}

	dynamic_array.RemoveAt(1);

	EXPECT_TRUE(dynamic_array.Size() == size + 1);
}


TEST(DynamicArray, TestSizeEqualsOne)
{
	data_structures::DynamicArray<int> dynamic_array;
	dynamic_array.Add(1);
	EXPECT_TRUE(dynamic_array.Size() == 1);
}

TEST(DynamicArray, TestSizeEqualsFiveDynamicResize)
{
	data_structures::DynamicArray<int> dynamic_array;
	dynamic_array.Add(1);
	dynamic_array.Add(2);
	dynamic_array.Add(3);
	dynamic_array.Add(4);
	dynamic_array.Add(5);
	EXPECT_TRUE(dynamic_array.Size() == 5);
}