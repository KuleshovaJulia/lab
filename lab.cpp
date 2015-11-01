#include "stdafx.h"
#include "Matr.h"
#include <iostream>
#include <locale>
using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	Set Array[3];
	char choice;
	int temp, max_suma=0, min_suma=50;

	for (int i = 0; i < 3; i++)
	{
		/*Введите элементы множества" */
		do
		{
			cout << "Введите элемент множества: ";
			cin >> temp;
			Array[i].add(temp);
			cout << "Продолжить?(y/n): ";
			cin >> choice;
		} while (choice != 'n');
		Array[i].display();
		Array[i].checksize();
		cout << endl << "Введите элемент, который вы хотите удалить из множества: ";
		cin >> temp;
		Array[i].del(temp);
		Array[i].display();
		Array[i].checksize();
		Array[i].sum();

		cout << endl<<endl;
	}

	cout << endl;

	for (int i = 0; i<3; i++)
	{
		int suma = Array[i].sum();
		if (suma > max_suma) max_suma = suma;
		if (suma < min_suma) min_suma = suma;
	}
	cout << endl << "Максимальная сумма эл-ов: "<< max_suma << endl;
	cout << "Минимальная сумма эл-ов: " << min_suma << endl;

	for (int i = 0; i < 3; i++)
	{
		if (Array[i].otric() == 1) Array[i].display();
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = i + 1; j < 3; j++)
		{
			if (Array[i].ravn(&Array[j])) cout << "Множества " << i << " и " << j << " равны\n";
		}
	}

	return 0;
}
