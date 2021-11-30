#include <iostream>
#include <string>
using namespace std;

void print(string* square)
{
	cout << endl;
	for (int i = 0; square[i][0] != '\0'; ++i)
	{
		for (int j = 0; square[i][j] != '\0'; j++)
		{
			cout << square[i][j];
		}
		cout << endl;
	}
	cout << "________________________________________" << endl;
};

int sign(int a)
{
	if (a > 0)
		return 1;
	else
		return -1;
}


bool insert_I(string*& square, int i, int j, bool reverse, bool turn, bool del) // i - Строка , j - столбец 
{
	if (reverse == true)
		return false;
	int p = 0;
	int n = 0;
	if (turn == false)
		p = 1;
	else
		n = 1;
	char insert = 'I';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'I';
	}
	for (int k = 0; k < 5; k++)
	{
		if (square[i][j] != extract)
		{

			return false;
		}
		i += p;
		j += n;
	}

	for (int k = 0; k < 5; k++)
	{
		i -= p;
		j -= n;
		square[i][j] = insert;

	}
	return true;
}
// подумать над объединением поворотов.  // объединены 0 и 180 можно ли объединить их с 90 и 270 

bool insert_L_0(string*& square, int i, int j, bool reverse, bool turn, bool del) // передаётся координата конца хвоста 
{ // каким образом объединить поворот на 180 и 0 градусов ? 
	int p = 1;
	if (turn == true)
		p = -1;
	char insert = '_';
	char extract = 'L';
	if (del == true)
	{
		insert = 'L';
		extract = '_';
	}
	int rev = 1;
	if (reverse == true)
		rev = -1;
	int i_or = i;
	for (int k = 0; k < 4; k++)
	{
		if (square[i][j] != insert)
		{
			return false;
		}
		i += rev;
	}
	if (square[i - rev][j + p] != insert)
	{
		return false;
	}
	i = i_or;
	for (int k = 0; k < 4; k++)
	{
		(square[i][j] = extract);
		i += rev;
	}
	(square[i - rev][j + p] = extract);
	return true;
}
bool insert_L_90(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	int p = 1;
	if (turn == true)
		p = -1;
	char insert = 'L';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'L';
	}
	int rev = 1;
	if (reverse == true) // разобраться с reverse 
		rev = -1;
	int j_or = j;

	for (int k = 0; k < 4; k++)
	{
		if (square[i][j] != extract)
		{
			return false;
		}
		j += rev;
	}
	if (square[i - p][j - rev] != extract)
	{
		return false;
	}
	j = j_or;
	for (int k = 0; k < 4; k++)
	{
		(square[i][j] = insert);
		j += rev;
	}
	(square[i - p][j - rev] = insert);
	return true;
}


bool insert_Y(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	int p = 1;
	if (turn == true)
		p = -1;
	char insert = 'Y';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'Y';
	}
	int rev = 1;
	if (reverse == true)
		rev = 0;
	for (int k = 0; k < 4; k++)
	{
		if (square[i + k][j] != extract)
		{
			return false;
		}
	}
	if (square[i + 1 + rev][j + p] != extract)
	{
		return false;
	}
	for (int k = 0; k < 4; k++)
	{
		square[i + k][j] = insert;
	}
	(square[i + 1 + rev][j + p] = insert);
	return true;
}
bool insert_Y_90(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	int p = 1;
	if (turn == true)
		p = -1;
	char insert = 'Y';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'Y';
	}
	int rev = 1;
	if (reverse == true)
		rev = 0;
	for (int k = 0; k < 4; k++)
	{
		if (square[i][j + k] != extract)
		{
			return false;
		}
	}
	if (square[i + p][j + 1 + rev] != extract)
	{
		return false;
	}
	for (int k = 0; k < 4; k++)
	{
		(square[i][j + k] = insert);
	}
	(square[i + p][j + 1 + rev] = insert);
	return true;
}

bool insert_F(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	int p = 1;
	if (turn == true)
		p = -1;
	char insert = 'F';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'F';
	}
	int rev = 1;
	if (reverse == true)
		rev = -1;
	for (int k = -1; k < 2; k++)
	{
		if (square[i + k][j] != extract)
		{
			return false;
		}
	}
	if (square[i][j - p] != extract)
		return false;
	if (square[i - rev][j + p] != extract)
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i + k][j] = insert;
	}
	square[i][j - p] = insert;
	square[i - rev][j + p] = insert;
	return true;

}
bool insert_F_90(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	int p = 1;
	if (turn == true)
		p = -1;
	char insert = '_';
	char extract = 'F';
	if (del == true)
	{
		insert = 'F';
		extract = '_';
	}
	int rev = 1;
	if (reverse == true)
		rev = -1;
	for (int k = -1; k < 2; k++)
	{
		if (square[i][j + k] != insert)
			return false;
	}
	if (square[i + p][j + rev] != insert || square[i - p][j] != insert)
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i][j + k] = extract;

	}
	square[i + p][j + rev] = extract;
	square[i - p][j] = extract;
	return true;
}


