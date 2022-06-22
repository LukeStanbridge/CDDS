#include "CppUnitTest.h"
#include "../LinkedLists/LinkedLists.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTesting
{
	TEST_CLASS(UnitTesting)
	{
	public:
		
		TEST_METHOD(PushFront)
		{
			LinkedList List;
			List.pushFront(1);
			List.pushBack(2);
			List.pushBack(3);
			Assert::AreEqual(List.begin(), 1);
		}

		TEST_METHOD(PopFront)
		{
			LinkedList List;
			List.pushFront(1);
			List.pushFront(2);
			List.pushFront(3);
			List.popFront();
			Assert::AreNotEqual(List.begin(), 3);
		}

		TEST_METHOD(PushBack)
		{
			LinkedList List;
			List.pushFront(1);
			List.pushFront(2);
			List.pushFront(3);
			Assert::AreEqual(List.end(), 1);
		}

		TEST_METHOD(PopBack)
		{
			LinkedList List;
			List.pushFront(1);
			List.pushFront(2);
			List.pushFront(3);
			List.popBack();
			Assert::AreNotEqual(List.end(), 1);
		}

		TEST_METHOD(CountList)
		{
			LinkedList List;
			List.pushFront(1);
			List.pushFront(2);
			List.pushFront(3);
			Assert::AreEqual(List.countList(), 3);
		}

		TEST_METHOD(insertAtLocation)
		{
			LinkedList List;
			List.pushFront(1);
			List.pushFront(2);
			List.pushFront(3);
			List.insertAtLocation(4, 2);
			Assert::AreEqual(List.getAtPos(2), 4);
		}
	};
}
