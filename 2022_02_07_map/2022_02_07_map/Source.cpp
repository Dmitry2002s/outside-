#include <iostream>
#include <map>
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
	map<int, int> numbers;
	int number;
	while (cin >> number)
	{
		if (numbers.count(number) == 0)
			numbers[number] = 1;
		else
		{
			++numbers[number];
		};
	}
	Print(numbers);
}
map<int, int> question2()
{
	map<int, int> res;
	int arg, result;
	int q;
	cin >> q; 
	int i = 0; 
	while (i < q)
	{
		cin >> arg >> result; 
		res[arg] = result;
		i++; 
	}
	return res;
} // к сдаче 
void question3()
{
	//map<int, int> numbers;
	int num;
	int data;
	cout << "Define the function" << endl;
	/*while (cin >> num >> data)
	{
		numbers[num] = data;
	}*/
	map<int, int> numbers = question2();
	cout << "enter a number for the function" << endl;
	int N;
	while (cin>>N)
	{
		if (numbers.count(N) != 0)
			cout << numbers[N] << endl;
		else
			cout << N << endl;
	}
}
template<typename T, typename N>
map<T, N> question4(map<T, N> x, map<T, N> y)  // объединение отображений ( отображения считаются непересекающимися) 
{
	map<T, N> result;
	for (auto p : x)
		result[p.first] = p.second; 
	for (auto p : y)
		result[p.first] += p.second; 
	return result;
}

/*else
			{
				result[x.first] = x.second;
				result[y.first] = y.second;
			}*/
template<typename T, typename N, typename S>
map<T, S> question5(map<T, N> first, map<N, S> two)
{
	map <T, S> result;
	
	for (auto x : first)
			result[x.first] = two[x.second];
	return result;
}
int main()
{
	//Для теста question4 
   //map <string, int> x1 = { {"one" , 4} , {"two" , 8 } };
   //map <string, int> x2 = { {"two" , 6} , {"four" , 9 } };

	map <int, int> x1 = { {1 , 4} ,{2 , 8}};
	map <int, int> x2 = { {4 , 6} , {8 , 9 } };
	//Print(question4(x1,x2));
	Print(question5(x1, x2));
}
