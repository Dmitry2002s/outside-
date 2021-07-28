#include<iostream>
#include<string> 
using namespace std; 
int couting(string p, int n=0,int k = 0)
{
	if (p[n] == '\0')
	{
		return k; 
	}
	else if ('0' <= p[n] && p[n] <= '9')
	{
		return couting(p, n + 1,k+1);
	}
	else
	{
		return couting(p, n+1,k);
	}

}
int main()
{
	string p; 
	getline(cin, p);
	cout << couting(p);
}