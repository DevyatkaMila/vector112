#pragma once
#include <iostream>

using namespace std;

class Vector112
{
	int* arr = nullptr;
	int len = 0;

public:
	// конструкторы
	Vector112() = default;
	Vector112(int len, int val = 0);
	Vector112(const int* arr, int size);

	// конструктор копирования    перегрузка оператора =   деструктор
	Vector112(const Vector112& vec);
	Vector112& operator=(const Vector112& vec);
	~Vector112();

	// добавить в конец значение
	void push_back(int val);
	// удалить последний элемент
	void pop_back();
	// добавить значениев начало
	void push_front(int val);
	// удалить первый элемент
	void pop_front();
	
	// печать массив
	void print() const;

	// вывод максимального значения
	void printMaxElem()const;
	// вывод минимального значения
	void printMinElem()const;

	// добавить элемен val по индексу
	void insert(int index, int val);
	// удалить элемент массива
	void erase(int index);		
	//удалить все вхождения значения val
	void remove(int val);

	inline int size() const { return this->len; }

	// очистка массива
	void clear();
	// проверить на nullptr
	bool empty() const;

	// вернуть элемент по индексу
	int operator[](int index) const;

	friend ostream& operator<<(ostream& out, const Vector112& arr);
	friend istream& operator>>(istream& in, Vector112& arr);
};

