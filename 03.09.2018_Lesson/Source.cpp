#include <iostream>
#include <iomanip>
#include<math.h>
#include<ctime>

using namespace std;

// 37.	** Написать функцию, которая принимает указатель на массив и количество элементов.Пользуясь ДВУМЯ указателями на массив целых чисел,
// функция должна поменять порядок элементов передаваемого ей массива на обратный.

void inversion(int *arr, int n){
	int *p1, *p2;
	p1 = arr;
	p2 = arr + n -1;

	/*for (p1 = arr, p2 = arr + n - 1; p1 < (arr + n / 2); p1++, p2--)
	{
		swap(*p1, *p2);
	}*/
	// или такой цикл, без разницы

	while (p1 < p2)
	{
		swap(*(p1), *(p2));
		p1++;
		p2--;
	}
	for (p1 = arr; p1 < arr + n; p1++)
		cout << *p1 << " ";
	cout << endl;
}
// 38.	*Написать программу, которая осуществляет поиск введенного пользователем числа, используя ДВА указателя на массив целых чисел.
// Первый указатель двигается с начала массива, второй – с конца.
void search(int *arr, int n) {
	int *p1, *p2;
	p1 = arr;
	p2 = arr + n - 1;
	int c;
	cin >> c;
	for (; p1 < (arr + n / 2); p1++, p2--)
	{
		if (*p1 == c) cout << p1 - arr << endl;
		if (*p2 == c) cout << p2 - arr << endl;
	}
}
// 39.	*Написать программу, которая вычисляет сумму элементов массива, используя ДВА указателя на массив целых чисел.
// Первый указатель двигается с начала массива, второй – с конца.
void sum(int *arr, int n) {
	int *p1, *p2;
	p1 = arr;
	p2 = arr + n - 1;
	int sum = 0;
	while (p1 <= p2)
	{
		if (p1 == p2) sum += *p1;
		else
			sum += *p1 + *p2;
		p1++;
		p2--;
	}
	cout << sum << endl << endl;
}
// 40.	*Написать программу, которая вычисляет сумму четных  элементов массива, используя ДВА указателя на массив целых чисел.
// Первый указатель двигается с начала массива, второй – с конца.
void sum_even_el(int *arr, int n) {
	int *p1, *p2;
	p1 = arr;
	p2 = arr + n - 1;
	int sum = 0;
	while (p1 <= p2)
	{
		if (p1 == p2 && *p1 % 2 == 0)
		{
			sum += *p1;
			break;
		}
		else
			if (*p1 % 2 == 0)
				sum += *p1;
			if (*p2 % 2 == 0)
				sum += *p2;
		p1++;
		p2--;
	}
	cout << sum << endl << endl;
}
// 41.	*Написать программу, которая вычисляет сумму элементов массива с четными номерами, используя ДВА указателя на массив целых чисел.
// Первый указатель двигается с начала массива, второй – с конца.
void sum_even(int *arr, int n) {
	int *p1, *p2;
	p1 = arr;
	p2 = arr + n - 1;
	int sum = 0;
	while (p1 <= p2)
	{
		if (p1 == p2) sum += *p1;
		else
			if ((p1 - arr) % 2 == 0)
				sum += *p1;
			if ((p2 - arr) % 2 == 0)
				sum += *p2;
		p1+=2;
		p2-=2;
	}
	cout << sum << endl << endl;
}
// 44.	**Даны два массива : А[M] и B[N](M и  N вводятся с клавиатуры).Необходимо создать третий массив минимально возможного размера,
// в котором нужно собрать элементы массивов A и B, которые не являются общими для них
void unique(int a[], int n, int b[], int m, int*&cc, int &d) {
	int k = 0, k1 = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n-1; j++)
			if (a[i] == a[j]) k1++;
	cout << k1 << endl;

	for (int i = 0; i < m; i++)
		for (int j = 0; j < m-1; j++)
			if (b[i] == b[j]) k1++;
	cout << k1 << endl;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i] == b[j]) k += 2;
		}
	}
	cout << k << " " << k1 << endl;
	int *c = new int[n + m - (k-k1)];
	/*int *tmp = new int(n + m);*/

	int p = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (a[i] != b[j])
			{
				c[p] = a[i];
				c[p++] = b[i];
			}
		}
	}

	for (int i = 0; i < p; i++)
		cout << c[i] << " ";
	cout << endl;
	
	delete[] cc;
	cc = c;
	d = k;

}




