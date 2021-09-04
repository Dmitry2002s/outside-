#include<iostream>
#include<string>
using namespace std;

int main()
{
	string a = ""s;
	cin >> a; 
	for (int i = 0; i < a.length(); i++)
	{
		if (i % 2 == 1)
		{
			cout << a[i]; 
		}
	}
	cout << endl <<"end"; 
	int c = 0; 
	printf("% d \n ", c);
}