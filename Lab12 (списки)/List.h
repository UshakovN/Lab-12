#pragma once
#include "ListBase.h"
#include <iostream>
using namespace std;

template <typename T>
class List : public ListBase<T> {
public:
	List() : ListBase<T>() {}
	List(T item) : ListBase<T>(item) {}
	List(List<T>& x) : ListBase<T>(x) {}
	void ControlDeleteElem(T z);
	bool NegativeElement();
};

template <typename T>
void Problem(List<T>& x, T z);

template <typename T>
ostream& operator << (ostream& stream, ListBase<T>& x);

template <typename T>
istream& operator >> (istream& stream, ListBase<T>& x);


#include "List.ipp"