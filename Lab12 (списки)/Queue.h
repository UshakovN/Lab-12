#pragma once
#include "QueueBase.h"

template <typename T>
class Queue : public QueueBase<T> {
public:
	Queue() : QueueBase<T>() {}
	Queue(T item) : QueueBase<T>(item) {}
	Queue(Queue<T>& qu) : QueueBase<T>(qu) {}
	template <typename U>
	void AddToBegin(U item);
	void DeleteFromEnd();
	T InfoEnd();
};

template <typename T>
void Problem1(Queue<T>& qu, Queue<T>& qout1, Queue<T>& qout2);

template <typename T>
void Problem2(Queue<T>& qu, Queue<T>& qout1, Queue<T>& qout2);

template <typename T>
ostream& operator << (ostream& stream, QueueBase<T>& qu);

template <typename T>
istream& operator >> (istream& stream, QueueBase<T>& qu);


#include "Queue.ipp"
