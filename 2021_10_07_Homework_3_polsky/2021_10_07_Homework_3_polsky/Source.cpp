#include<iostream>
#include<string>
#include<stack>
using namespace std;
/*
int f2()
{
	stack <int> s;  
	string expression; 
	string number; 
	cin >> expression; 
	int i = 0; 
	while (isdigit(expression[i]) )
	{
		number += expression[i];
		i++; 
	}
	i = 0; 
	while(number[i] != '\0')
	{
		cin.
		i++; 
	}
	int num = 0; 
	cin >> num; 
	return num; 

}
*/
int main()
{
	char x; 
	double a, b, c, n; 
	stack<double> stack; 
	while (cin >> x)
	{
		if (isdigit(x))
		{
			cin.putback(x);
			cin >> n; 
			stack.push(n);
		}
	}
	
}