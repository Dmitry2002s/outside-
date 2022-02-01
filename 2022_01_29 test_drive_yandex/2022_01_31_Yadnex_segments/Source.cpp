#include<iostream>

using namespace std; 

struct Stall
{
	int X = -1; 
	bool free = 1; 

	void print()
	{
		cout << "X = " << X << " ";
		free == true ? cout << "Free" : cout << "Occupied";
		cout << endl;
	}
};

void print(Stall* S, int count)
{
	for (int i = 0; i < count; i++)
	{
		cout <<  i << " "; 
		S[i].print();
	}
	cout << "_____________________________________________________" << endl;
}

int distance(Stall s, Stall k)
{
	int result = s.X - k.X; 
	if (result < 0)
		return -result; 
	return result; 
}

void placement(Stall* S, int K)
{
	for (int k = 0; k < K; k++)
	{
		S[k].free = 0; 
	}
}
int minDistance(Stall* S, int K)
{
	int result = 100000000; 
	for (int i = 0; i < K; i++)
		for (int j = i + 1; j < K; j++)
			if(S[i].free == 0 && S[j].free== 0 && result > distance(S[i], S[j]))
				result = distance(S[i], S[j]);
	return result; 
}
int replacement(Stall* S, int K)
{
	int newmin = 100000000;
	int min = minDistance(S, K);
	for (int i = 0; i < K; i++)
		
			for (int j = 0; j < K; j++)
				if (S[i].free == 0)
					if (S[j].free == 1 && i!= j)
					{
						S[i].free = 1;
						S[j].free = 0; 
						newmin = minDistance(S, K);
						if (newmin >= min)
						{
							min = newmin; 
						}
						else
						{
							S[i].free = 0;
							S[j].free = 1;
						}
						
					}
	return min; 
}


int main()
{
	int N; // ќл-во стойл  
	int K; // ќл-во коров. 
	cin >> N >> K;
	if (K > N)
	{
		cout << "error : quantity cow bigger than quantity stall" << endl;
		return false;
	}
	Stall* S = new Stall[N];
	int n = 0;  
	while (n<N)
	{
		cin >> S[n].X;
		n++; 
	}
	placement(S, K);
	
	minDistance(S, N);
	cout <<replacement(S, N);

	
}