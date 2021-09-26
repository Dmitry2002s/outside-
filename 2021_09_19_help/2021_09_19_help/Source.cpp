#include<iostream>
using namespace std;
int main(int argc, char* argv[])
{
	int a, b; 

	cin >> a >> b; // 123 
	cout << (b * (b / a) + a * (a / b)) / (a / b + b / a);
	
}