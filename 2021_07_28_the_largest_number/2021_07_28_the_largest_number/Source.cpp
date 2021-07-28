# include<iostream>
# include<string>
using namespace std; 
int GetLargestNumber(string s, int k=1, char max=0)
{
	if (s[k] == '\0')
	{
		return max; 
	}
	if (0 <= s[k] <= 9)
	{
		if (s[k] > max)
		{
			max = s[k];
		}
		return (GetLargestNumber(s, k + 1, max));
	}
	else {
		return -1; 
	}
}

int main()
{
	string s=""s;
	getline(cin, s);
		cout << (GetLargestNumber(s));

}