#pragma once
#include <iostream>
#include "QueueBase.h"
//Базовые методы

//Конструктор по умолчанию
template <typename T>
QueueBase<T>::QueueBase() {
	p = new T[20];
	begin_reserve = 0;
	end_reserve = 10;
	size = 0;
}

//С параметром числом
template <typename T>
QueueBase<T>::QueueBase(T item) {
	size = 1;
	begin_reserve = 0;
	end_reserve = 10;
	p = new T[20];
	p[begin_reserve] = item;
}

//Конструктор копирования
template <typename T>
QueueBase<T>::QueueBase(QueueBase<T>& qu) {
	p = new T[20];
	begin_reserve = 0;
	end_reserve = 10;
	size = 0;
	QueueBase buffer;
	while (!qu.IsEmpty()) {
		AddToEnd(qu.GetItem());
		qu.TopToBottom(buffer);
	}
	while (!buffer.IsEmpty()) {
		buffer.TopToBottom(qu);
	}
}

//Деструктор
template <typename T>
QueueBase<T>::~QueueBase() {
	if (size != 0) {
		delete[] p;
		begin_reserve = 0;
		end_reserve = 0;
		size = 0;
	}
}

//Получить первый элемент из очереди не удаляя его
template <typename T>
T QueueBase<T>::GetItem() {
	return p[begin_reserve];
}

//Проверка на пустоту
template <typename T>
bool QueueBase<T>::IsEmpty() {
	return size == 0;
}

//Движение
template <typename T>
void QueueBase<T>::TopToBottom(QueueBase<T>& qu) {
	T buffer;
	if (!IsEmpty()) {
		buffer = GetItem();
		DeleteFromBegin();
		qu.AddToEnd(buffer);
	}
}

//Методы контроля массива
template <typename T>
void QueueBase<T>::Control() {
	if (begin_reserve == 10) {
		MinusBegin();
	}
	if (end_reserve == 0) {
		PlusEnd();
	}
	else if (end_reserve == 20) {
		MinusEnd();
	}
}

template <typename T>
void QueueBase<T>::MinusBegin() {
	T* p2;
	p2 = new T[size + end_reserve];
	for (int i = 0; i < size + end_reserve; i++) {
		p2[i] = p[i + 10];
	}
	delete[] p;
	p = p2;
	begin_reserve -= 10;
}

template <typename T>
void QueueBase<T>::MinusEnd() {
	T* p2;
	p2 = new T[begin_reserve + size];
	for (int i = 0; i < begin_reserve + size; i++) {
		p2[i] = p[i];
	}
	delete[] p;
	p = p2;
	end_reserve -= 10;
}

template <typename T>
void QueueBase<T>::PlusEnd() {
	T* p2;
	p2 = new T[begin_reserve + size + end_reserve + 10];
	for (int i = 0; i < begin_reserve + size + end_reserve; i++) {
		p2[i] = p[i];
	}
	delete[] p;
	p = p2;
	end_reserve += 10;
}

//Добавление в конец
template <typename T>
template <typename U>
void QueueBase<T>::AddToEnd(U item) {
	if (!(std::is_same<T, U> ::value)) throw BADTYPE("Исключение: Несоотвествие типов.\n");
	else {
		Control();
		size++;
		p[begin_reserve + size - 1] = item;
		end_reserve--;
	}
}

//Удаление из начала
template <typename T>
void QueueBase<T>::DeleteFromBegin() {
	if (size == 0) throw EMPTY("Исключение: Очередь пустая.\n");
	else {
		Control();
		begin_reserve++;
		size--;
	}
}
