#include<iostream>

using namespace std; 

bool printArray(int** array,int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < 2; k++)
		{
			cout << array[i][k] << " ";
		}
		cout << endl; 
	}
	return true; 
}
int** createArray(int n, int c)
{
	int** array;
	array = new int* [n];
	for (int i = 0; i < n; i++)
	{
		array[i] = new int[c];
	}

	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < c; k++)
		{
			cin >> array[i][k];
		}
	}
	return array; 
}
int** swap(int** array, int n, int c, int k) // k -кол-во элементов в массиве , n и c - номера строк которые нужно заменить 
{
	int* string; 
	string = new int [k];
	for (int i = 0; i < k; i++)
	{
		string[i] = array[n][i];
	}
	for (int i = 0; i < k; i++)
	{
		array[n][i] = array[c][i];
		array[c][i] = string[i];
	}
	return array; 
}

int** sort(int** array,int n)
{
	for (int i = 0; i < n; i++)
	{
		for (int m = i; m < n; m++)
		{
			if (array[i][1] > array[m][1])
			{
				swap(array, i, m, 2);
			}
		}
	}
	return array;
}

int main()
{
	int n; 
	cin >> n; // n - кол-во массивов  
	int** array = createArray(n, 2);
	cout << endl; 
	printArray(array, n);
	sort(array, n);
	cout << endl; 
	printArray(array, n); 
	cout << endl << endl << endl; 

	int** points;
	points = new int* [n];
	for (int i = 0; i < n; i++)
	{
		array[i] = new int[2];
	}


	int P = 0; 
	for (int i = 0; i < n; i++)
	{
		if (array[i][1] >= array[n - 1][0])
		{
			points[P][1] << array[i][1];
			P++; 
			break;
		}
		
		else {
			for (int k = i + 1; k < n; k++)
			{
				if (array[i][1] < array[k][0])
				{
					points[P][1] << array[i][1];
					P++;
					break;
				}
			}
		}
	}
	printArray(points, n);	
}