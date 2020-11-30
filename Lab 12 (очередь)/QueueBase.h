#pragma once
#include <iostream>
#include "Exception.h"
using namespace std;

//Базовые методы
template <typename T>
class QueueBase {

private:
	T* p;
	int size;
	int begin_reserve, end_reserve;
	void Control();
	void MinusBegin();
	void MinusEnd();
	void PlusEnd();

public:
	QueueBase();
	QueueBase(T item);
	QueueBase(QueueBase<T>& qu);
	~QueueBase();
	T GetItem();
	bool IsEmpty();
	void TopToBottom(QueueBase<T>& qu);
	template <typename U>
	void AddToEnd(U item);
	void DeleteFromBegin();
};

#include "QueueBase.ipp"
