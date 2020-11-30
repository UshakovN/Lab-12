#pragma once
#include <iostream>
using namespace std;

template <typename T>
class ListBase;

template <typename T>
class Elem {
public:
	T GetInfo();
	Elem<T>* Next();
	Elem<T>* Prev();
	bool IsEmpty();
	friend ListBase<T>;
private:
	Elem<T>* next, * prev;
	T data;
};

template <typename T>
class ListBase {
private:
	Elem<T>* first, * last;
public:
	ListBase();
	ListBase(T item);
	ListBase(ListBase<T>& x);
	~ListBase();
	bool IsEmpty();
	void AddToMiddle(Elem<T>*& node, T item);
	void AddToEnd(T item);
	void AddToBegin(T item);
	void DeleteFromMiddle(Elem<T>*& node);
	void DeleteFromEnd();
	void DeleteFromBegin();
	void Init(T item);
	void Deinit();
	T InfoMiddle(Elem<T>* node);
	T InfoBegin();
	T InfoEnd();
	Elem<T>* First();
	Elem<T>* Last();
};

#include "ListBase.ipp"
