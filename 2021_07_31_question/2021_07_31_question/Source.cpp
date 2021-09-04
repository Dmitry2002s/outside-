#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	cin >> n;
	for (int k = n ; k > 0; k--)
	{
		for (int i = 1; i < k + 1; i++)
		{
			cout << i << " ";
			if (i > 1)
			{
				cout << -(i - 1) << " ";
			}

		}
	}
}



/*int main()
{
	int n = 0; 
	cin >> n; 
	if (n == 1)
	{
		cout << 1;
	}
	n += 1;
	
	for (; n > 0; n--)
	{
		for (int i = 1; i < n ; i++)
		{
			if (i != n - 1 && ((i != 1) || (n - 1 != 1) || (i != n - 1)))
			{
				cout << i << " ";
				
				if (i > 1 && n > 3 && i != n - 1)
					{
					cout << -(i - 1) << " ";
						
					}
				
			}
		}
	}
}*/