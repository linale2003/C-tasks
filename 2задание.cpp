#include <iostream>
#include<ctime>
using namespace std;

/*Найти самое маленькое число в массиве и вывести его не экран*/

void main()
{
	setlocale(LC_ALL, "ru");

	srand(time(NULL));

	const int SIZE = 10;
	int arr[SIZE];

	bool alreadyThere;

	for (int i = 0; i < SIZE; )
	{
		alreadyThere = false;
		int newRanomValue = rand() % 20;

		for (int j = 0; j < i; j++)
		{
			if (arr[j] == newRanomValue)
			{
				alreadyThere = true;
				break;
			}
		}

		if (!alreadyThere)
		{
			arr[i] = newRanomValue;
			i++;
		}

	}

	// поиск минимального элемента массива

	int minValue = arr[0];

	for (int i = 1; i < SIZE; i++)
	{
		if (arr[i] < minValue)
		{
			minValue = arr[i];
		}
	}

	cout << "Наименьшее число в массиве " << minValue << endl;
}