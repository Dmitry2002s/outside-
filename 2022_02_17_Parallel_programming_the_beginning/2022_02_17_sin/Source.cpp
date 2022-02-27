#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <math.h>
using namespace std;



int main()
{
	double step = 100000000; 
	double result = 0;
	double t = omp_get_wtime(); 
	for (double i = 1; i > 0; i -= (1 / step))
	{
		result = i ;
	}
	cout << omp_get_wtime() - t << endl; 


	result = 0;
	t = omp_get_wtime();
#pragma omp parallel sections 
	{

#pragma omp section
		{
			double result1 = 0;
			for (double i = 1; i > 0.5; i -= (1 / step))
			{
				result1 = i;
			}
		}
#pragma omp section
		{
			double result2 = 0;
			for (double i = 0.5; i > 0; i -= (1 / step))
			{
				result2 = i;
			}
		}
	}
	cout << omp_get_wtime() - t << endl;

	result = 0;
	t = omp_get_wtime();
#pragma omp parallel sections 
	{

#pragma omp section
		{
			double result1 = 0;
			for (double i = 1; i > 0.75; i -= (1 / step))
			{
				result1 = i;
			}
		}
#pragma omp section
		{
			double result2 = 0;
			for (double i = 0.75; i > 0.5; i -= (1 / step))
			{
				result2 = i;
			}
		}
#pragma omp section
		{
			double result3 = 0;
			for (double i = 0.5; i > 0.25; i -= (1 / step))
			{
				result3 = i;
			}
		}
#pragma omp section
		{
			double result4 = 0;
			for (double i = 0.25; i > 0; i -= (1 / step))
			{
				result4 = i;
			}
		}
	}
	cout << omp_get_wtime() - t << endl;

	return EXIT_SUCCESS; 
}