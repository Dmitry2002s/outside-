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

int square_room(string* square, int i, int j ,int result = 0 )
{
	if (square[i][j] == '_')
	{
		result++; 
		square[i][j] = 'E';
		result += square_room(square, i + 1, j);
		result += square_room(square, i, j + 1 );
		result += square_room(square, i - 1 , j);
		result += square_room(square, i, j - 1 );
		
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
	for (int i = 0; square[i][0] != '\0';i++)
	{
		for (int j = 0; square[i][j] != '\0'; j++)
		{
			if (square[i][j] == '_')
			{
				if (square_room(square, i, j) < 5)
				{
					square_room_reserve(square,i,j);
					return false;
				}
				square_room_reserve(square,i ,j);
			}
		}
	}
	return true; 
}

bool insert_I(string*& square, int i, int j, bool reverse, bool turn, bool del) // i - Строка , j - столбец 
{
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
		if (square[i][j + rev] != extract)
		{
			return false;
		}
		j += rev;
	}
	if (square[i - p][j] != extract)
	{
		return false;
	}
	j = j_or;
	for (int k = 0; k < 4; k++)
	{
		(square[i][j + rev] = insert);
		j += rev;
	}
	(square[i - p][j] = insert);
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
}


int main()
{
	string* square = new string[20];
	string x; 
	int i = 0; 
	while (cin >> x)
	{

		square[i] += x;
		++i;
	}
	print(square);
	cout << check(square);
	print(square);
	bool((*figure[22]))(string * &square, int i, int j, bool reverse, bool turn, bool del);

	figure[0] = insert_L_0;
	figure[1] = insert_L_90;
	figure[2] = insert_I;
	figure[3] = insert_Y;
	figure[4] = insert_Y_90;
	figure[5] = insert_F;
	figure[6] = insert_F_90;
	figure[7] = insert_N;
	figure[8] = insert_N_90;
	figure[9] = insert_P;
	figure[10] = insert_P_90;
	figure[11] = insert_U;
	figure[12] = insert_U_90;
	figure[13] = insert_T;
	figure[14] = insert_T_90;
	figure[15] = insert_V;
	figure[16] = insert_V_90;
	figure[17] = insert_Z;
	figure[18] = insert_Z_90;
	figure[19] = insert_W;
	figure[20] = insert_W_90;
	figure[21] = insert_X;
	bool turn = false; 
	bool reverse = false; 
	for (int i = 0; i < 22; i++)
	{
		reverse = false;
		for (int l = 0; l < 2; l++)
		{
			turn = false;
			for (int k = 0; k < 2; k++)

			{
				figure[i](square, 5, 6, reverse, turn, false);
				print(square);
				figure[i](square, 5, 6, reverse, turn, true);
				turn = true;

			}
			reverse = true; 
		}
	}
}