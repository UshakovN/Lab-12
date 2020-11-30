#include "List.h"
//�������������� ������

//��������� ���� ����������
template <typename T>
istream& operator >> (istream& stream, ListBase<T>& x) {
	int n;
	T buffer;
	stream >> n;
	if (n > 0) {
		stream >> buffer;
		x.Init(buffer);
		for (int i = 0; i < n - 1; i++) {
			stream >> buffer;
			x.AddToEnd(buffer);
		}
	}
	return stream;
}

//��������� ����� ����������
template <typename T>
ostream& operator << (ostream& stream, ListBase<T>& x) {
	Elem<T>* buffer = x.First(); cout << "������ �����: ";
	while (!buffer->IsEmpty()) {
		stream << buffer->GetInfo() << " ";
		buffer = buffer->Next();
	}
	buffer = x.Last(); cout << endl << "�������� �����: ";
	while (!buffer->IsEmpty()) {
		stream << buffer->GetInfo() << " ";
		buffer = buffer->Prev();
	}
	cout << endl;
	return stream;
}

//������� ������������� ��������� � ������
template <typename T>
bool List<T>::NegativeElement() {
	Elem<T>* buffer = this->First();
	bool flag = false;
	while (!buffer->IsEmpty() && !flag) {
		if (buffer->GetInfo() < 0) flag = true;
		else buffer = buffer->Next();
	}
	return flag;
}

//�������� ������ ��������� ��������
template <typename T> 
void List<T>::ControlDeleteElem(T z) {
	Elem<T>* buffer = this->First();
	while (!buffer->IsEmpty()) {
		if (buffer->GetInfo() > z) {
			if (buffer != this->Last()) 
			{
				if (buffer == this->First()) {
					buffer = buffer->Next();
					this->DeleteFromBegin();
				}
				else {
					if (this->First() != this->Last()) this->DeleteFromMiddle(buffer);
					else {this->Deinit(); buffer = NULL;}
				}
			}
			else {
				if (this->First() == this->Last()) {this->Deinit(); buffer = NULL;}
				else {this->DeleteFromEnd(); buffer = NULL;}
			}
		}
		else {buffer = buffer->Next();}
	}
}

//���� � ������ �� ������������ ����� ���� ������������� �������, ������� �� ������ ��������, ������� ��������� ��������.
template <typename T>
void Problem(List<T>& x, T z) {
	if (x.NegativeElement()) {
		x.ControlDeleteElem(z);
	}
	else cout << "� ������ ��� ������������� ���������." << endl;
}




/*

//���� � ������ �� ������������ ����� ���� ������������� �������,
//������� �� ������ ��������, ������� ��������� ��������.
template <typename T>
void Problem(List<T>& x, T z) {
	Elem<T>* buffer = x.First();
	while (!buffer->IsEmpty()) {
		if (buffer->GetInfo() > z) {
			if (buffer != x.Last())
			{
				if (buffer == x.First()) {
					buffer = buffer->Next();
					x.DeleteFromBegin();
				}
				else {
					if (x.First() != x.Last()) x.DeleteFromMiddle(buffer);
					else {
						buffer = NULL;
					}
				}
			}
			else {
				if (x.First() == x.Last()) {
					buffer = NULL;
				}
				else {
					x.DeleteFromEnd();
					buffer = NULL;
				}
			}
		}
		else {
			buffer = buffer->Next();
		}
	}
}


*/
