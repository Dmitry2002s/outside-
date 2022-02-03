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
			if (S[i].free == 0 && S[j].free == 0 && result > distance(S[i], S[j]))
				result = distance(S[i], S[j]);
	return result;
}
//Возвращает минимальную дистанцию между занятыми. 
int maxDistance(Stall* S, int K)
{
	int M = 0; 
	int N = 0; 
	int result = 0; 
	int Z = 0;
	int number = -1 ; 
	for (int i = 0; i < K; i++)
	{
		if (i == 0)
			Z = distance(S[i], S[i + 1]);
		else if (i == K - 1)
			Z = distance(S[i], S[i - 1]);
		else
		{
			M = distance(S[i], S[i - 1]); 
			N = distance(S[i + 1], S[i]); 
			M < N ? Z = M : Z = N;
		}
		if (Z > result)
		{
			result = Z;
			number = i; 
		}
	}
	return number; 
}
//ВОзвращает точку, максимально удалённую от соседей(незанятых) . 
int NearestUP(Stall* S, int quantity, int number)
{
	for (int i = number + 1 ; i < quantity; i++)
	{
		if (S[i].free == false)
			return i; 
	}
	return -1; 
}
// Возвращает ближайший занятый вверх. Если таких нет , то -1. 
int NearestDOWN (Stall* S, int quantity, int number)
{
	for (int i = number-1; i > -1 ; i--)
	{
		if (S[i].free == false)
			return i;
	}
	return -1; 
} 
// Возвращает ближайший занятый вниз. Если таких нет , то -1. 
int maxDistanceToOccupied(Stall* S, int K)
{
	{
		int M = 0;
		int N = 0;
		int result = 0;
		int Z = 0;
		int number = -1;
		int Nearestup = -1; 
		int Nearestdown = -1;

		for (int i = 0; i < K; i++)
		{
			if (S[i].free == true)
			{
				Nearestdown = NearestDOWN(S, K, i);
				Nearestup = NearestUP(S, K, i);
				if (i == 0)
					Z = distance(S[i], S[Nearestup]);
				else if (i == K - 1)
					Z = distance(S[i], S[Nearestdown]);
				else
				{
					M = distance(S[i], S[Nearestdown]);
					N = distance(S[Nearestup], S[i]);
					M < N ? Z = M : Z = N;
				}
				if (Z > result)
				{
					result = Z;
					number = i;
				}
			}

		}
		return number;
	}
}
void firstElement(Stall* S, int K)
{
	S[maxDistance(S, K)].free = false; 
}
void Completion(Stall* S, int quantity, int quantityCow )
{
	for (int i = 0; i < quantityCow; i++)
	{
		if (i == 0)
			firstElement(S, quantity);
		else
		{
			S[maxDistanceToOccupied(S, quantity)].free = false; 
		}
	 }
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
	int N; //КОл-во стойл  
	int K; //КОл-во коров. 
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
	
	Completion(S, N, K);
	print(S, N);
	cout << minDistance(S, N) << endl; ;
	return 0; 
	
}