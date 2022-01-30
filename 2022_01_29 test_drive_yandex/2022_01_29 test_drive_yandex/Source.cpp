#include <iostream>
#include <string>
using namespace std;
bool noMore(string test, int k, char num)
{
	while (test[k] != '\0')
	{
		if (test[k] < num)
			return false; 
		k++;
	}
	return true; 
}
bool more(string str1, string str2,bool result ="\0", int i = 0)
{
	if (str1 == str2)
		return false;
	else if (str1[i] == 'X' && str2 != "X")
		return false; 
	else if (str1[i] == '\0')
	{
		if (str2[i] != '0' && noMore(str2, i, str2[0]) ) //str2[i]>=str2[0])
				return false;
		result = true;
	}
		
	else if (str2[i] == '\0' )
	{

		if (str1[i] != '0' && noMore(str1, i, str1[0]) ) // str1[i]>=str1[0])
			return true;
		result = false;
	}
	else if (str1[i] > str2[i])
	{
		result = true;
	}
	else if (str1[i] < str2[i])
	{
		result = false;
	}
	else
	{
		result =  more(str1, str2, result, ++i);
	}
	return result;
}
string number(string*& mas,int countlines) // выводит конечный результат 
{ 
	string result;
	 //Номер максимального элемента. 
	for (int m = 0; m < countlines; m++)
	{
		int i = 0;

		int N = 0;
		while (mas[i] != "\0")
		{
			if (mas[i] != "X")
			{
				if (N != i && mas[i] != "")
				{
					if (more(mas[N], mas[i]) == false)
						N = i;
					//lmax = max(lmax, mas[j]);
				}

				//result += lmax;
			}
			i++;
		}

		if (mas[N] == "X")
		{

		}
		else {
			result += mas[N];
			mas[N] = 'X';
		}
	}
	return result; 
}

int main()
{
	string* mas = new string[100];
	int countlines = 0;
	while (cin)
	{
		getline(cin, mas[countlines]);
		countlines++;
	}

	cout  << number(mas, countlines);
}