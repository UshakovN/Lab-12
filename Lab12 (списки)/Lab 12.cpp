#include <iostream>
#include <locale.h>
#include "Queue.h"
#include "List.h"
using namespace std;

int main() {
	setlocale(LC_ALL, "Rus");

	try {
		List<int> L1;
		L1.DeleteFromBegin();
		//L1.DeleteFromEnd();
	//	List<int> L1(128);
		cout << "[Список 1]\n" << L1;
		L1.AddToBegin(10); 	L1.AddToBegin(15); 	L1.AddToBegin(20);
		cout << "[Список 1]\n" << L1;
		L1.AddToEnd(-6); L1.AddToEnd(-8); L1.AddToEnd(-12);
		cout << "[Список 1]\n" << L1;
		cout << L1.InfoBegin() << endl;
		cout << L1.InfoEnd() << endl;

		cout << "Если в списке из вещественных чисел есть отрицательный элемент, удалить из списка элементы, большие заданного значения." << endl;
		int z; cout << "Введите заданное значение z: ";
		cin >> z;
		Problem(L1, z);
		cout << "[Решение задачи]\n" << L1;

		List<char> L2;
		cin >> L2;
		cout << "[Список 2]\n" << L2;

		List<int> L3(L1);
		cout << "[Список 3]\n" << L3;
	}
	catch (const EMPTY ExceptionEmpty) {
		ExceptionEmpty.GetInfo();
	}


	/*
	try {
		cout << "Задание 1. Введите новую очередь:" << endl;
		Queue<int> Input1;
		cin >> Input1;
		cout << "[Исходная очередь] " << Input1 << endl;
		Queue<int> Divide; Queue<int> NonDivide;
		Problem1(Input1, Divide, NonDivide);
		cout << "[Очередь кратных 5] " << Divide << endl;
		cout << "[Очередь не кратных 5] " << NonDivide << endl;

		cout << "Задание 2. Введите новую очередь:" << endl;
		Queue<double> Input2;
		cin >> Input2;
		cout << "[Исходная очередь] " << Input2 << endl;
		Queue<double> Positive; Queue<double> Negative;
		Problem2(Input2, Positive, Negative);
		cout << "[Очередь положительных] " << Positive << endl;
		cout << "[Очередь неположительных] " << Negative << endl;

		cout << "Тесты методов:" << endl;

		Queue<int> Q1;
		cout << "[Очередь 1] " << Q1 << endl;

		//Q1.DeleteFromBegin();
		//Q1.DeleteFromEnd();

		Q1.AddToEnd(5); Q1.AddToEnd(8);
		cout << "[Очередь 1] " << Q1 << endl;

		Q1.AddToEnd(30); Q1.AddToEnd(17);
		cout << "[Очередь 1] " << Q1 << endl;

		int z = Q1.InfoEnd();
		cout << "Элемент из конца Очереди 1 = " << z << endl << endl;

		//Q1.AddToBegin('z');
		//Q1.AddToEnd('z');

		Q1.AddToBegin(15);
		cout << "[Очередь 1] " << Q1 << endl;
		Q1.DeleteFromEnd(); Q1.DeleteFromEnd();
		cout << "[Очередь 1] " << Q1 << endl;
		Q1.AddToEnd(30);
		cout << "[Очередь 1] " << Q1 << endl;

		Queue<int> Q2;
		cout << "[Очередь 2] " << Q2 << endl;
		Q2.AddToEnd(14);
		Q2.AddToEnd(8);
		cout << "[Очередь 2] " << Q2 << endl;

		Q1.AddToEnd(128);
		Q2.AddToEnd(256);
		cout << "[Очередь 1] " << Q1 << endl;
		cout << "[Очередь 2] " << Q2 << endl;

		cout << "TopToBottom для Очереди 1." << endl;
		Q1.TopToBottom(Q1);
		cout << "[Очередь 1] " << Q1 << endl;
		cout << "TopToBottom для Очереди 2." << endl;
		Q2.TopToBottom(Q2);
		cout << "[Очередь 2] " << Q2 << endl;
	}
	catch (const BADTYPE ExceptionInvalidType) {
		ExceptionInvalidType.GetInfo();
	}
	catch (const EMPTY ExceptionEmpty) {
		ExceptionEmpty.GetInfo();
	}
	*/

}
