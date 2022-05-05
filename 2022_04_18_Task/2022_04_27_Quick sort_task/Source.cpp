
#include<iostream>
#include<cstdlib>
#include<omp.h>
using namespace std;
const int n = 1000; // ������ �������
// ������� partition ����� ��������� �������� ���
// ������������������ ������� � ���������� ��� �������������
// ������� � ��������������� �������
int partition(int a[n], int l, int r)
{
	int i = l - 1, j = r; // l � r � ����� � ������ �������
	int v = a[r]; // ������� ������� ������
	while (true)
	{
		while (a[++i] < v);
		// ������� i ������ ���� ����������� a[i] < a[r]
		while (v < a[--j])
			// ������� j ����� ���� ����������� a[r] < a[j]
			if (j == l) // �������� ������ �� ������� �������
				break;
		if (i >= j)
			break;
		swap(a[i], a[j]); // ������������ �������� a[i] � a[j]
	}
	swap(a[i], a[r]); // ������������ �������� a[i] � a[r]
	return i;
}

void qsort(int a[n], int l, int r)
{
	if (l >= r) return;
	int i = partition(a, l, r);
	qsort(a, l, i - 1); // ��������� ����� ����� �������
	qsort(a, i + 1, r); // ��������� ������ ����� �������
}
int main()
{

	int a[n];
	for (int& x : a) // ���������� �������� ���� for
		x = rand() % 100;
#pragma omp parallel 
	{
#pragma omp task 
		qsort(a, 0, n - 1);
	}
	for (int x : a)
		cout << x << " ";
	cout << endl;

	for (int& x : a) // ���������� �������� ���� for
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