#include <iostream>

using namespace std; 
 
struct Carnation
{
	int X = 0; 
	bool free = true; 
};
int distantion(Carnation C, Carnation V)
{
	int a = C.X - V.X;
	if (a> 0)
		return a;
	else
		return -a; 
}
bool freeCarnation(Carnation* Carnations, int quantity)
{
	for (int i = 0; i < quantity; i++)
		if (Carnations[i].free == true)
			return true; 
	return false;  
}
int set(Carnation* Carnations, int quantity, int distance=1)
{
	int result = 0; 
	for (int i = 0; i < quantity-1 ; i++)
	{
		for(int j = i+1; j < quantity; j++ )
		if (distantion(Carnations[i], Carnations[j]) == distance && (Carnations[i].free == true|| Carnations[j].free == true))
		{
			Carnations[i].free = false;
			Carnations[j].free = false; 
			result += distance; 
		}
	}
	if (freeCarnation(Carnations, quantity) == true)
		return result + set(Carnations, quantity, distance + 1);
	return result; 
}

int main()
{
	int quantity = 0; 
	cin >> quantity;
	Carnation* Carnations = new Carnation[quantity];
	int i = 0; 
	
	while (i<quantity)
	{
		cin >> Carnations[i].X; 
			i++; 
	}
	if (quantity == 1)
	{
		cout << 0;
		return 0;
	}
	cout << set(Carnations, quantity);
}