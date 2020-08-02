#pragma once

namespace data_structures
{
	template <typename T>
	struct DoublyLinkedListNode
	{
		T Data;
		DoublyLinkedListNode* next;
		DoublyLinkedListNode* previous;
	};

	template <typename T>
	class DoublyLinkedList
	{
	public:
		DoublyLinkedList();
		~DoublyLinkedList();

		void Add();
		T Remove(T elm);
		T RemoveAt(int index);
	private:

	};
}
