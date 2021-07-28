#include <iostream>
using namespace std; 
bool canGet(int n = -1)
{
	if (n <= 0)
	{
		return false; 
	}
	if (n == 1)
	{
		return true; 
	}
	return (canGet(n - 3) ||canGet (n -= 5));
}
int main()
{
	int n=-1; 
	cin >> n; 
	cout << (canGet(n) ? "Yes" : "No");
}
