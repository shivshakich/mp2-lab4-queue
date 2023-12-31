#include "../gtest-sln/gtest.h"
#include "../TQueue/TQueueOnList.h"

// КОНСТРУТОРЫ И ДЕСТРУКТОР

// конструктор по умолчанию

TEST(TQueueOnList, can_create_queue_using_default_constructor) {
	ASSERT_NO_THROW(TQueueOnList<int> que);
}

TEST(TQueueOnList, queue_created_using_default_constuctor_is_empty) {
	TQueueOnList<int> que;

	ASSERT_TRUE(que.IsEmpty());
}