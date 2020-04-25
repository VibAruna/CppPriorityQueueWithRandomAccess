//============================================================================
// Name        : CppPriorityQueueWithRandomAccess.cpp
// Author      : Vibhath
// Version     :
// Copyright   : Your copyright notice
// Description : Priority Queue with Random Access in C++, Ansi-style
//============================================================================

#include <iostream>
#include <gtest/gtest.h>
#include "RandAccPriorityQueue.h"
#include "IndexOutOfBoundException.h"
using namespace std;

bool comp(const int& i, const int& j)
{
	return i <= j;
}

bool eq(const int& i, const int& j)
{
	return i == j;
}

TEST(GTest_Test, CanInsertAndGet)
{
	RandAccPriorityQueue<int> queue(comp, eq);
	queue.insert(7);
	queue.insert(5);
	queue.insert(6);
	queue.insert(10);
	queue.insert(1);
	queue.insert(6);

	ASSERT_EQ(1, queue.get(0));
	ASSERT_EQ(5, queue.get(1));
	ASSERT_EQ(6, queue.get(2));
	ASSERT_EQ(6, queue.get(3));
	ASSERT_EQ(7, queue.get(4));
	ASSERT_EQ(10, queue.get(5));
}

TEST(GTest_Test, CanGetIndex)
{
	RandAccPriorityQueue<int> queue(comp, eq);
	queue.insert(7);
	queue.insert(5);
	queue.insert(6);

	ASSERT_EQ(2, queue.indexOf(7));
	ASSERT_EQ(0, queue.indexOf(5));
	ASSERT_EQ(1, queue.indexOf(6));
	ASSERT_EQ(-1, queue.indexOf(10));
}

TEST(GTest_Test, CanErase)
{
	RandAccPriorityQueue<int> queue(comp, eq);
	queue.insert(7);
	queue.insert(5);
	queue.insert(6);

	ASSERT_EQ(1, queue.erase(6));
	ASSERT_EQ(7, queue.get(1));
	ASSERT_EQ(-1, queue.erase(10));
}

TEST(GTest_Test, ArrayOperatorTest)
{
	RandAccPriorityQueue<int> queue(comp, eq);
	queue.insert(7);
	queue.insert(5);
	queue.insert(6);

	ASSERT_EQ(5, queue[0]);
	ASSERT_EQ(6, queue[1]);
	ASSERT_EQ(7, queue[2]);

	queue[1] = 8;
	ASSERT_EQ(5, queue[0]);
	ASSERT_EQ(8, queue[1]);
	ASSERT_EQ(7, queue[2]);

	ASSERT_THROW(queue[5], IndexOutOfBoundException);
}

TEST(GTest_Test, CanUpdate)
{
	RandAccPriorityQueue<int> queue(comp, eq);
	queue.insert(7);
	queue.insert(5);
	queue.insert(6);

	queue.update(5, 8);

	ASSERT_EQ(6, queue[0]);
	ASSERT_EQ(7, queue[1]);
	ASSERT_EQ(8, queue[2]);
}

TEST(GTest_Test, AccessingEnds)
{
	RandAccPriorityQueue<int> queue(comp, eq);
	ASSERT_THROW(queue.front(), IndexOutOfBoundException);
	ASSERT_THROW(queue.back(), IndexOutOfBoundException);
	ASSERT_THROW(queue.pop_front(), IndexOutOfBoundException);
	ASSERT_THROW(queue.pop_back(), IndexOutOfBoundException);

	queue.insert(7);
	queue.insert(5);
	queue.insert(6);
	queue.insert(8);

	ASSERT_EQ(5, queue.pop_front());
	ASSERT_EQ(8, queue.pop_back());
	ASSERT_EQ(6, queue.front());
	ASSERT_EQ(7, queue.back());
}

struct MSG
{
//	char id[10];
	std::string id;
	int priority;
};

bool msg_comp(const MSG& msg1, const MSG& msg2)
{
	return msg1.priority > msg2.priority;
}

bool msg_equals(const MSG& msg1, const MSG& msg2)
{
	return msg1.id == msg2.id;
}

TEST(Struct_test, CanInsertAndGet)
{
	RandAccPriorityQueue<MSG> queue(msg_comp, msg_equals);
	MSG msg1 = {"abc", 3};
	MSG msg2 = {"def", 1};
	MSG msg3 = {"gh", 2};
	MSG msg4 = {"ad", 1};

	queue.insert(msg1);
	queue.insert(msg2);
	queue.insert(msg3);
	queue.insert(msg4);

	ASSERT_EQ("abc", queue.get(0).id);
	ASSERT_EQ("gh", queue.get(1).id);
	ASSERT_EQ("def", queue.get(2).id);
	ASSERT_EQ("ad", queue.get(3).id);
}

