#include<iostream>
#include<string>
#include<stack>
using namespace std;

int f2()
{
	stack<int> s;

	string expression;
	string output; 

	cin >> expression;
	int i = 0;
	while (expression[i] != '\0')
	{
		if (isdigit(expression[i]))
		{
			int number = 0;
			while (isdigit(expression[i]) || expression[i] != '\0')
			{
				number = number * 10 + expression[i];
				i++;
			}
			s.push(number);
		}
		else
		{
			output += expression[i];
		}


	}

}
int main()
{
	
}