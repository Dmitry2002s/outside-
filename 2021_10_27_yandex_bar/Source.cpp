#include <iostream>
#include <string>
using namespace std; 
struct ingr
{
	string name;
	int count;
	char x;
	ingr()
	{
		string name1;
		int count1 =0 ;
		char x1 =0;
		name=name1;
		count = count1;
		x = x1; 
			
	}
};
int main()
{
	int a = 0;//кол-во строк
	cin >> a;
	if (a < 2 || a>100)
	{
		return false; 
	}
	int b = 0;// кол-во столбцов / элементов в каждой строке 
	cin >> b;
	if (b < 3 || b>100)
	{
		return false;
	}
	string* bar = new string[a];
	string x;
	char p;
	getline(cin, x);

	for (int i = 0; i < a; i++)
	{
		getline(cin, x);
		bar[i] = x;
	};
	
	int count = 0;
	cin >> count;
	ingr* in = new ingr[count];
	for (int i = 0; i < count; i++)
	{
		cin >> in[i].name;
		cin >> in[i].count;
		cin >> in[i].x;
	}

	int i = a - 2;
	int m = 0;
	for (int k = 0; k < count; k++)
	{

		while ((m < in[k].count) & (i > 0))
		{
			for (int j = 0; j < b; j++)
			{
				if (bar[i][j] == ' ')
				{
					bar[i][j] = in[k].x;
				}
			}
			i--;
			in[k].count--;
		}


	}
	
	for (int i = 0; i < a; i++)
	{
		cout << bar[i] << endl;
	};
}