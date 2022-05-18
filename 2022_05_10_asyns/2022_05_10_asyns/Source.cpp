
#include <iostream>
#include <future>
#include <chrono>
#include <vector>
using namespace std;
using namespace std::chrono;
const int n = 100000000; 
int block_size(int threads)
{
	return n / threads + (n % threads ? 1 : 0);
}

double f(double x)
{
	double result = (1 / (1 + (x * x)));
	return result;
}
double pi_counting(double from, int threats )
{
	double sum = 0; 
	int  bl_size = block_size(threats);
	for (int i = from; i <= from +bl_size ; ++i)
	{
		sum += f((2 * i - 1) / (2 * n));
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


int main()
{
	
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

	cout << pi(p); 

	

	future<void>(pi);
}

