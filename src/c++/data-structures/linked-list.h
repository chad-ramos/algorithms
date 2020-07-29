#pragma once

namespace data_structures
{
	template <typename T>
	struct LinkedListNode
	{
		T Data
		LinkedListNode* next;
	};
	
	template <typename T>
	class LinkedList
	{
	public:
		void Add();
		T Remove(T elm);
		T RemoveAt(int index);
	private:
		
	};
}