bool insert_N(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	int p = 1;
	if (turn == true)
		p = -2;
	char insert = '_';
	char extract = 'N';
	if (del == true)
	{
		insert = 'N';
		extract = '_';
	}
	int rev = 1;
	if (reverse == true)
		rev = -1;
	for (int k = 0; k < 3; k++)
	{
		if (square[i - k][j] != insert)
			return false;
	}
	if (square[i + p - 1][j - rev] != insert)
		return false;
	if (square[i + p][j - rev] != insert)
		return false;
	for (int k = 0; k < 3; k++)
	{
		square[i - k][j] = extract;
	}
	square[i + p - 1][j - rev] = extract;
	square[i + p][j - rev] = extract;
	return true;
}
bool insert_N_90(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	int p = 1;
	if (turn == true)
		p = -1;
	char insert = '_';
	char extract = 'N';
	if (del == true)
	{
		insert = 'N';
		extract = '_';
	}
	int rev = 1;
	if (reverse == true)
		rev = -1;
	for (int k = 0; k < 3; k++)
	{
		if (square[i][j - k * p] != insert)
			return false;
	}
	if (square[i - rev][j] != insert)
		return false;
	if (square[i - rev][j + p] != insert)
		return false;
	for (int k = 0; k < 3; k++)
	{
		square[i][j - k * p] = extract;
	}
	square[i - rev][j] = extract;
	square[i - rev][j + p] = extract;
	return true;
}

bool insert_P(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	int t;
	if (reverse == false)
		t = 1;
	else
		t = -1;
	char insert = 'P';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'P';
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i][j + k] != extract)
			return false;
	}
	if (square[i - t][j] != extract)
		return false;
	if (square[i - t][j + p] != extract)
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i][j + k] = insert;

	}
	square[i - t][j] = insert;
	square[i - t][j + p] = insert;
	return true;
}
bool insert_P_90(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	int t;
	if (reverse == false)
		t = 1;
	else
		t = -1;
	char insert = 'P';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'P';
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i + k][j] != extract)
			return false;
	}
	if (square[i][j - t] != extract)
		return false;
	if (square[i + p][j - t] != extract)
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i + k][j] = insert;

	}
	square[i][j - t] = insert;
	square[i + p][j - t] = insert;
	return true;
}

bool insert_U(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	if (reverse == true)
		return false;
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	char insert = 'U';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'U';
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i + k][j] != extract)
		{
			return false;
		}
	}
	if (square[i - 1][j + p] != extract)
		return false;
	if (square[i + 1][j + p] != extract)
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i + k][j] = insert;
	}
	square[i - 1][j + p] = insert;
	square[i + 1][j + p] = insert;

	return true;
}
bool insert_U_90(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	if (reverse == true)
		return false;
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	char insert = 'U';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'U';
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i][j + k] != extract)
		{
			return false;
		}
	}
	if (square[i + p][j + 1] != extract)
		return false;
	if (square[i + p][j - 1] != extract)
		return false;
	square[i + p][j + 1] = insert;
	square[i + p][j - 1] = insert;
	for (int k = -1; k < 2; k++)
	{
		square[i][j + k] = insert;
	}

	return true;
}

bool insert_T(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	if (reverse == true)
		return false;
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	char insert = 'T';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'T';
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i + k][j] != extract)
		{
			return false;
		}
	}
	if (square[i - p][j - 1] != extract)
		return false;
	if (square[i - p][j + 1] != extract)
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i + k][j] = insert;
	}
	square[i - p][j - 1] = insert;
	square[i - p][j + 1] = insert;

	return true;
}
bool insert_T_90(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	if (reverse == true)
		return false;
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	char insert = 'T';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'T';
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i][j + k] != extract)
		{
			return false;
		}
	}
	if (square[i - 1][j - p] != extract)
		return false;
	if (square[i + 1][j - p] != extract)
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i][j + k] = insert;
	}
	square[i + 1][j - p] = insert;
	square[i - 1][j - p] = insert;

	return true;
}

