
#include<iostream>
#include<cstdlib>
#include<omp.h>
using namespace std;
const int n = 1000; // размер массива
// функция partition берет последний элемента еще
// неотсортированного массива и определяет его окончательную
// позицию в отсортированном массиве
int partition(int a[n], int l, int r)
{
	int i = l - 1, j = r; // l и r – левая и правая границы
	int v = a[r]; // крайний элемент справа
	while (true)
	{
		while (a[++i] < v);
		// двигаем i вправо пока выполняется a[i] < a[r]
		while (v < a[--j])
			// двигаем j влево пока выполняется a[r] < a[j]
			if (j == l) // проверка выхода за пределы массива
				break;
		if (i >= j)
			break;
		swap(a[i], a[j]); // переставляем значения a[i] и a[j]
	}
	swap(a[i], a[r]); // переставляем значения a[i] и a[r]
	return i;
}

void qsort(int a[n], int l, int r)
{
	if (l >= r) return;
	int i = partition(a, l, r);
	qsort(a, l, i - 1); // сортируем левую часть массива
	qsort(a, i + 1, r); // сортируем правую часть массива
}
int main()
{

	int a[n];
	for (int& x : a) // используем короткий цикл for
		x = rand() % 100;
#pragma omp parallel 
	{
#pragma omp task 
		qsort(a, 0, n - 1);
	}
	for (int x : a)
		cout << x << " ";
	cout << endl;

	for (int& x : a) // используем короткий цикл for
		x = rand() % 100;
#pragma omp parallel 
	{
#pragma omp task 
		qsort(a, 0, n - 1);
	}
	for (int x : a)
		cout << x << " ";
	cout << endl;




	return EXIT_SUCCESS;
}