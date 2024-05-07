#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_12.7/LAB_12.7.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(TestCreateRecommendedList)
		{
			// Arrange
			Textbook* head = nullptr;
			appendToList(head, "Author1", "Title1", 5);
			appendToList(head, "Author2", "Title2", 10);
			appendToList(head, "Author3", "Title3", 3);
			appendToList(head, "Author4", "Title4", 8);

			// Act
			Textbook* recommendedList = createRecommendedList(head, 6);

			// Assert
			int count = 0;
			Textbook* current = recommendedList;
			while (current != nullptr) {
				count++;
				current = current->next;
			}
			Assert::AreEqual(2, count);

			// Free allocated memory
			freeList(head);
			freeList(recommendedList);
		}
	};
}
