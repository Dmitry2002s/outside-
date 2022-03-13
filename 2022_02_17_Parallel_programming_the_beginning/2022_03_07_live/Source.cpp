
#include <iostream>
#include <omp.h>
#include <string>
#include <vector>
#include <map>
#include <set>
using namespace std;
struct cell
{
	int x = -3;
	int y = -3;
	bool operator!= (const cell& rv)
	{
		if (x != rv.x || y != rv.y)
			return false;
		return true;
	}

};
void Print(cell a)
{
	cout << a.x << " " << a.y << endl;
}
int q(cell* a)
{
	int result = 0;
	cell end;
	end.x = -3;
	end.y = -3;
	for (int i = 0; a[i] != end; i++)
		result++;
	return result;
}
void Print(map<int, cell> a)
{

	int size = 0;
	size = a.size();
	map <int, cell> ::iterator p;
	cout << "___________" << endl << "list of living cells" << endl;
	for (int i = 0; i < size; i++)
		Print(a[i]);
	cout << "___________" << endl;
}
map<int, cell> Live(vector<string> field)
{
	map<int, cell> result;
	int number = 0;
	cell a;
	int q = field.size();
	for (int j = 0; j < q; j++)
		for (int i = 0; field[j][i] != '\0'; i++)
		{
			if (field[j][i] == '1')
			{
				a.x = j;
				a.y = i;
				result[number] = a;
				number++;
			}


		}

	return result;

}
bool moment(vector<string> field, int i, int j)
{
	int neighboor = 0;
	vector<string> ::iterator a = field.end();
	vector<string> ::iterator p = field.begin() + i;
	int m_o = -1;
	int k_o = -1;
	int m_max = 2;
	int k_max = 2;
	if (field[i][j] == '\0')
		return false;
	if (i == 0)
		k_o++;
	if (j == 0)
		m_o++;
	if (p + 1 == a)
		k_max--;
	if (field[i][j + 1] == '\0')
		m_max--;
	for (int k = k_o; k < k_max; k++)
		for (int m = m_o; m < m_max; m++)
			if (k != 0 || m != 0)
				if (field[i + k][j + m] == '1')
					neighboor++;

	if (2 <= neighboor && neighboor <= 3 && field[i][j] == '1')
	{
		return true;
	}
	else if (neighboor == 3 && field[i][j] == '0')
	{
		return true;
	}
	else
		return false;
}
void Print(vector<string> field)
{

	int q = field.size();
	for (int j = 0; j < q; j++)
	{
		for (int i = 0; field[j][i] != '\0'; i++)
		{
			cout << field[j][i];
		}
		cout << endl;
	}
	cout << endl << endl;
}

vector<string> last(vector<string> field)
{
	string a;
	vector<string> result = field;
	for (int i = 0; i < field.size(); i++)
	{
		for (int j = 0; field[i][j] != '\0'; j++)
		{
			if (moment(field, i, j) == true)
				a += '1';
			else
				a += '0';
		}
		result[i] = a;
		a = "";
	}
	return result;
}
vector<string> last_multi(vector<string> field)
{
	string a;
	vector<string> result = field;
#pragma omp parallel sections 
	{
#pragma omp section 
		{
			int z = field.size() / 2;
			vector<string> result1;
			for (int i = field.size() / 2; i < field.size(); i++)
			{
				for (int j = 0; field[i][j] != '\0'; j++)
				{
					if (moment(field, i, j) == true)
						a += '1';
					else
						a += '0';
				}
				result[i] = a;
				a = "";
			}
		}
#pragma omp section 
		{
			for (int i = 0; i < field.size() / 2; i++)
			{
				for (int j = 0; field[i][j] != '\0'; j++)
				{
					if (moment(field, i, j) == true)
						a += '1';
					else
						a += '0';
				}
				result[i] = a;
				a = "";
			}
		}
	}
	return result;
}

int main()
{
	vector <string> field;
	string str;
	map<int, cell> result;

	/*while (cin >> str)
	{
		field.push_back(str);
	}
	moment(field, 2, 0);
	vector <string> new_field;
	double t = omp_get_wtime();
	for (int i = 100; i > 0; i--)
	{
		field = last(field);

	}
	cout << omp_get_wtime() - t << endl;
	cout << "test multi " << endl;
	field.clear();
	*/
	while (cin >> str)
	{
		field.push_back(str);
	}
	double m = omp_get_wtime();
	for (int i = 10; i > 0; i--)
	{
		field = last_multi(field);

	}
	cout << omp_get_wtime() - m << endl;

}
/*	
*/
