#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <cmath>
#include <map>

using namespace std;

#define PI 3.14159265

int main()
{
	double smallness = 1000000; 
	cin >> smallness; 
	double* table = new double[smallness];
	double result = 0;
	double time = 0; 
	cout << "1 stream" << endl; 
	double t = omp_get_wtime(); 
	for (int i = 0; i < smallness; i += 1)
	{
		 table[i] = sin(i* (PI / (2 * smallness)));
	}
	time = omp_get_wtime() - t;
	cout << "time = " << time << endl;
	

	result = 0;
	cout << "2 streams" << endl; 
	t = omp_get_wtime();
#pragma omp parallel sections 
	{
#pragma omp section
		{
			for (int i = 0; i < smallness /2; i += 1)
			{
				table[i] = sin(i * PI / (2 * smallness));
			}
		}
#pragma omp section
		{
			for (int i = smallness / 2; i <= smallness; i += 1)
			{
				table[i] = sin(i * PI / (2 * smallness));
			}
		}
	}
	time = omp_get_wtime() - t;
	cout << "time = " << time << endl;

	result = 0;
	cout << "4 streams" << endl; 
	t = omp_get_wtime();
#pragma omp parallel sections 
	{
#pragma omp section
		{
			
			for (int i = 0; i < smallness /4; i += 1)
			{
				table[i] = sin(i * PI / (2 * smallness));
			}
		}
#pragma omp section
		{
			
			for (int i = smallness/4; i < smallness /2; i += 1)
			{
				table[i] = sin(i * PI / (2 * smallness));
			}
		}
#pragma omp section
		{
			for (int i = smallness/2; i < smallness *3/4; i += 1)
		{
			table[i] = sin(i * PI / (2 * smallness));
		}
		}
#pragma omp section
		{
			for (int i = smallness*3 /4; i <= smallness; i += 1)
			{
				table[i] = sin(i * PI / (2 * smallness));
			}
		}
	}
	time = omp_get_wtime() - t;
	cout << "time = " << time << endl;
	
	return EXIT_SUCCESS; 
}