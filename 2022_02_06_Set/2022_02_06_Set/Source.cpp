#include <iostream>
#include <set>
using namespace std; 

void Print(set<int>  A)
{
	for (int s : A)
	{
		cout << s << endl; 
	}
}
void question1()//ќтобразить элементы без повторений 
{
	set <int> numbers;
	int k = 0; 
	while (cin)
	{
		cin >> k; 
		numbers.insert(k);
	}
	Print(numbers);
}
void question2()// отобразить элементы без повторений  , которые по€вл€ютс€ не менее 2 
{
	set <int> numbers;
	set <int> Cout; 
	int k = 0;
	while (cin)
	{
		cin >> k;
		if (numbers.count(k) == 1)
			Cout.insert(k); 
		else
			numbers.insert(k);
	}
	Print(Cout); 
}
void question3() // отобразить элементы без повторений , которые по€вл€ютс€ ровно 2 раза 
{
	set <int> numbers;
	set <int> Double;
	set <int> Cout;
	int k = 0;
	while (cin)
	{
		cin >> k; 
		if (numbers.count(k) == 0)
			numbers.insert(k);
		else if (Double.count(k) == 0 && Cout.count(k) == 0)
		{
			Double.insert(k);
			Cout.insert(k);
		}
		else
			Double.erase(k);
	}
	Print(Double);
}
template<typename T>  
set <T> question4 (set<T> set1, set<T> set2)
{
	set<T> result; 
	typename set<T>::iterator i;
	for (i = set1.begin(); i != set1.end(); ++i)
		result.insert(*i);
	for (i = set2.begin(); i != set2.end(); ++i)
		result.insert(*i);
	return result; 
}

int main()
{
	
	set<int > set1 = { 1, 2 ,3,4,5,6 };

	set<int > set2 = { 3, 4 ,5,6,7,8 };
	
	Print(question4(set1, set2));
}