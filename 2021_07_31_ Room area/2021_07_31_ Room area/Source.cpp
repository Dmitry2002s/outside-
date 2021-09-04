#include<iostream>

using namespace std; 

int size(int n, int a, int b, char field[10][10], int s = 0)
{
	if (a<0 || a>n ||b<0 || b>n)
	{
		return s;
	}
	if (field[a][b]=='.')
	{
		s += 1;
		field[a][b] = '*';
		s +=  size(n, a+1, b, field, 0);
		s +=  size(n, a-1, b, field, 0);
		s +=  size(n, a, b+1, field, 0);
		s +=  size(n, a, b-1, field, 0);
	};
	return s; 
}

int main()
{
	int n = 0; 
	cin >> n; 
	if (3 > n || 10 < n)
	{
		return -1;
	}
	
	char field[10][10];
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			cin >> field[i][k];
		}
	}
	int a = 0; 
	int b = 0;
	cin >> a >> b; 
	a -= 1;
	b -= 1;

	cout  << size(n,a,b,field) << endl;
	
	return 0; 
}