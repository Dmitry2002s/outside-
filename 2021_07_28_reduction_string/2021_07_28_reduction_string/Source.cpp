#include<iostream>
#include<string> 
using namespace std; 


int length(string a, int n = 0)
{
	if (a[n] == '\0')
	{
		return n - 1;
		
	}
	n += 1;
	return length(a, n);
	
}

string noSimmetry(string a,string g, int n, int k=0)
{
	if (a[k] == '\0')
	{
		return g; 
	}
	if (a[n] != a[k])
	{
		g += a[n];
		return (g += noSimmetry(a, g, n - 1, k + 1));
	}
	else
	if (n == k)
		{
			g += a[n];
		}
		return (g += noSimmetry(a, g, n - 1, k + 1));
	}


/*bool reduction(string a, int k, int l = 0)
{
	
	 if (l > ((k)/2))
	{
		return false; 
	}
	 else if (a[l] == a[k])
	 {
		 return (reduction(a, k - 1, l + 1));
	 }
	
		cout << a[l];
		return (reduction(a, k - 1, l + 1));
	
}*/

int main()
{
	string g; 
	string a; 
	getline(cin, a);
	cout << "length = " << length(a) << endl;
	
	cout << "NoSimmetry ----- " << noSimmetry(a, g, length(a)) << endl;
	cout << a << endl << g;
	
	return 0;
}