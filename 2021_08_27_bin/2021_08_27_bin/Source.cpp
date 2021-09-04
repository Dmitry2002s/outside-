#include<iostream>

using namespace std;

int main()
{
	int a = 0;
	int b = 1;
	int f = 0;
	int c = 0;
	cin >> c;
	if (c >= 2)
	{
		for (int k = 1; k < c; k++)
		{
			f = a + b;
			a = b;
			b = f;
		}
	}
	else if (c == 1)
	{
		f = 1; 
	}
	cout << f << endl; 
}