#include <iostream>
#include <cstdlib>
#include <omp.h>

using namespace std; 

double f(double x)
{
	double result = (1 / (1 + (x * x)));
	return result; 
}

int main()
{
	double n = 100000000;
	double result = 0;
	double sum = 0;
	double time = 0;
	//test parallel 
	cout << "2 streams " << endl;
	double t = omp_get_wtime();
#pragma omp parallel sections reduction (+:result)
	{
#pragma omp section 
		{
			for (int i = 1; i < n / 2; ++i)
			{
				result += f((2 * i - 1) / (2 * n));
			}

		}
#pragma omp section
		{

			for (int i = n / 2; i <= n; ++i)
			{
				result += f((2 * i - 1) / (2 * n));
			}

		}
	}
	//result = (result * 4.0) / n;
	time = omp_get_wtime() - t;
	cout << time << endl;
	cout << "time" << endl;
	cout << (result * 4.0) / n << endl;

	//No parallel 
	cout << endl << endl << "II" << endl << "No parallel " << endl;

	result = 0;
	sum = 0;
	t = omp_get_wtime();
	{
		{
			for (int i = 1; i <= n; ++i)
			{
				sum += f((2 * i - 1) / (2 * n));
			}
		}
	}
	time = omp_get_wtime() - t;
	result += (sum * 4) / n;

	cout << time << endl;
	cout << "time" << endl;
	cout << result << endl;
	cout << endl << endl << "III" << endl;

	cout << "4 streams " << endl;
	result = 0;
	t = omp_get_wtime();
#pragma omp parallel sections reduction (+:result)
	{
#pragma omp section 
		{

			for (int i = 1; i <= n / 4; ++i)
			{
				result += f((2 * i - 1) / (2 * n));
			}

		}
#pragma omp section
		{

			for (int i = n / 4; i <= n / 2; ++i)
			{
				result += f((2 * i - 1) / (2 * n));
			}

		}
#pragma omp section 
		{

			for (int i = n / 2; i <= (3 * n / 4); ++i)
			{
				result += f((2 * i - 1) / (2 * n));
			}
		}

#pragma omp section
		{

			for (int i = 3 * n / 4; i < n; ++i)
			{
				result += f((2 * i - 1) / (2 * n));
			}
		}
	}
	time = omp_get_wtime() - t;
	result = result * 4 / n;

	cout << time << endl;
	cout << "time : " << endl;
	cout << result << endl;

	cout << "schedule" << endl; 
	result = 0;
	sum = 0;
	t = omp_get_wtime();
#pragma omp parallel for schedule (guided)
			for (int i = 1; i <= n; ++i)
			{
				sum += f((2 * i - 1) / (2 * n));
			}
		
	time = omp_get_wtime() - t;
	result += (sum * 4) / n;


	return 0;


}
		/*
		//12 streams 
		result = 0;
		cout << "12 streams" << endl; 
		t = omp_get_wtime();
#pragma omp parallel sections 
		{
#pragma omp section 
			{
				double sum1 = 0;
				for (int i = 1; i < n / 12; i++)
				{
					sum1 += f((2 * i - 1) / (2 * n));
				}
				result += sum1;
			}
#pragma omp section
			{
				double sum2 = 0;
				for (int i = n / 12; i < 2*n / 12; i++)
				{
					sum2 += f((2 * i - 1) / (2 * n));
				}
				result += sum2;
			}
#pragma omp section 
			{
				double sum3 = 0;
				for (int i = 2*n / 12; i < 3 * n / 12; i++)
				{
					sum3 += f((2 * i - 1) / (2 * n));
				}
				result += sum3;
			}
#pragma omp section
			{
				double sum4 = 0;
				for (int i = 3 * n / 12; i < 4*n/12; i++)
				{
					sum4 += f((2 * i - 1) / (2 * n));
				}
				result += sum4;
			}
#pragma omp section 
		{
			double sum1 = 0;
			for (int i = 4*n/12; i < 5*n / 12; i++)
			{
				sum1 += f((2 * i - 1) / (2 * n));
			}
			result += sum1;
		}
#pragma omp section
		{
			double sum2 = 0;
			for (int i = 5*n / 12; i < 6*n / 12; i++)
			{
				sum2 += f((2 * i - 1) / (2 * n));
			}
			result += sum2;
		}
#pragma omp section 
		{
			double sum3 = 0;
			for (int i = 6*n / 12; i < 7 * n / 12; i++)
			{
				sum3 += f((2 * i - 1) / (2 * n));
			}
			result += sum3;
		}
#pragma omp section
		{
			double sum4 = 0;
			for (int i = 7 * n / 12; i < 8*n/12; i++)
			{
				sum4 += f((2 * i - 1) / (2 * n));
			}
			result += sum4;
		}

#pragma omp section 
		{
			double sum1 = 0;
			for (int i = 8*n/12; i < 9*n / 12; i++)
			{
				sum1 += f((2 * i - 1) / (2 * n));
			}
			result += sum1;
		}
#pragma omp section
		{
			double sum2 = 0;
			for (int i = 9*n / 12; i < 10*n / 12; i++)
			{
				sum2 += f((2 * i - 1) / (2 * n));
			}
			result += sum2;
		}
#pragma omp section 
		{
			double sum3 = 0;
			for (int i = 10*n / 12; i < 11 * n / 12; i++)
			{
				sum3 += f((2 * i - 1) / (2 * n));
			}
			result += sum3;
		}
#pragma omp section
		{
			double sum4 = 0;
			for (int i = 11 * n / 12; i < n; i++)
			{
				sum4 += f((2 * i - 1) / (2 * n));
			}
			result += sum4;
		}
		}
		result = result * 4 / n;
		cout << "time : " << omp_get_wtime() - t << endl;
		cout << result << endl;
		
		return 0;
	
} */