#include <iostream>
#include <string>
using namespace std;
string max(string& str1, string& str2,string result ="\0", int i = 0)
{
	if (str1 == str2)
		return "\0";
	if (str1[i] == ('\0'||'X'))
	{
		result = str2;
		str2 = "X";
	}
	else if (str2[i] == ('\0' || 'X'))
	{
		result = str1;
		str1 = "X";
	}
	else if (str1[i] > str2[i])
	{
		result = str1;
		str1 = "X";
	}
	else if (str1[i] < str2[i])
	{
		result = str2;
		str2 = "X";
	}
	else
	{
		result =  max(str1, str2, result, ++i);
	}
	if (result == "X")
		return "\0";
	return result;
}
string number(string*& mas)
{ 
	string result;
	for(int i = 0 ; i < 100 ; i++ ) 
		if (mas[i] != "X")
		{
			string lmax = mas[i];
			for (int j = 0; j < 100; j++)
			{
				if (i != j && mas[j] != "")
				{
					lmax = max(lmax, mas[j]);
					
				}
			}
			result += lmax;
		}
	return result; 
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
	cout << number(mas);
}