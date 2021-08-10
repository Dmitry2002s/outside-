#include<iostream>
using namespace std; 

int f(int n, int a=0 , int b=1 )
{
	
	if (n > 0)
	{
		f(n - 1, b, a + b);
	}
	if (n == 0)
	{
		return a + b;
	}

}

int main()
{
	
	int n = 0; 
	cin >> n; 
	if (n < 0)
		return 0;
	if (n == 0)
	{
		cout << 0;
	}
	if (1 <= n && n <= 2)
	{
		cout << 1; 
	}
	else if (n>=3)
	{
		n -= 2;
		cout << f(n);
	}
	return 0;
}