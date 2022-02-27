#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <math.h>

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


int main()
{
	int n; 
	cin >> n; 

	cout << Prime_numbers(n);
	return EXIT_SUCCESS; 
}