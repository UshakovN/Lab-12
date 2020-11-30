#pragma once
#include "Queue.h"
#include "QueueBase.h"
//�������������� ������

//���������� � ������
template <typename T>
template <typename U>
void Queue<T>::AddToBegin(U item) {
	if (!(std::is_same<T, U> ::value)) throw BADTYPE("����������: ������������� �����.\n");
	else {
		Queue<T> temp(item);
		while (!this->IsEmpty()) {
			temp.AddToEnd(this->GetItem());
			this->DeleteFromBegin();
		}
		while (!temp.IsEmpty())
			temp.TopToBottom(*this);
	}
}

//�������� �� �����
template <typename T>
void Queue<T>::DeleteFromEnd() {
	if (this->IsEmpty()) throw EMPTY("����������: ������� ������.\n");
	else {
		Queue<T> temp(this->GetItem());
		this->DeleteFromBegin();
		while (!this->IsEmpty()) {
			T item = this->GetItem();
			this->DeleteFromBegin();
			if (!this->IsEmpty()) {
				temp.AddToEnd(item);
			}
		}
		while (!temp.IsEmpty())
			temp.TopToBottom(*this);
	}
}

//������ ���������� � �����
template <typename T>
T Queue<T>::InfoEnd() {
		Queue<T> temp; T item;
		while (!this->IsEmpty()) {
			item = this->GetItem();
			this->TopToBottom(temp);
		}
		while (!temp.IsEmpty()) {
			temp.TopToBottom(*this);
		}
		return item;
}

//��������� ����� ����������
template <typename T>
ostream& operator << (ostream& stream, QueueBase<T>& qu) {
	QueueBase<T> buffer;
	if (!qu.IsEmpty()) {
		while (!qu.IsEmpty()) {
			stream << qu.GetItem() << " ";
			qu.TopToBottom(buffer);
		}
		stream << endl;
		while (!buffer.IsEmpty()) {
			buffer.TopToBottom(qu);
		}
	}
	else stream << "������� �����." << endl;
	return stream;
}

//��������� ���� ����������
template <typename T>
istream& operator >> (istream& stream, QueueBase<T>& qu) {
	int n;
	T buffer;
	stream >> n;
	for (int i = 0; i < n; i++) {
		stream >> buffer;
		qu.AddToEnd(buffer);
	}
	return stream;
}

//�������. ��������� ������ ��������� ����� �����. ��������� �� �� ������� 5 � ��������� 5.
template <typename T>
void Problem1(Queue<T>& qu, Queue<T>& qout1, Queue<T>& qout2) {
	if (std::is_same<T, int > ::value) {
		cout << "�������: ���������� �����.\n";
		QueueBase<T> buffer(qu);
		while (!buffer.IsEmpty()) {
			if (buffer.GetItem() % 5 == 0) buffer.TopToBottom(qout1);
			else buffer.TopToBottom(qout2);
		}
	}
	else throw BADTYPE("����������: ������������ �����.\n");
}

//�������. ��������� ������ ��������� ������������ �����. ��������� �� �� ������������� � ���������������.
template <typename T>
void Problem2(Queue<T>& qu, Queue<T>& qout1, Queue<T>& qout2) {
	if (std::is_same<T, double > ::value) {
		cout << "�������: ����������� �����.\n";
		Queue<T> buffer(qu);
		while (!buffer.IsEmpty()) {
			if (buffer.GetItem() > 0) buffer.TopToBottom(qout1);
			else buffer.TopToBottom(qout2);
		}
	}
	else throw BADTYPE("����������: ������������� �����.\n");
}


/*
template <typename T>
QueueBase<T>& QueueBase<T>::operator = (const QueueBase<T>& qu) {
	T* p2 = new T[qu.size + qu.end_reserve + qu.begin_reserve];
	if (size > 0) delete[] p;
	p = p2;
	size = qu.size;
	end_reserve = qu.end_reserve;
	begin_reserve = qu.begin_reserve;
	for (int i = 0; i < size + end_reserve + begin_reserve; i++)
		p[i] = qu.p[i];
	return *this;
}
*/
