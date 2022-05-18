#include <iostream>
#include <omp.h>
using namespace std;


void divide(double** massive ,int number , double q, int lenght)
{
	for (int i = 0; i < lenght; i++)
		massive[number][i] = massive[number][i] / q; 
}
void subtract(double** massive, int one, int two, double q, int lenght)
{
	for (int i = 0; i < lenght; i++)
		massive[one][i] = massive[one][i] - q * massive[two][i];

}
void swap(double** massive, int one, int two, int lenght)
{
	double  k = 0; 
	for (int i = 0; i< lenght; i++)
	{
		k = massive[one][i]; 
		massive[one][i] = massive[two][i];
		massive[two][i] = k; 
	}
}
void print(double** massive , int lenght,int count)
{
	cout << "_____________________________________________" << endl;
	for (int i = 0; i < count ; i++)
	{
		for (int k = 0; k < lenght; k++)
			cout << massive[i][k] << " ";
		cout << endl; 
	}
	cout << "_____________________________________________" << endl;
}
void transform(double** massive, int lenght )
{
	for (int z = 0; z < lenght; z++)
	{
		int number_max = z;
		int max = 0;
		for (int i = z; i < lenght; ++i)
		{
			if (max < massive[i][0])
			{
				max = massive[i][0];
				number_max = i;
			}
		}
		swap(massive, z, number_max, lenght);
		divide(massive, z, massive[z][z], lenght);
		for (int k = 0; k < lenght; k++)
		{
			if(k!=z)
			subtract(massive, k, z, massive[k][z], lenght);
		}
	} 
}
void transform_par(double** massive, int lenght)
{

	for (int z = 0; z < lenght; z++)
	{
		int number_max = z;
		int max = 0;
		for (int i = z; i < lenght; ++i)
		{
			if (max < massive[i][0])
			{
				max = massive[i][0];
				number_max = i;
			}
		}
		swap(massive, z, number_max, lenght);
		divide(massive, z, massive[z][z], lenght);
#pragma omp parallel for schedule(static, 12)
		for (int k = z + 1; k < lenght; k++)
		{
			subtract(massive, k, z, massive[k][z], lenght);
		}
	}
}
int main()
{
	int n = 20; 
	cout << "count equation" << endl; 
	cin >> n; 
	int lenght = n + 1; 
	double** massive = new double *[n]; 
	for (int i = 0; i < n; i++)
		massive[i] = new double[lenght];

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < lenght; k++)
		{
			massive[i][k] = rand() % 10;
		}
	}
	double t = 0; 
	//(massive, lenght, n);
	t = omp_get_wtime();
	transform(massive, n);
	cout << omp_get_wtime() - t << endl; 
	//print(massive, lenght, n);

	
	cout << "test parallel" << endl; 
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < lenght; k++)
		{
			massive[i][k] = rand() % 10;
		}
	}
	//print(massive, lenght, n);
	t = omp_get_wtime();
	transform_par(massive, n);
	cout << omp_get_wtime() - t << endl;
	//print(massive, lenght, n);
}