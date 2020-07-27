#include "../dynamic-array.h"
#include "../dynamic-array.cpp"

#include <gtest/gtest.h>

TEST(DynamicArray, Size)
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

TEST(DynamicArray, Empty)
{
	data_structures::DynamicArray<int> dynamic_array;
	EXPECT_TRUE(dynamic_array.IsEmpty());
}

TEST(DynamicArray, OutOfBoundsHigh)
{
	data_structures::DynamicArray<int> dynamic_array;
	EXPECT_ANY_THROW(dynamic_array.RemoveAt(5));
}

TEST(DynamicArray, OutOfBoundsLow)
{
	data_structures::DynamicArray<int> dynamic_array;
	EXPECT_ANY_THROW(dynamic_array.RemoveAt(-1));
}

TEST(DynamicArray, RemoveWithIntType)
{
	data_structures::DynamicArray<int> dynamic_array;
	const int size = 5;
	int values[size] = { 1, 2, 3, 4, 5 };

	for (int i = 0; i < size; i++)
	{
		dynamic_array.Add(values[i]);
	}

	int value;
	int target = 2;
	value = dynamic_array.Remove(target);

	EXPECT_TRUE(value == target);
	EXPECT_TRUE(dynamic_array.Size() == size - 1);
}

TEST(DynamicArray, RemoveWithStringType)
{
	data_structures::DynamicArray<std::string> dynamic_array;
	const int size = 5;

	std::string values[size] = { "1", "2", "3", "4", "5" };
	for (int i = 0; i < size; i++)
	{
		dynamic_array.Add(values[i]);
	}

	std::string value;
	std::string target = "4";
	value = dynamic_array.Remove(target);
	
	EXPECT_TRUE(value == target);
	EXPECT_TRUE(dynamic_array.Size() == size - 1);
}

TEST(DynamicArray, RemoveAt)
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