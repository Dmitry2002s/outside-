#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <cmath>
#include <map>

using namespace std;

#define PI 3.14159265

int main()
{
	map<double, double> table;
	double step = 1000000; 
	double result = 0;
	cout << "1 stream" << endl; 
	double t = omp_get_wtime(); 
	for (double i = 0; i < PI/2; i += (PI /(2* step)))
	{
		 table[i] = sin(i);
	}
	cout << "time = " <<  omp_get_wtime() - t << endl;
	

	result = 0;
	cout << "2 streams" << endl; 
	t = omp_get_wtime();
#pragma omp parallel sections 
	{
#pragma omp section
		{
			double result1 = 0;
			for (double i = PI/4; i <= PI/2; i += (PI /(2* step)))
			{
				table[i] = sin(i);
			}
		}
#pragma omp section
		{
			double result2 = 0;
			for (double i = 0; i < PI/4 ; i += (PI/ (2 * step)))
			{
				table[i] = sin(i);
			}
		}
	}
	cout << "time = " <<  omp_get_wtime() - t << endl;

	result = 0;
	cout << "4 streams" << endl; 
	t = omp_get_wtime();
#pragma omp parallel sections 
	{

#pragma omp section
		{
			
			for (double i = 3 * PI / 4; i <= PI / 2; i += (PI / (2 * step)))
			{
				table[i] = sin(i);
			}
		}
#pragma omp section
		{
			
			for (double i = PI / 4; i < 3*PI/8 ; i += (PI / (2 * step)))
			{
				table[i] = sin(i);
			}
		}
#pragma omp section
		{
		
			for (double i = PI / 8 ; i <PI/4; i += (PI / (2 * step)))
			{
				table[i] = sin(i);
			}
		}
#pragma omp section
		{
		
			for (double i = 0; i < PI/8 ; i += (PI /(2* step)))
			{
				table[i] = sin(i);
			}
		}
	}
	cout << "time = " << omp_get_wtime() - t << endl;

	return EXIT_SUCCESS; 
}