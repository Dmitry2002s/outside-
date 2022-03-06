#include <iostream>
#include <cstdlib>
#include <omp.h>
#include <cmath>
#include <vector> 
using namespace std; 

struct Point
{
	double x, y, z; 
	Point()
	{
		x = 0; 
		y = 0; 
		z = 0; 
	}
	Point(double _x, double _y, double _z)
	{
		x = _x; 
		y = _y; 
		z = _z; 
	}
};
template <class T> 
int q(vector<T> v)
{
	
	vector<Point> ::iterator a;
	a = v.begin();
	int result = 0; 
	while (a != v.end())
	{
		result++;
		a++; 
	}
	return result; 
}
double dist(Point x, Point y)
{
	double result = sqrt((x.x - y.x)* (x.x - y.x) + (x.y - y.y)* (x.y - y.y) + (x.z - y.z)* (x.z - y.z));
	return result;
}

int main()
{
	vector<Point> Points;
	double x, y, z;
	while (cin >> x >> y >> z)
	{
		Points.push_back(Point(x, y, z));
	}
	cout << "quantity = " << q(Points) << endl;
	vector<Point> ::iterator end = Points.end();
	vector<Point> ::iterator beg = Points.begin();
	double t = omp_get_wtime();
	double max = 0;
	vector<Point> ::iterator i = Points.begin();
	double a;
	vector<Point> ::iterator m = i + 1;
	for (i = beg; i != end; i++)
		for (m = i + 1; m != end; m++)
		{
			a = dist(*i, *m);
			if (a > max)
				max = a;
		}
	cout << omp_get_wtime() - t << endl;
	cout << "max dist = " << max << endl;

	cout << endl << "Test 2 streams" << endl;
	t = omp_get_wtime();
	double max1 = 0;
	double max2 = 0;
	int e = q(Points) / 2;
#pragma omp parallel sections 
	{
#pragma omp section 
		{
			int e = q(Points) / 2;
			vector<Point> ::iterator i = Points.begin();
			vector<Point> ::iterator m = Points.begin();
			vector<Point> ::iterator beg = i;
			vector<Point> ::iterator end = i + e;
			for (i = beg; i != end; i++)
				for (m = i + 1; m != end; m++)
				{
					a = dist(*i, *m);
					if (a > max1)
						max1 = a;
				}
		}
#pragma omp section 
		{
			int e = q(Points) / 2;
			vector<Point> ::iterator i = Points.begin();
			vector<Point> ::iterator end = Points.end();
			vector<Point> ::iterator beg = i + e;
			vector<Point> ::iterator m = Points.begin();
			for (i = beg; i != end; i++)
				for (m = i + 1; m != end; m++)
				{
					a = dist(*i, *m);
					if (a > max1)
						max1 = a;
				}
		}
	}
	max1 > max2 ? max = max1 : max = max2;
	cout << omp_get_wtime() - t << endl;
	cout << "max dist = " << max << endl;

	cout << endl << "Test 3 streams" << endl;
	t = omp_get_wtime();
	max1 = 0;
	max2 = 0;
	double max3 = 0;
	double max4 = 0;
	int e1 = q(Points) / 3;
	int e2 = e1 * 2;
	int e3 = e1 * 3;
#pragma omp parallel sections 
	{
#pragma omp section 
		{

			vector<Point> ::iterator i = Points.begin();
			vector<Point> ::iterator m = Points.begin();
			vector<Point> ::iterator beg = i;
			vector<Point> ::iterator end = i + e1;
			for (i = beg; i != end; i++)
				for (m = i + 1; m != end; m++)
				{
					a = dist(*i, *m);
					if (a > max1)
						max1 = a;
				}
		}
#pragma omp section 
		{

			vector<Point> ::iterator i = Points.begin();
			vector<Point> ::iterator m = Points.begin();
			vector<Point> ::iterator beg = i + e1;
			vector<Point> ::iterator end = i + e2;
			for (i = beg; i != end; i++)
				for (m = i + 1; m != end; m++)
				{
					a = dist(*i, *m);
					if (a > max2)
						max2 = a;
				}
		}
#pragma omp section 
		{

			vector<Point> ::iterator i = Points.begin();
			vector<Point> ::iterator m = Points.begin();
			vector<Point> ::iterator beg = i + e2;
			vector<Point> ::iterator end = Points.end();
			for (i = beg; i != end; i++)
				for (m = i + 1; m != end; m++)
				{
					a = dist(*i, *m);
					if (a > max3)
						max3 = a;
				}
		}

	}
	if (max1 > max2)
		max = max1;
	else
		max = max2;
	if (max3 > max)
		max = max3;

	cout << omp_get_wtime() - t << endl;
	cout << "max dist = " << max << endl;




	cout << endl << "Test 4 streams" << endl;
	t = omp_get_wtime();
	max1 = 0;
	max2 = 0;
	max3 = 0;
	max4 = 0;
	e1 = q(Points) / 4;
	e2 = e1 * 2;
	e3 = e1 * 3;
#pragma omp parallel sections 
	{
#pragma omp section 
		{
			double a1 = 0;
			vector<Point> ::iterator i = Points.begin();
			vector<Point> ::iterator m = Points.begin();
			vector<Point> ::iterator beg = i;
			vector<Point> ::iterator end = i + e1;
			for (i = beg; i != end; i++)
			{


				for (m = i + 1; m != end; m++)
				{

					a = dist(*i, *m);
					if (a > max1)
						max1 = a;
				}
			}
		}
#pragma omp section 
		{
			double a2 = 0;
			vector<Point> ::iterator i = Points.begin();
			vector<Point> ::iterator m = Points.begin();
			vector<Point> ::iterator beg = i + e1;
			vector<Point> ::iterator end = i + e2;
			for (i = beg; i != end; i++) {
				for (m = i + 1; m != end; m++)
				{
					a = dist(*i, *m);
					if (a > max2)
						max2 = a;
				}

			}
		}
#pragma omp section 
			{
				double a3 = 0;
				vector<Point> ::iterator i = Points.begin();
				vector<Point> ::iterator m = Points.begin();
				vector<Point> ::iterator beg = i + e2;
				vector<Point> ::iterator end = i + e3;
				for (i = beg; i != end; i++)
					for (m = i + 1; m != end; m++)
					{
						a = dist(*i, *m);
						if (a > max3)
							max3 = a;
					}
			}
#pragma omp section 
			{
				double a4 = 0;
				vector<Point> ::iterator i = Points.begin();
				vector<Point> ::iterator m = Points.begin();
				vector<Point> ::iterator beg = i + e3;
				vector<Point> ::iterator end = Points.end();
				for (i = beg; i != end; i++)
					for (m = i + 1; m != end; m++)
					{
						a = dist(*i, *m);
						if (a > max4)
							max4 = a;
					}
			}
	}
		if (max1 > max2)
			max = max1;
		else
			max = max2;
		if (max3 > max)
			max = max3;
		if (max4 > max)
			max = max4;
		cout << omp_get_wtime() - t << endl;
		cout << "max dist = " << max << endl;

		return EXIT_SUCCESS;
	}
