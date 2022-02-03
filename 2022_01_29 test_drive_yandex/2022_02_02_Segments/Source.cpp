#include <iostream>

using namespace std; 

struct Segment
{
	int begin = -1;
	int end = -1;
	bool busy = false;
};
void print(Segment* S, int quantity)
{
	int i = 0; 
	for (int i = 0; i < quantity; i++)
	{
		cout << i << " begin  = " << S[i].begin << " End =  " << S[i].end << " "; 
		if (S[i].busy == true)
			cout << "busy";
		else
			cout << "free";
		cout << endl << "______________________________________" << endl;
	}
}
bool set(Segment* S, Segment Set, int quantity)
{
	return true; 
}
int main()
{
	int quantity = 0; 
	cin >> quantity; 
	Segment* Segments = new Segment[quantity];
	int i = 0; 
	while (cin)
	{
		cin >> Segments[i].begin >> Segments[i].end; 
		i++; 
	}
	print(Segments, quantity); 

}