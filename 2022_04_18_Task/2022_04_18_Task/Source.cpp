#include <iostream>
#include <cmath >
using namespace std;  



double f(double x)
{
	return (1 / (1 + x * x));
}
double function(double a)
{

	return 1/a;
}

double integr(double a, double b, double function(double))
{
	double result = 0; 
	double left = 0; 
	double right = 0; 
	for (int i = 0; i < 10; i++)
	{
		left = a + i * (b-a) / 10;
		right = a + (i+1) * (b - a) / 10;
		result += (function(left) + function(right)) * (b-a) / 20;
	}
	return result; 
}

double integral(double a, double b, double function(double))
{
	double result = 0; 
	if ((integr(a, b, function) - integr(a, a + (b - a) / 2, function) - integr(a + (b - a) / 2, b, function))>(exp(-10)))
	{
		result+= integral(a, a + (b - a) / 2, function) + integral(a + (b - a) / 2, b, function);
	}
	else
	{
		result+= integr(a,b, function);
	}
	return result; 
}

double task_integral(double a, double b, double function(double))
{
	double result = 0;
	double result4 = 0;
#pragma omp parallel
	{
#pragma omp single
		{
#pragma omp task
			{
			double result3 = 0;
			result3 = integral(a, a + (b - a) / 3, function);
			result += result3; 
		}
#pragma omp task 
			{
			double result2 = 0;
			result2 = integral(a + (b - a) / 3, a + 2 * (b - a) / 3, function);
			result += result2; 
		}
#pragma omp task 
			{
				double resutl1 = 0;
				resutl1 = integral(a + 2 * (b - a) / 3, b, function);
				result += resutl1;
			}
		}
	}
	return result;
}

int main()
{
	double a; 
	cout << integr(1, 4, function) << endl; 
	cout << integral(1, 4, function) << endl; 
	cout << task_integral(1, 4, function) << endl; 
}