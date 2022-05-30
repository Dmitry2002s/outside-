
#include <iostream>
#include <future>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;
const int n = 100000000; 


double f(double x)
{
	double result =1 / (1 + (x * x));
	return result;
}
double pi_counting(int from, int to )
{
	double sum = 0; 
	for (int i = from; i <= to ; ++i)
	{
		sum += f((2.0 * i - 1) / (2.0 * n));
	}
	return (sum * 4) / n;
}
/*double pi(int threads, int first_index)
{
	double n = 100000000;
	double result = 0;
	double sum = 0;
	
	for (int i = first_index; i <= n/2; ++i)
		{
			sum += f((2 * i - 1) / (2 * n));
		}
	for (int i = n/2; i <= n; ++i)
	{
		sum += f((2 * i - 1) / (2 * n));
	}
	return (sum * 4) / n;
}*/
/*
void MultiThreadPi(int threads)
{
	vector<future <void>> fut(threads);
	int bl_size = block_size(threads);
	int first_index = 0;
	int i = 0;
	while (first_index < n)
	{
		fut[i] = async(pi_counting, first_index,threads);
		first_index += bl_size;
		i++;
	}
	// можно явно написать вызовы f.get()
	for (int j = 0; j < i; ++j)
		fut[j].get();
	// дожидаемся результатов параллельных вычислений
}
*/

int main()
{
	/*
	double result = 0;
	double sum = 0;
	cout << endl << endl << "II" << endl << "No parallel " << endl;
	double t = 0; 
	result = 0;
	sum = 0;
	auto t1 = steady_clock::now();
	{
		{
			for (int i = 1; i <= n; ++i)
			{
				sum += f((2 * i - 1) / (2 * n));
			}
		}
	}
	auto t2 = steady_clock::now();
	auto time = duration_cast<milliseconds> (t2 - t1).count();
	cout << time << " ms " << endl;

	result += (sum * 4) / n;
	cout << result << endl;
	
	cout << "test asyns" << endl; 
	int p = 0; 
	cin >> p;  // p = threats 
	*/
	cout << "AAAAAAAAAAAAAAAAAAA" << endl << endl; 
	future<double> f1 = async(pi_counting, 1, 100000000 / 2);
	future<double> f2 = async(pi_counting, 100000000 / 2 + 1, 100000000);
	cout << (f1.get() + f2.get());

	
}

