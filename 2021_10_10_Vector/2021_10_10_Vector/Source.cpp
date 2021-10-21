#include <iostream>
#include <vector>
#include <algorithm>
using namespace std; 
bool print(vector<double> a)
{
	vector<double> ::iterator i;
	for (auto i : a)
	{
		cout << i << " ";
	}
	cout << endl;
	return true;
}
bool enlarge(vector<double> &a)
{
	vector<double> ::iterator i ;
	int x = 0; 
	int y = 0; 
	double k = 0; 
	vector<double> ::iterator m;
	if (a.begin() == a.end() || a.begin()++ == a.end())
	{
		return true; 
	}
	m = a.begin();
	i = a.begin();
	i++;
	while ( m != a.end() & i != a.end())
	{
		x = *(m);
		y = *(i);
		k = (x + y)/2; 
		i = a.insert(i, k);
		i++;
		m = i; 
		i++;
	}
	
}
bool del(vector<double>& a)
{
	vector<double> ::iterator i; 
	i = a.begin();
	i++;
	while (i != a.end())
	{
		i = a.erase(i);
		i++;
	}
	return true;
}

bool print(double* massive,int n)
{
	cout << "massive = " << endl; 
	for (int x = 0; x < n; x++)
	{
		cout << massive[x] << " ";
	}
	cout << endl; 
	return true;
}
int lenght(vector<double> a)
{
	int result = 0; 
	vector <double> ::iterator b; 
	b = a.begin();
	while (b != a.end())
	{
		result++;
		b++; 
	}
	return result; 
}
vector<double> concat(vector<double> a, vector<double> b)
{
	vector<double> result(a.size() + b.size(),0);
	vector <double> ::iterator p;
	copy(a.begin(), a.end(), result.begin());
	p = result.begin();
	for (int i = 0; i < a.size(); i++)
	{
		p++;
	}
	copy(b.begin(), b.end(),p);
	return result; 
}
vector<double> repeat(vector<double> a, int n)
{
	vector<double> result(a.size() * n);
	vector < double > ::iterator p; 
	p = result.begin();
	for (int z = 0; z < n; z++)
	{
		print(result);
		copy(a.begin(), a.end(), p);
		for (int i = 0; i < a.size(); i++)
		{
			p++;
		}
	}
	return result; 
}
vector<double> ::iterator found_2(vector<double> &a, int search )
{
	vector<double> ::iterator found =  find(++find(a.begin(), a.end(), search), a.end(), search);
	return found; 
}
vector<double> ::iterator found_last(vector<double> &a, int search)
{
	if (find(a.begin(), a.end(), search) == a.end())
	{
		return a.end();
	}
	else
	{
		vector<double> ::iterator result = a.end();
		vector<double> ::iterator test = a.begin();
		while (test != a.end())
		{
			result = test;
			test = find(++test, a.end(), search);

		}
			return result;
	}
}
vector<int> ::iterator found_upper(vector<int> a, int search)
{
	vector<int> ::iterator result = a.end();
	vector<int> ::iterator test = a.begin();
	while (test != a.end())
	{
		result = test;
		test = lower_bound(++test, a.end(), search);

	}
	return result; 
}
bool subseq(vector<double> a, vector<double> b)
{
	vector <double> ::iterator A = a.begin(); 
	vector <double> ::iterator border = a.begin();
	vector <double> ::iterator B = b.begin();
	while (A != a.end())
	{
		border =find(A, a.end(), *B);
		if (border != a.end())
		{
			A = border; 
			B++;
		}
		else
		{
			return false; 
		}
		return true; 
	}
}
bool availability(vector<double> a, double x, int& i, int& j)
{
	vector<double> ::iterator p = upper_bound(a.begin(), a.end(), x);
	if (p == a.end())
	{
		i = upper_bound(a.begin(), a.end(), x);
		j = lower_bound(a.begin(), a.end(), x); 
	}
	else
	{
		i = j = find(a.begin(), a.end(), x);
	}
}


int main()
{
	vector<double> a{ 1,9,18,27,36 };
	vector<double> b{ 2,10,19,28,37 };
	print(a);
	vector <double> ::iterator k; 
	k = a.begin();
	enlarge(a);
	print(a);
	del(a);
	cout << endl <<"test delete" << endl << endl; 
	print(a);
	int n = 5; 
	double *massive = new double[n];
	copy(a.begin(), a.end(), massive);
	print(massive, n);
	cout << "test concat " << endl;
	vector<double> result(a.size() + b.size(), 0);
	vector <double> test = concat(a, b);
	print(test);
	cout << "repeat" << endl; 
	vector <double> c = repeat(a, 5);
	print(c);
	vector <double> ::iterator op = found_2(c, 18);
	cout << "test found _ 2 " << endl; 
	print(c); 
	c.erase(op);
	print(c);
	op = found_last(c, 18);
	cout << "test found_last" << endl; 
	c.erase(op);
	print(c);
	cout << endl << endl << "test subseq " << endl; 
	vector<double> V{ 1,9,18,27,36 };
	vector<double> W{ 4, 3,1,9,18,27,36 };
	cout << subseq(W, V) << endl; 

	cout << subseq(V,W) << endl;
}