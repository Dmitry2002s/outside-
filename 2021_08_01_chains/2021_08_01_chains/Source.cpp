#include<iostream>

using namespace std; 

bool chains( int n, int k,int i  )
{
	for (int i = 1; i < n; i++)
	{
		for (int p = 1; p < k; p++)
		{
			cout << p << " ";
		}
		
	}
	return 0; 
}

int main()
{
	int i = 1; 
	int n; // ���-�� ����� � ������� 
	int k; // ������������ ����� � ������� 
	cin >> n >> k; 
	chains(n, k, i);
}