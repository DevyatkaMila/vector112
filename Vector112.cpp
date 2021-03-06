#include "Vector112.h"

Vector112::Vector112(int len, int val)
{
	this->len = len;
	this->arr = new int[this->len];
	for (int i = 0; i < this->len; i++) {
		this->arr[i] = val;
	}
}

Vector112::Vector112(const int* arr, int size)
{
	this->len = size;
	this->arr = new int[this->len];
	for (int i = 0; i < this->len; i++) {
		this->arr[i] = arr[i];
	}
}

Vector112::Vector112(const Vector112& vec):Vector112(vec.arr, vec.len){}  // делегирование на другой конструктор

Vector112& Vector112::operator=(const Vector112& vec)
{
	//защита от самоприсваивания
	if (this == &vec)
		return *this;

	//повторение конструктора копирования с проверкой на одинаковую длину this и vec
	if (this->len != vec.len) {
		this->~Vector112();
		this->len = vec.len;
		this->arr = new int[this->len];
	}

	for (int i = 0; i < this->len; i++)
	{
		this->arr[i] = vec.arr[i];
	}
	return *this;
}

Vector112::~Vector112()
{
	if (this->arr != nullptr) {
		delete[] this->arr;
		this->arr = nullptr;
		this->len = 0;
	}
}

void Vector112::push_back(int val)
{
	if (this->arr == nullptr) {
		/*this->arr = new int[1];
		this->arr[0] = val;
		this->len = 1;*/
		this->arr = new int[++this->len]{ val };
		return;
	}

	int* n_arr = new int[++this->len];
	for (int i = 0; i < this->len-1; i++) {
		n_arr[i] = this->arr[i];
	}
	n_arr[this->len-1] = val;
	delete[] this->arr;
	this->arr = n_arr;
}

void Vector112::pop_back()
{
	// массив пустой
	if (this->arr == nullptr)
		return;

	// массив из 1 элемента
	if (this->len == 1) {
		this->~Vector112();
		return;
	}

	// остальные случаи
	int* n_arr = new int[--this->len];
	for (int i = 0; i < this->len; i++) {
		n_arr[i] = this->arr[i];
	}
	delete[]this->arr;
	this->arr = n_arr;
}

void Vector112::push_front(int val)	
{
	if (this->arr == nullptr) {
		this->arr = new int[++this->len]{ val };
		return;
	}

	int* n_arr = new int[++this->len];
	n_arr[0] = val;
	for (int i = 0; i < this->len - 1; i++) {
		n_arr[i + 1] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = n_arr;
}

void Vector112::pop_front()
{
	if (this->arr == nullptr)
		return;

	if (this->len == 1) {
		this->~Vector112();
		return;
	}

	int* n_arr = new int[--this->len];
	for (int i = 1; i < this->len + 1; i++) {
		n_arr[i - 1] = this->arr[i];
	}
	delete[] this->arr;
	this->arr = n_arr;
}

void Vector112::print() const
{
	for (int i = 0; i < this->len; i++) {
		cout << this->arr[i] << "  ";
	}
	cout << endl;
}

void Vector112::printMaxElem() const
{
	if (this->arr == nullptr)
		return;

	int max = this->arr[0];
	for (int i = 1; i < this->len; i++) {
		if (max < this->arr[i])
			max = this->arr[i];
	}
	cout << max << endl;
}

void Vector112::printMinElem() const
{
	if (this->arr == nullptr)
		return;

	int min = this->arr[0];
	for (int i = 1; i < this->len; i++) {
		if (min > this->arr[i])
			min = this->arr[i];
	}
	cout << min << endl;
}

void Vector112::insert(int index, int val)
{
	// проверка индекса на корректность
	if (index > this->len || index < 0)
		return;

	if (index == this->len) {
		this->push_back(val);
		return;
	}
	if (index == 0) {
		this->push_front(val);
		return;
	 }
	
	int* n_arr = new int[this->len + 1];
	for (int i = 0; i < this->len; i++) {
		if (i < index) {
			n_arr[i] = this->arr[i];
		}
		else {
			n_arr[i + 1] = this->arr[i];
		}
	}
	n_arr[index] = val;
	this->len++;
	delete[] this->arr;
	this->arr = n_arr;
}

void Vector112::erase(int index)
{
	if (this->len == 0)
		return;

	if (index > this->len || index < 0)
		return;

	if (this->len == 1)
		this->~Vector112();

	int* n_arr = new int[this->len - 1];
	for (int i = 0; i < this->len; i++) {
		if (i < index)
			n_arr[i] = this->arr[i];
		else if (i > index)
			n_arr[i - 1] = this->arr[i];
	}
	this->len--;
	delete[] this->arr;
	this->arr = n_arr;
}

void Vector112::remove(int val)
{
	if (this->arr == nullptr)
		return;

	int count = 0;
	for (int i = 0; i < this->len; i++)
		if (this->arr[i] == val)
			count++;

	if (count == 0)
		return;

	if (count == this->len) {
		this->~Vector112();
		return;
	}

	int* n_arr = new int[this->len - count];
	for (int i = 0, k = 0; i < this->len; i++) {
		if (this->arr[i] != val) {
			n_arr[k++] = this->arr[i];
		}
	}
	this->len -= count;
	delete[] this->arr;
	this->arr = n_arr;
}

void Vector112::clear()
{
	this->~Vector112();
}

bool Vector112::empty() const
{
	return false;
}

int Vector112::operator[](int index) const
{

	return this->arr[index];
}

int& Vector112::operator[](int index)
{
	return this->arr[index];
}

ostream& operator<<(ostream& out, const Vector112& arr)
{
	return out;
}

istream& operator>>(istream& in, Vector112& arr)
{
	return in;
}