bool insert_V(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	if (reverse == true)
		return false;
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	char insert = 'V';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'V';
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i + k][j] != extract)
		{
			return false;
		}
	}
	if (square[i - p][j + 2] != extract)
		return false;
	if (square[i - p][j + 1] != extract)
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i + k][j] = insert;
	}
	square[i - p][j + 2] = insert;
	square[i - p][j + 1] = insert;

	return true;
}
bool insert_V_90(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	if (reverse == true)
		return false;
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	char insert = 'V';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'V';
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i - k][j] != extract)
		{
			return false;
		}
	}
	if (j - 2 < 0)
		return false;
	if (square[i - p][j - 2] != extract)
		return false;
	if (square[i - p][j - 1] != extract)
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i - k][j] = insert;
	}
	square[i - p][j - 2] = insert;
	square[i - p][j - 1] = insert;

	return true;
}

bool insert_Z(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	if (reverse == true)
		return false;
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	char insert = 'Z';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'Z';
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i + k][j] != extract)
		{
			return false;
		}
	}
	if (square[i - 1][j - p] != extract)
		return false;
	if (square[i + 1][j + p] != extract)
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i + k][j] = insert;
	}
	square[i - 1][j - p] = insert;
	square[i + 1][j + p] = insert;

	return true;
}
bool insert_Z_90(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	if (reverse == true)
		return false;
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	char insert = 'Z';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'Z';
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i][j + k] != extract)
		{
			return false;
		}
	}
	if (square[i - p][j + 1] != extract)
		return false;
	if (square[i + p][j - 1] != extract)
		return false;
	square[i - p][j + 1] = insert;
	square[i + p][j - 1] = insert;
	for (int k = -1; k < 2; k++)
	{
		square[i][j + k] = insert;
	}

	return true;
}

bool insert_W(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	if (reverse == true)
		return false;
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	char insert = 'W';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'W';
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i + k * p][j + k * p] != extract)
			return false;
	}
	if (square[i + p][j] != extract)
		return false;
	if (square[i][j - p] != extract)
		return false;
	square[i + p][j] = insert;
	square[i][j - p] = insert;
	for (int k = -1; k < 2; k++)
	{
		square[i + k * p][j + k * p] = insert;
	}
	return true;
}
bool insert_W_90(string*& square, int i, int j, bool reverse, bool turn, bool del)
{
	if (reverse == true)
		return false;
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	char insert = 'W';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'W';
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i - k * p][j + k * p] != extract)
			return false;
	}
	if (square[i + p][j] != extract)
		return false;
	if (square[i][j + p] != extract)
		return false;
	square[i + p][j] = insert;
	square[i][j + p] = insert;
	for (int k = -1; k < 2; k++)
	{
		square[i - k * p][j + k * p] = insert;
	}
	return true;
}

bool insert_X(string*& square, int i, int j, bool reverse, bool turn, bool del) // i , j - координаты центра 
{
	char insert = '_';
	char extract = 'X';
	if (turn == true || reverse == true)
		return false;
	if (del == true)
	{
		insert = 'X';
		extract = '_';
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i][j + k] != insert)
		{
			return false;
		}
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i + k][j] != insert)
		{
			return false;
		}
	}
	for (int k = -1; k < 2; k++)
	{
		square[i][j + k] = extract;
	}
	for (int k = -1; k < 2; k++)
	{
		square[i + k][j] = extract;
	}
	return true;
} // почему-то вощвращает true при выходе с ошибкой 

int square_empty(string*& square, int i, int j, int result)
{
	if ((square[i][j] == '_'));
	{
		if (square[i][j] != '#')
		{
			result++;
			square[i][j] = 'E';

			result += square_empty(square, i + 1, j, 0);
			result += square_empty(square, i, j + 1, 0);
			square[i][j] = '_';
		}
	}

	return result;
}

bool checking_empty(string* square)
{
	for (int i = 1; square[i][0] != '\0'; i++)
	{
		for (int j = 1; square[i][j] != '\0'; j++)
		{

			if (square[i][j] == '_')
				print(square);
			if (square_empty(square, i, j, 0) < 5)
				return false;
		}
	}
	return true;
}
int square_room(string* square, int i, int j, int result = 0)
{
	if (square[i][j] == '_')
	{
		result++;
		square[i][j] = 'E';
		result += square_room(square, i + 1, j);
		result += square_room(square, i, j + 1);
		result += square_room(square, i - 1, j);
		result += square_room(square, i, j - 1);

	}
	return result;
}

void square_room_reserve(string* square, int i, int j)
{
	if (square[i][j] == 'E')
	{
		square[i][j] = '_';
		square_room_reserve(square, i + 1, j);
		square_room_reserve(square, i, j + 1);
		square_room_reserve(square, i - 1, j);
		square_room_reserve(square, i, j - 1);

	}
}
bool check(string* square)
{
	for (int i = 0; square[i][0] != '\0'; i++)
	{
		for (int j = 0; square[i][j] != '\0'; j++)
		{
			if (square[i][j] == '_')
			{
				if (square_room(square, i, j) % 5 != 0)
				{
					square_room_reserve(square, i, j);
					return false;
				}
				square_room_reserve(square, i, j);
			}
		}

	}
	return true;
}




