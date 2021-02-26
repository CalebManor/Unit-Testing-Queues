#include <gtest/gtest.h>
#include "queue.hpp"

//ASSERT - if not true, will stop
//EXPECT - if not true, will keep going

TEST(QueueTest, VerifyCapacity) {
	data::FixedQueue queue(10);
	ASSERT_EQ(10, queue.capacity());
	
	data::FixedQueue queue1(0);
	ASSERT_EQ(0, queue1.capacity());
}

TEST(QueueTest, VerifySizeOfZero) {
	data::FixedQueue queue(10);
	ASSERT_EQ(0, queue.size());
}

TEST(QueueTest, VerifyEnqueue) {
	data::FixedQueue queue(10);
	ASSERT_TRUE(queue.enqueue(1));
}

TEST(QueueTest, VerifySizeAfterEnqueue) {
	data::FixedQueue queue(10);
	int numElements = 5;
	for (int i = 0; i < numElements; i++) {
		queue.enqueue(1);
	}
	ASSERT_EQ(numElements, queue.size());
}

TEST(QueueTest, DequeueAfterEnqueue) {
	data::FixedQueue queue(10);
	queue.enqueue(1);
	int x = 0;
	ASSERT_TRUE(queue.dequeue(x));
}

TEST(QueueTest, RetrieveElementAFterEnqueueUsingDequeue) {
	data::FixedQueue queue(10);
	int testEnqueueElement = 5;

	queue.enqueue(testEnqueueElement);
	int testDequeueElement = 0;
	
	queue.dequeue(testDequeueElement);
	ASSERT_EQ(testEnqueueElement, testDequeueElement);
}

TEST(QueueTest, VerifyFIFO) {
	data::FixedQueue queue(10);
	const int numElements = 5;

	int queueFIFOEnqueueElements[numElements];
	int temp = 1;

	for (int i = 0; i < numElements; i++) {
		queueFIFOEnqueueElements[i] = temp;
		temp++;
	}

	for (int j = 0; j < numElements; j++) {
		queue.enqueue(queueFIFOEnqueueElements[j]);
	}

	int queueFIFODequeueElements[numElements];

	for (int l = 0; l < numElements; l++) {
		queue.dequeue(queueFIFODequeueElements[l]);
	}

	for (int h = 0; h < numElements; h++) {
		ASSERT_EQ(queueFIFOEnqueueElements[h], queueFIFOEnqueueElements[h]);
	}
}

TEST(QueueTest, EnqueueAtCapacity) {
	data::FixedQueue queue(1);
	int temp = 1;
	queue.enqueue(temp);

	ASSERT_FALSE(queue.enqueue(temp));
}

TEST(QueueTest, EnqueueWhileFullDoesNotChangeSize) {
	data::FixedQueue queue(1);
	int temp = 1; 

	queue.enqueue(temp);
	int fullCapacity = queue.capacity();

	queue.enqueue(temp);
	int fullCapacityPostEnqueue = queue.capacity();

	ASSERT_EQ(fullCapacity, fullCapacityPostEnqueue);

}

TEST(QueueTest, DequeueWhileEmpty) {
	data::FixedQueue queue(10);
	int temp = 0;
	ASSERT_FALSE(queue.dequeue(temp));
}

TEST(QueueTest, DequeueWhileEmptyDoesNotChangeSize) {
	data::FixedQueue queue(1);

	int emptyCapacity = queue.capacity();

	int temp = 0;
	queue.dequeue(temp);
	int temp2 = 0;
	

	ASSERT_EQ(emptyCapacity, queue.capacity());
}

TEST(QueueTest, WrapTest) {
	int capacity = 10;
	data::FixedQueue queue(capacity);

	int tempData = 1; 

	for (int i = 0; i < capacity; i++) {

		for (int j = 0; j < capacity; j++) {
			queue.enqueue(tempData);
		}
		for (int l = 0; l < capacity; l++) {
			queue.dequeue(tempData);
		}
	}

	ASSERT_FALSE(queue.dequeue(tempData));
}