#include <iostream>
#include <cstdlib>
#include <omp.h>

using namespace std; 

int main()
{
	double t = omp_get_wtime();
	int sum = 0; 
	for (int i = 0; i < 10000000; i++)
	{
#pragma omp parallel sections 
		{
#pragma omp section
			{sum++; }
#pragma omp section 
			{sum++; }
		}
		 
		
	}
	cout << "Sum : " << sum << endl; 
	cout << "time : " << omp_get_wtime() - t << endl; 
	cout << " II " << endl; 
	t = omp_get_wtime();
	sum = 0;
#pragma omp parallel sections
	{ 
#pragma omp section
		{for (int i = 0; i < 10000000; i++)
			{
				{sum++; }
			}
		}
#pragma omp section 
		{for (int i = 0; i < 10000000; i++)
		{
			{sum++; }
		}
		}


	}
	cout << "Sum : " << sum << endl;
	cout << "time : " << omp_get_wtime() - t << endl;
	cout << "III" << endl; 
	t = omp_get_wtime();
	sum = 0;
	for (int i = 0; i < 10000000; i++)
	{
		{
			{sum++; }
			{sum++; }
		}
	}
	cout << "Sum : " << sum << endl;
	cout << "time : " << omp_get_wtime() - t << endl;
	cout << endl << endl << "IV" << endl; 
	
	
		t = omp_get_wtime();
		sum = 0;
#pragma omp parallel sections reduction(+:sum)
		{
#pragma omp section
			{
				for (int i = 0; i < 1000000; i++)
					sum++;
			}
#pragma omp section
			{
				for (int i = 0; i < 1000000; i++)
					sum++;
			}
		}
		cout << "Sum: " << sum << endl;
		cout << "Time: " << omp_get_wtime() - t << endl;
	return EXIT_SUCCESS; 
}