bool enumeration(bool((*figure[21]))(string*& square, int i, int j, bool reverse, bool turn, bool del), string* square, int i)
{
	if (check(square) == false)
	{
		return false;
	}

	int memory = 0;
	int result = false;
	bool reverse = false;
	bool turn = false;

		
	for (int k = 1; square[k][1 && 0] != '\0'; k++)
	{
		
		for (int j = 1; square[k][j] != '\0'; j++)
		{

			if (square[k][j] != '#')
			{
				reverse = false;
				for (int m = 0; m < 2; m++)
				{
					turn = false;
					for (int n = 0; n < 2; n++)
					{
						if (i == 2 || i == 4 || i == 6 || i == 8 || i == 10 || i == 12 || i == 14 || i == 16 || i == 18 || i == 20)
						{
							if (figure[i](square, k, j, reverse, turn, false) == true)
							{

								memory = i;
								if (i == 21 || i == 20)
								{
									print(square);
									return true;
								}
								
								if (enumeration(figure, square, i + 2) == true)
								{
									print(square);
									return true;
								}
								figure[memory](square, k, j, reverse, turn, true);

							}
							if (figure[i+1](square, k, j, reverse, turn, false) == true)
							{
								memory = i + 1 ;
								if (i == 21 || i == 20)
								{
									print(square);
									return true;
								}


								if (enumeration(figure, square, i + 2) == true)
								{
									print(square);
									return true;
								}
								figure[memory](square, k, j, reverse, turn, true);
							}
						}
						else
						{
							
							if (figure[i](square, k, j, reverse, turn, false) == true)
							{
								
								memory = i;
								if (i == 21 || i == 20)
								{
									print(square);
									return true;
								}


								if (enumeration(figure, square, i + 1) == true)
								{
									print(square);
									return true;
								}
								figure[memory](square, k, j, reverse, turn, true);

							}
						}
						turn = true;
					}
					reverse = true;
				}

			}
		}
		
	}
	if (i == 0)
		cout << "The solution could not be found" << endl;
	return false;
}
bool test(bool((*figure[21]))(string*& square, int i, int j, bool reverse, bool turn, bool del), string* square, int i)
{
	if (check(square) == false)
	{
		return false;
	}

	i =2;
	int j = 0;

	int memory = 0;
	int result = false;
	bool reverse = true;
	bool turn = true;

	for (int k = 1; square[k][1 && 0] != '\0'; k++)
	{

		for (int j = 1; square[k][j] != '\0'; j++)
		{

			if (square[k][j] != '#')
			{
				reverse = true;
				for (int m = 0; m < 2; m++)
				{
					turn = true;
					for (int n = 0; n < 2; n++)
					{
						memory = i;
						if ((figure[i](square, k, j, reverse, turn, false)) == true)
						{

							print(square);


						}
						figure[memory](square, k, j, reverse, turn, true);

						turn = false;
					}
					reverse = false;
				}
			}
		}

	}

	return false;
}
int main()
{
	string* square = new string[60];
	string x;
	int i = 0;
	while (cin >> x)
	{

		square[i] += x;
		++i;
	}


	print(square);
	bool((*figure[22]))(string * &square, int i, int j, bool reverse, bool turn, bool del);

	figure[0] = insert_X; // 0 
	figure[1] = insert_I; // 1 
	figure[2] = insert_T; // 2 
	figure[3] = insert_T_90; // 3 
	figure[4] = insert_V; // 4 
	figure[5] = insert_V_90; // 5 
	figure[6] = insert_Z; // 6 
	figure[7] = insert_Z_90; // 7 
	figure[8] = insert_W; // 8   
	figure[9] = insert_W_90; // 9 
	figure[10] = insert_U_90; // 10 
	figure[11] = insert_U; // 11 
	figure[12] = insert_L_90; // 13 
	figure[13] = insert_L_0; // 12 
	figure[14] = insert_Y_90; // 15 
	figure[15] = insert_Y; // 14 
	figure[16] = insert_F; // 16 
	figure[17] = insert_F_90; // 17 
	figure[18] = insert_N_90; // 19 
	figure[19] = insert_N; // 18
	figure[20] = insert_P; // 20 
	figure[21] = insert_P_90; // 21 

	//test (figure, square, 2);
	enumeration(figure, square, 0);


	//test(figure, square, 1);

	return EXIT_SUCCESS;

}