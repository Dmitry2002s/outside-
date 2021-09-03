#include <iostream>
#include <cassert>
using namespace std; 

	int main()
	{
		int n; 
		cin >> n; 
		int a = 0; 
		int b = 1; 
		int c = 0; 
	
		for (int i = 1; i < n; i++)
		{
			c = b;	
			b = (a + b)%10; 
			a = c; 
		}
		cout << b; 
	
	}