#include<iostream>

using namespace std; 

/*bool print(char a)
{
	for (int i = 0; i < 12; i++)
	{
		for (int k = 0; k < 12; k++)
		{
			cout << a[i][k];
		}
		cout << endl;
	}
}*/

int size(int n, int a, int b, char field[12][12], int s = 0)
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
	cout << "enter the room size " << endl;
	cin >> n; 
	if (3 > n || 10 < n)
	{
		return -1;
	}
	
	char field[12][12];
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			cout << field[i][k];
		}
		cout << endl; 
	}
	cout << "enter the room parameters " << endl; 
	for (int i = 0; i < n; i++)
	{
		for (int k = 0; k < n; k++)
		{
			cin >> field[i][k];
		}
		cout << endl;
	}
	int a = 0; 
	int b = 0;
	cout << "enter the coordinates of the room" << endl; 
	cin >> a >> b; 
	a -= 1;
	b -= 1;

	cout << "the size of the room is equal to  " << size(n,a,b,field) << endl;
	return 0; 
}