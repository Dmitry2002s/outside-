#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <math.h>
#include <cmath>

using namespace std; 

bool Prime(int number)
{
	if (number % 2 == 0)
		return false; 

	if (number % 3 == 0 && number != 3)
		return false;
	
	for (int i = 1; (6*i-1) * (6*i-1) <= number; i++)
	{
		if (number % (6 * i - 1) == 0)
			return false; 
		if (number % (6 * i + 1) == 0)
			return false;
	}
	return true; 
}
bool Prime_multi(int number)
{
	if (number % 2 == 0)
		return false;

	if (number % 3 == 0 && number != 3)
		return false;
#pragma omp parallel sections
	{

			for (int i = 1; (6 * i - 1) * (6 * i - 1) <= number; i++)
			{
#pragma omp section
				{
					if (number % (6 * i - 1) == 0)
					return false;
				}
#pragma omp section
				{
					if (number % (6 * i + 1) == 0)
						return false;
				}
			}
	

			
		
	}
	return true;
}
int Prime_numbers(int n)
{
	int count = 0; 
	for (int i = 3; i < n; i++)
	{
		if (Prime(i) == true)
			count++; 
	}
	return count; 
}
int Prime_numbers_multi(int n)
{
	int count = 0;
#pragma omp parallel sections(+:count)
	{
#pragma omp section

		{		for (int i = 5; i < n; i += 4)
			{
				if (Prime(i))
					count++;
			}
		}
#pragma omp section
		{
			for (int i = 3; i < n; i += 4)
			{
				if (Prime(i) == true)
					count++;
			}
		}
	}
	return count;
}



int main()
{
	int n; 
	cin >> n; 

	double m = omp_get_wtime();
	cout << Prime_numbers_multi(n) << endl;
	cout << "Time couple cores = " << (omp_get_wtime() - m) << endl;

	double t = omp_get_wtime();
	cout << Prime_numbers(n) << endl; 
	cout << "Time one core = " << ( omp_get_wtime() - t );

	
	return EXIT_SUCCESS; 
	//co
}