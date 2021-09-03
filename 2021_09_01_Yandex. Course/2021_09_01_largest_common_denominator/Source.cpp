#include<iostream>
using namespace std; 

LCD(int a, int b)
{

}

int main()
{
	int a; 
	int b; 
	cin >> a >> b; 
	if (a > b)
	{
		LCD(a, b);
	}
	else if (a == b)
	{
		cout << a; 
	}
	else
	{
		LCD(b, a);
	}
}