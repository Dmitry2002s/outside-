#include <iostream>
#include <string>
using namespace std;
int square(int** figure)
{
	int result = 0; 
	for (int i = 0; i < 0; i = 0);
	return 0; 
}
void print(string* square)
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; square[i][j] != '\0';j++)
		{
			cout << square[i][j]; 
		}
		cout << endl; 
	}
};
bool check(string* square)
{
	int i = 0; 
	for (int k = 0; square[k][0] != '\0'; k++)
	{
		for (int j = 0; square[k][j] != '\0'; j++)
		{
			if (square[k][j] == '_')
				i++; 
		}
	}
	if (i == 60)
		return true; 
	return false; 
}
int main()
{
	string* square = new string[20];
	string x; 
	int i = 0;
	while (cin >> x)
	{

		square[i] += x; 
		++i;
	}
	print(square);
	if(!check(square))
		return EXIT_FAILURE;
	return EXIT_SUCCESS;
	
}