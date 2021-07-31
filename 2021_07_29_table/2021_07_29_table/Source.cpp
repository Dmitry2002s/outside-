#include<iostream>
using namespace std;

int countMessages(int** messages, int n, int sourceMessage)
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (sourceMessage == messages[i][0])
		{
			count += 1; 
		}
		if (sourceMessage == messages[i][1])
		{
			count += countMessages(messages, n, messages[i][0]);
		}
	}
	return count; 
}

int main()
{
	int n = 0; 

	cin >> n; 
	int** messages = new int* [n];
	for (int i = 0; i < n; ++i)
	{
		cin >> messages[i][0] >> messages[i][1];
	}
	int sourceMessages = 0;
	cin >> sourceMessages; 
	cout << countMessages(messages, n, sourceMessages);
	for (int i = 0; i < n; ++i)
	{
		delete[] messages[i];
	}
		return 0; 
}