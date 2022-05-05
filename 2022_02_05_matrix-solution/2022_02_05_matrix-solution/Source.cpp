#include <iostream>
using namespace std;

void divide(double** massive , int number , int q)
{
	for (int i = 0; massive[number][i] != '\0'; i++)
		massive[number][i] = massive[number][i] / q; 
}
void subtract(double** massive, int one, int two, double q)
{
	for (int i = 0; i < sizeof(massive) + 2 != '\0'; i++)
		massive[one][i] = massive[one][i] - q * massive[two][i];

}
void swap(double** massive, int one, int two)
{
	int k = 0; 
	for (int i = 0; i<sizeof(massive)+2 != '\0'; i++)
	{
		k = massive[one][i]; 
		massive[one][i] = massive[two][i];
		massive[two][i] = k; 
	}
}
void print(double** massive)
{
	cout << "_____________________________________________" << endl;
	for (int i = 0; i < sizeof(massive)+2; i++)
	{
		for (int k = 0; k < sizeof(massive[i])+2; k++)
			cout << massive[i][k];
		cout << endl; 
	}
	cout << "_____________________________________________" << endl;
}
void transform(double** massive)
{
	int number_max = 0;
	int max = 0;
	for (int i = 0; i<sizeof(massive)+2; ++i)
	{
		if (max < massive[i][0])
			max = massive[i][0];
			number_max = i;
		
		}
	cout << "check 1 " << endl; 
	print(massive);

	swap(massive,0, number_max);
	print(massive);

	cout << "check 2 " << endl;
	for (int k = 0; k < sizeof(massive); k++ )
	{
		for (int i = 1+k; i+k < sizeof(massive) + 2; i++)
		{
			double q = 0;
			q = (massive[i+k][k] / massive[0][k]);
			subtract(massive, i, k, q);
		}
			print(massive);
	}

}


int main()
{
	int n = 5; 
	double** massive = new double *[n]; 
	for (int i = 0; i < n; i++)
		massive[i] = new double[n];

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			massive[i][k] = rand() % 10;
		}
	}
	print(massive);
	transform(massive);
	print(massive);
	delete[] massive; 
}