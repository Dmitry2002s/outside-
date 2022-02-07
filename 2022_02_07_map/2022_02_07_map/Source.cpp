#include <iostream>
#include <map>
#include <vector> 
using namespace std; 
template <typename S, typename Z>
void Print(const map<S, Z>& m)
{
	for (const auto& item : m)
		cout << item.first << " : " << item.second << endl; 
}

/*template <typename A, typename A>
void Print(const map<A, A>& m)
{
	for (const auto& item : m)
		cout << item.first << " : " << item.second << endl;
}*/
void question1()
{
	vector<int> counters;
	map<int, int> numbers;
	int str;
	cin >> str; 
	while (cin)
	{
		counters.push_back(str);
		cin >> str;
	}
	for (const int& x : counters)
		++numbers[x];
	Print(numbers);
}
void question3() 
{
	map<int, int> numbers;
	int num;
	int data; 
	cout << "Define the function" << endl; 
	cin >> num >> data; 
	while (cin)
	{
		numbers[num] = data; 
		cin >> num >> data; 
	}
	cout << "enter a number for the function" << endl; 
	int N; 
	cin.clear();
	cin >> N; 
	if (numbers.count(N) != 0)
		cout << numbers[N] << endl;
	else
		cout << N << endl; 
}
template<typename T, typename N>
map<T,N> question4(map<T,N> x, map<T,N> y)  // объединение отображений ( отображения считаются непересекающимися) 
{
	map<T, N> result; 
	for (auto  p: x)
		result[p.first] = p.second;
	for (auto p : y)
		result[p.first]=p.second;
	return result; 
}

template<typename T, typename N>
map<T,N> question5(map<T,N> first, map<T,N> two)// композиция
{
	map <T, T> result; 
	for (auto x : first)
		for (auto y : two)
			if(y.first==x.second)
				result[x.first] = y.second; 
	return result; 
} 
int main()
{
	 //Для теста question4 
	//map <string, int> x1 = { {"one" , 4} , {"two" , 8 } };
	//map <string, int> x2 = { {"two" , 6} , {"four" , 9 } };

	map <int, int> x1 = { {1 , 4} , {2 , 8 } };
	map <int, int> x2 = { {4 , 6} , {8 , 9 } };
	Print(question5(x1, x2));
	
}
