#include "stdafx.h"
#include "Matr.h"
#include <iostream>

using namespace std;

void Set::add(int number)//добавление нового элемента в множество
{
	int *temp, pos;
	for (pos = 0; pos<size && mass[pos]<number; pos++) {}// поиск позиции под элемент
	if (mass[pos] != number)// добавление элемента, если его нет в множестве
	{
		temp = new int[++size];
		for (int i = 0; i<size - 1; i++)
		{
			if (i<pos)
			{
				temp[i] = mass[i];
			}
			else
			{
				temp[i + 1] = mass[i];
			}
		}
		temp[pos] = number;
		delete[] mass;
		mass = temp;
	}
	else
	{
		cout << "такой элемент уже есть" << endl;
	}
}
void Set::display()// вывод элементов множества
{
	cout << endl << "Элементы множества: ";
	for (int i = 0; i<size; i++)
	{
		cout << mass[i] << " ";
	}
	cout << endl;
}
void Set::checksize()// вывод количества элементов множества
{
	cout << "Количество элементов множества: " << size << endl;
}
void Set::del(int number)// удаление элемента множества
{
	if (size>0)// проверка на заполненность множества
	{
		int pos=0;
		/*for (pos = 0; pos<number && mass[pos]<number; pos++) {}*/// поиск элемента в множестве
		while (mass[pos] != number && pos< size){pos++;}

		if (mass[pos] == number)
		{
			int *temp;
			temp = new int[--size];
			for (int i = 0; i<size; i++)
			{
				if (i<pos)
				{
					temp[i] = mass[i];
				}
				else
				{
					temp[i] = mass[i + 1];
				}
			}
			delete[] mass;
			mass = temp;
		}
		else
		{
			cout << endl << "Ошибка. Такого элемента нет в множестве" << endl;
		}
	}
	else
	{
		cout << endl << "Ошибка. Множество пустое" << endl;
	}
}

int Set::sum()
{
	int sum=0;

	for (int i = 0; i < size; i++)
	{
		sum += mass[i];
	}
	cout << "Сумма эл-ов равна = " << sum<<" ";
	return sum;
}

int Set::otric()
{
	for (int i = 0; i < size; i++)
 {
		if (mass[i] < 0) return 1;
		return 0;
 }
}

int Set::ravn(Set* temp)
{
	if (size != temp->size) return 0;

	for (int i = 0; i < size; i++) {
		if (temp->mass[i] != mass[i]) return 0;
	}

	return 1;
}