int main()
{
	srand(time(NULL));

	setlocale(LC_ALL, "Rus");

	int tn = 0;

	while (true)
	{
		cout << "Задача № ";
		cin >> tn;

		switch (tn)
		{
		case 1:
		{
			int **a;
			int n = 4, m = 6;
			a = new int*[n];

			for (int i = 0; i < n; i++)
				a[i] = new int[m];

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m; j++)
				{
					a[i][j] = rand() % 10;
					cout << a[i][j] << " ";
				}
				cout << endl;
			}
			cout << endl;

			for (int i = 0; i < n; i++)
				delete[] a[i];
			delete[] a;
		}
		break;
		case 2:
		{
			// 28.	*Создать 2 целые переменные и определить «расстояние» между ними в памяти.
			int *a, *b;
			a = new int;
			b = new int;

			cout << b - a << endl; // количество ячеек между ними
			delete a;
			delete b;

			int c, d;
			cout << &c << endl << &d << endl; // адрес ячеек будет постоянно меняться
			cout << &d - &c << endl; // полученное число умножить на 4 байта
			//переводим число в другой тип чтобы сразу выдавал в байтах, без умножения
			cout << (char*)&d - (char*)&c << endl; // char шагает по 1 байту, double по 8 байтов

			// void указатели
		}
		break;
		case 3:
		{
			int *a, *b;
			a = new int;
			b = new int;

			cout << a << endl << b << endl;
			cout << (char*)b - (char*)a << endl;

			delete a;
			delete b;
		}
		break;
		case 4:
		{
			int *a;
			int n = 7;
			a = new int[n];

			for (int i = 0; i < n; i++)
			{
				a[i] = i + 1;
				cout << a[i] << " ";
			}
			cout << endl;

			inversion(a, n);
			search(a, n);
			sum(a, n);
			sum_even_el(a, n);
			sum_even(a, n);
		}
		break;
		case 5:
		{
			
			int a[6] = { 2, 4, 7, 5, 2, 0 };
			int b[5] = { 4, 5, 9, 4, 8 };

			int d = 0;
			int *cc = new int[d];
			unique(a, 6, b, 5, cc, d);

			delete[] cc;
		}
		break;
		case 6:
		{
			int a[] = { 2, 4, 7, 5, 2, 0 };
			int b[] = { 4, 5, 9, 4, 8 };

			int* pa, *pb;
			pa = a;
			pb = b;

			int k = 0;
			for (int i = 0; i < 6; i++)
			{
				int sum = 0;
				for (int j = 0; j < 5; j++)
				{
					if (a[i] == b[j]) sum++;
				}
				if (sum = 0) k++;
			}

			int k1 = 0;
			for (int i = 0; i < 5; i++)
			{
				int sum = 0;
				for (int j = 0; j < 6; j++)
				{
					if (b[i] == a[j]) sum++;
				}
				if (sum = 0) k1++;
			}
			int *c;
			c = new int[k + k1];
			int h = 0;
			for (int i = 0; i < 6; i++)
			{
				int sum = 0;
				for (int j = 0; j < 5; j++)
				{
					if (a[i] == b[j]) sum++;
				}
				if (sum == 0) c[h++] = a[i];
			}

			for (int i = 0; i < 5; i++)
			{
				int sum = 0;
				for (int j = 0; j < 6; j++)
				{
					if (a[i] == b[j]) sum++;
				}
				if (sum == 0) c[h++] = b[i];
			}

			for (int i = 0; i < k + k1; i++)
				cout << c[i] << " ";
			cout << endl << endl;
		}
		break;
		case 7:
		{
			void *p; // "пустой" или универсальный указатель может хранить адреса любых переменных, файлов, функций
			// используют когда неизвестно откуда передается и также для безопасности, т.к. пустой указатель лишь показывает адрес, не вторгаясь в данные
			// через него нельзя напрямую получить доступ к данным под указателем
			int a=5;
			double b;
			p = &a;
			p = &b;

			/*cout << *p << endl;*/ // Но через него нельзя вывести значение под укзателем, нужно сначала первести в конкретный тип и тогда выведет
			cout << *((int*)p) << endl;
		}
		break;
		case 8:
		{
			int *p = new int[5];
			int a[10];

			delete[] p;
			p = a;
		}
		break;
		case 9:
		{
			int a, b;
			int *const p = &a;
			*p = 10; // см тетрадь
		}
		break;
		case 10:
		{
			// 58.	*Создать три переменные, создать три указателя на них, создать три указателя на указатели.
			// С помощью указателей получить переменные с клавиатуры.
			// С помощью указателей на указатели поменять значение самой большой и самой маленькой переменной местами.
			// Каждый этап решения задачи сопроводить подробным выводом значений переменных, указателей,
			// указателей на указатели и адресами переменных, указателей и указателей на указатели.

			int a, b, c;
			int *p, *p1, *p2;
			p = &a;
			p1 = &b;
			p2 = &c;
			int **pp, **pp1, **pp2;
			pp = &p;
			pp1 = &p1;
			pp2 = &p2;

			cin >> *p >> *p1 >> *p2;
			cout << *p << " " << *p1 << " " << *p2 << endl;

			int *min, *max;
			/*if (**pp > **pp1 && **pp > **pp2) pp = &max;
			else if (**pp1 > **pp2 && **pp1 > **pp2) pp1 = &max;
			else pp2 = &max;

			if (**pp < **pp1 && **pp < **pp2) pp = &min;
			else if (**pp1 < **pp2 && **pp1 < **pp2) pp1 = &min;
			else pp2 = &min;*/

			if (a > b) *pp = &a;
			else *pp = &b;
			if (c > **pp) *pp = &c;

			if (a < b) *pp2 = &a;
			else *pp2 = &b;
			if (c < **pp2) *pp2 = &c;

			swap(**pp, **pp2); 

			cout << **pp << " " << **pp1 << " " << **pp2 << endl;
		}
		break;
		case 11:
		{
			// 59.	**Функция принимает указатель на массив, его размер и указатель на переменную.
			// Определить, является ли переменная ячейкой массива(т.е значение указателя совпадает с одним из адресов ячеек массива),
			// является ли содержимое указателем адресом внутри массива, является ли содержимое указателя никак ни связанным с массивом адресом.
			// Функция должна вернуть три логических значения для каждого случая.
		}
		break;
		default:
			cout << "нет такой задачи" << endl << endl;
		}
	}
	system("pause");
	return 0;
}