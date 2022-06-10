// Vector.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Vector112.h"

using namespace std;

int main()
{
	Vector112 v1;
	Vector112 v2(5);
	Vector112 v3(5, 2);

	v3[0] = 77;
	v3.print();

	// 1 2 5 7 0 9
	//v1.insert(4, 777);   // в 4-ый элемент
	// 1 2 5 7 777 0 9
}

