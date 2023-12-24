#include "pch.h"
#include "../TQueue/TQueue.h"

// конструктор преобразования (int преобразует в TQueue<T>)

TEST(TQueue, can_create_queue_with_positive_size) {
	ASSERT_NO_THROW(TQueue<int> q(3));
}

TEST(TQueue, cant_create_queue_with_null_size) {
	ASSERT_ANY_THROW(TQueue<int> q(0));
}

TEST(TQueue, cant_create_queue_with_negative_size) {
	ASSERT_ANY_THROW(TQueue<int> q(-3));
}

TEST(TQueue, created_with_default_constructor_queue_is_empty) {
	TQueue<int> q(3);

	ASSERT_ANY_THROW(q.Pop());
	ASSERT_EQ(q.IsEmpty(), true);

	for (int i = 0; i < 3; ++i) 
		q.Push(i);
	ASSERT_EQ(q.IsFull(), true);

	q.Pop();
	ASSERT_EQ(q.IsFull(), false);
	ASSERT_EQ(q.IsEmpty(), false);
	q.Pop();
	q.Pop();

	ASSERT_ANY_THROW(q.Pop());
}

// конструктор копирования

TEST(TQueue, can_create_copy_queue) {
	TQueue<int> q1(10);
	for (int i = 0; i < 10; ++i)
		q1.Push(i * i);

	ASSERT_NO_THROW(TQueue<int> q2(q1));
}

TEST(TQueue, queue_and_copied_with_constructor_queue_equal) {
	TQueue<int> q1(10);
	for (int i = 0; i < 10; ++i)
		q1.Push(i * i);

	TQueue<int> q3(q1);

	for (int i = 0; i < 10; ++i) {
		bool result = q3.Pop() == q1.Pop();

		ASSERT_EQ(result, true);
	}
}

// оператор присваивания operator=

TEST(TQueue, queue_and_created_with_operatorEQUAL_queue_equal) {
	TQueue<int> q1(10);
	for (int i = 0; i < 10; ++i)
		q1.Push(i * i);

	TQueue<int> q2(2);

	q2 = q1;

	ASSERT_NO_THROW(q2.Pop());
	
	q2 = q1;

	for (int i = 0; i < 10; ++i) {
		bool result = q1.Pop() == q2.Pop();

		ASSERT_EQ(result, true);
	}
}

TEST(TQueue, first_and_second_queues_created_with_operatorEQUAL_equal) {
	TQueue<int> q1(10);
	for (int i = 0; i < 10; ++i)
		q1.Push(i * i);

	TQueue<int> q2(2);
	TQueue<int> q3(10);

	q2 = q1;
	q3 = q1;

	for (int i = 0; i < 10; ++i) {
		bool result = q2.Pop() == q1.Pop();

		ASSERT_EQ(result, true);
	}

	ASSERT_ANY_THROW(q2.Pop());
}

// проверки на пустоту и полноту

TEST(TQueue, correct_work_of_IsEmpty) {
	TQueue<double> q(10);

	ASSERT_ANY_THROW(q.Pop());
	ASSERT_EQ(q.IsEmpty(), true);
}

TEST(TQueue, correct_work_of_IsFull) {
	TQueue<int> q(10);
	for (int i = 0; i < 10; ++i)
		q.Push(i * i * i);

	ASSERT_ANY_THROW(q.Push(10 * 11 * 12));
	ASSERT_EQ(q.IsFull(), true);

	q.Pop(); q.Pop(); q.Pop();
	q.Push(7); q.Push(8); q.Push(9);

	ASSERT_ANY_THROW(q.Push(10));
	ASSERT_EQ(q.IsFull(), true);
}

// push, pop, front, back

TEST(TQueue, push_and_pop_correct_work) {
	TQueue<int> q1(3);

	for (int i = 0; i < 3; ++i)
		q1.Push(i * i);

	ASSERT_ANY_THROW(q1.Push(123));

	for (int i = 0; i < 3 - 1; ++i) {
		bool result = i * i == q1.Pop();

		ASSERT_EQ(result, true);
	}

	q1.Push(3 * 3);
	ASSERT_EQ(q1.Pop(), 2 * 2);
	ASSERT_EQ(q1.Pop(), 3 * 3);

	ASSERT_ANY_THROW(q1.Pop());
}

TEST(TQueue, front_and_back_correct_work) {
	TQueue<int> q(3);

	q.Push(10); q.Push(11);
	q.Pop(); q.Pop();

	for (int i = 0; i < 3; ++i)
		q.Push(10 + i * i);

	for (int i = 0; i < 10; ++i)
		ASSERT_EQ(q.Front(), 10 + 0);

	for (int i = 0; i < 10; ++i)
		ASSERT_EQ(q.Back(), 10 + 2 * 2);
}

// clear
TEST(TQueue, correct_work_of_clear) {
	for (int i = 3; i < 10; ++i) {
		TQueue<int> q(i * i);

		for (int j = 0; j < i * i; ++j)
			q.Push(i * i + j);

		q.Clear();

		ASSERT_ANY_THROW(q.Pop());

		q.Push(10);
		q.Pop();

		ASSERT_ANY_THROW(q.Pop());
	}

	TQueue<int> q(10);

	ASSERT_NO_THROW(q.Clear());
	ASSERT_NO_THROW(q.Clear());
}