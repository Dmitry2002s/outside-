#include <iostream>
#include <string>
using namespace std;
string max(string& str1, string& str2,string result ="\0", int i = 0)
{
	if (str1 == str2 == 'X')
		return "\0";
	if (str1[i] == '\0')
	{
		result = str2;
		str2 = "X";
		return result; 
	}
	else if (str2[i] == '\0')
	{
		result = str1;
		str1 = "X";
		return result; 
	}
	else if (str1[i] > str2[i])
	{
		result = str1;
		str1 = "X";
		return result; 
	}
	else if (str1[i] < str2[i])
	{
		result = str2;
		str2 = "X";
		return result;
	}
	else
	{
		return max(str1, str2, result, ++i);
	}
}
string number(string*& mas)
{
	string max; 
	string result; 
	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			max(mas[i], mas[j]);
	return 0; 
}

int main()
{
	string* mas = new string[100];
	int i = 0;
	while (cin)
	{
		getline(cin, mas[i]);
		i++;
	}
	max(mas[i], mas[i]);
	cout << number(mas);
}