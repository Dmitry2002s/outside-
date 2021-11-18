
#include <iostream>

using namespace std;
bool average(int a, int b, int c)
{
	if ((a >= b) & (a <= c))
		return true; 
	if ((a <= b) & (a >= c))
		return true;
	else
		return false;
}
bool med(int* mas, int i)
{
	if (average(mas[i], mas[(i + 1) % 3], mas[(i + 2) % 3]))
		{
			return true; 
		}
	else
	{
		
			if (average(mas[i] - mas[(i + 1) % 3], mas[(i + 1) % 3], mas[(i + 2) % 3]))
			{
				return true;
			}
			if (average(mas[i] - mas[(i + 2) % 3], mas[(i + 1) % 3], mas[(i + 2) % 3]))
			{
				return true;
			}
			if (average(mas[i], mas[(i + 1) % 3] - mas[i], mas[(i + 2) % 3]))
			{
				return true;
			}
			if (average(mas[i], mas[(i + 1) % 3] - mas[(i + 2) % 3], mas[(i + 2) % 3]))
			{
				return true;
			}
			if (average(mas[i], mas[(i + 1) % 3], mas[(i + 2) % 3] - mas[i]))
			{
				return true;
			}
			if (average(mas[i], mas[(i + 1) % 3] , mas[(i + 2) % 3]-mas[(i+1)%3]))
			{
				return true;
			}
			else
			{
				return false; 
			}
		
	}
}
void print(bool a)
{
	if (a == true)
	{
		cout << "YES" << endl;
	}
	else
		cout << "NO" << endl;
}

int main()
{
	int* mas = new int[3];
	for (int i = 0; i < 3; i++)
	{
		cin >> mas[i];
	}
	print(med(mas, 0));
	print(med(mas, 1));
	print(med(mas, 2));


	return EXIT_SUCCESS;
}