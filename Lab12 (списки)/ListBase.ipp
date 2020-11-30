#include "ListBase.h"
//Базовые методы

template <typename T>
Elem<T>* Elem<T>::Next() {
	return this->next;
}

template <typename T>
Elem<T>* Elem<T>::Prev() {
	return this->prev;
}

template <typename T>
bool Elem<T>::IsEmpty() {
	return this == NULL;
}

template <typename T>
Elem<T>* ListBase<T>::First() {
	return this->first;
}

template <typename T>
Elem<T>* ListBase<T>::Last() {
	return this->last;
}

template <typename T>
T Elem<T>::GetInfo() {
	return this->data;
}

template <typename T>
ListBase<T>::ListBase() {
	first = NULL;
	last = NULL;
}

template <typename T>
ListBase<T>::ListBase(T item) {
	Elem<T>* buffer = new Elem<T>;
	buffer->prev = NULL;
	buffer->next = NULL;
	buffer->data = item;
	last = buffer;
	first = buffer;
}

template <typename T>
ListBase<T>::ListBase(ListBase<T>& x) {
	Elem<T>* buffer = new Elem<T>;
	buffer->data = x.first->GetInfo();
	buffer->next = buffer->prev = NULL;
	first = last = buffer;
	buffer = x.first->Next();
	while (!buffer->IsEmpty()) {
		AddToEnd(buffer->GetInfo());
		buffer = buffer->Next();
	}
}

template <typename T>
ListBase<T>::~ListBase() {
	Elem<T>* buffer = first;
	while (first != last) {
		this->DeleteFromBegin();
	}
	if (!first->IsEmpty())
		this->Deinit();
}

template <typename T>
bool ListBase<T>::IsEmpty() {
	return first == NULL;
}

template <typename T>
void ListBase<T>::Init(T item) {
	Elem<T>* buffer = new Elem<T>;
	buffer->data = item;
	buffer->next = buffer->prev = NULL;
	first = last = buffer;
}

template <typename T>
void ListBase<T>::Deinit() {
	delete first;
	first = last = NULL;
}

template <typename T>
void ListBase<T>::AddToMiddle(Elem<T>*& node, T item) {
	Elem<T>* buffer1, * buffer2;
	buffer1 = new Elem<T>;
	buffer2 = node->Next();
	buffer1->data = item;
	buffer1->prev = node;
	node->next = buffer1;
	buffer1->next = buffer2;
	buffer2->prev = buffer1;
}

template <typename T>
void ListBase<T>::AddToEnd(T item) {
	Elem<T>* buffer;
	buffer = new Elem<T>;
	buffer->prev = last;
	buffer->data = item;
	buffer->next = NULL;
	last->next = buffer;
	last = buffer;

}

template <typename T>
void ListBase<T>::AddToBegin(T item) {
	Elem<T>* buffer;
	buffer = new Elem<T>;
	buffer->prev = NULL;
	buffer->data = item;
	buffer->next = first;
	first->prev = buffer;
	first = buffer;
}

template <typename T>
void ListBase<T>::DeleteFromMiddle(Elem<T>*& node) {
	if (IsEmpty()) throw EMPTY("Исключение: Список пуст.\n");
	else {
		Elem<T>* buffer1, * buffer2;
		buffer1 = node;
		node = buffer1->Prev();
		buffer2 = buffer1->Next();
		buffer1->prev = NULL;
		buffer1->next = NULL;
		node->next = buffer2;
		buffer2->prev = node;
		delete buffer1;
	}
}

template <typename T>
void ListBase<T>::DeleteFromEnd() {
	if (IsEmpty()) throw EMPTY("Исключение: Список пуст.\n");
	else {
		Elem<T>* buffer;
		buffer = last;
		last = last->Prev();
		buffer->prev = NULL;
		last->next = NULL;
		delete buffer;
	}
}

template <typename T>
void ListBase<T>::DeleteFromBegin() {
	if (IsEmpty()) throw EMPTY("Исключение: Список пуст.\n");
	else {
		Elem<T>* buffer;
		buffer = first;
		first = first->Next();
		buffer->next = NULL;
		first->prev = NULL;
		delete buffer;
	}
}

template <typename T>
T ListBase<T>::InfoMiddle(Elem<T>* node) {
	return node->data;
}

template <typename T>
T ListBase<T>::InfoEnd() {
	return last->data;
}

template <typename T>
T ListBase<T>::InfoBegin() {
	return first->data;
}
