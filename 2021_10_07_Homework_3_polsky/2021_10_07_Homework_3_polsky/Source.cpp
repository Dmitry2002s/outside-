#include<iostream>
#include<string>
#include<stack>
using namespace std;

int f2()
{
	stack<int> s;
	int p; 
	int a, b = 0;  
	char x; 
	int result; 
	while (cin >> x)
	{
		if (isdigit(x))
		{
			cin.putback(x);
			cin >> p; 
			s.push(p);
		}
		else if(x != 'z') // окончить ввод буквой z ; 
		{
			a = s.top();
			s.pop();
			b = s.top();
			s.pop();
			switch (x)
			{
			case '+': s.push(a + b); break;
			case '-': s.push(b - a); break;
			case '*': s.push(a * b); break;
			case '/': s.push(b / a); break;
			}
		}
		else
		{
			return s.top();
		}
	}
	return s.top();
}
string f1()
{
/*stack<int> s;
	int p = 0; 
	char x; 
	string result; 
	char memory ='f';
	while (cin >> x && x!='z')
	{
		
		if (isdigit(x))
		{
			cin.putback(x);
			cin >> p; 
			result += to_string(p); 
			if (memory != 'f')
			{
				result += memory; 
				memory = 'f';
			}
		}
		else
		{
			memory = x; 
		}
	}
	int i = 0; 
	char mem; 
	while (result[i] != '\0')
	{
		if ((result[i] == '+' || result[i] == '-')&&(result[i+1] != '\0'))
		{
			if (result[i + 2] == '*' || result[i + 2] == '/')
			{
				mem = result[i]; 
				result[i] = result[i + 1];
				result[i + 1] = result[i + 2];
				result[i + 2] = mem;
			}
		}
		i++;
	}
	return result; 
	*/
	stack<char> sign;
	stack<int> numbers;
	char x;
	string result;
	int number; 
	while (cin >> x && x!='z')
	{
		if (isdigit(x))
		{
			cin.putback(x);
			cin >> number; 
			result += to_string(number);
		}
		else
		{
			if  ((x == '-' || x == '+'))
			{
				if (sign.empty() || sign.top() == '(')
				{
					sign.push(x);
				}
				else
				{

					result += sign.top();
					sign.pop();
					sign.push(x);
				}
			}
			else if (x == '*' || x == '/')
			{
				sign.push(x);
			}
			else if (x == '(')
			{
				sign.push(x);
			}
			else if (x == ')')
			{
				while (sign.empty()==false&&sign.top() != '(')
				{
					result += sign.top();
					sign.pop();
				}
				sign.pop();
			}
		}
	}
	while (sign.empty() == false)
	{
		result += sign.top();
		sign.pop();
	}
	return result; 
}
int main()
{
	cout << "result = " << f1() << endl; 
}