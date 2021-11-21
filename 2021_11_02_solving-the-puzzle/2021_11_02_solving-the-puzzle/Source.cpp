#include <iostream>
#include <string>
using namespace std;

void print(string* square)
{
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; square[i][j] != '\0';j++)
		{
			cout << square[i][j]; 
		}
		cout << endl; 
	}
};
bool check(string* square)
{
	int i = 0; 
	for (int k = 0; square[k][0] != '\0'; k++)
	{
		for (int j = 0; square[k][j] != '\0'; j++)
		{
			if (square[k][j] == '_')
				i++; 
		}
	}
	if (i == 60)
		return true; 
	return false; 
}

bool insert_I(string*& square, int i , int j, bool turn , bool del) // i - Строка , j - столбец 
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
}

bool insert_L_0(string*& square, int i, int j) // передаётся координата конца хвоста 
{
	for (int k = 0; k < 4; k++)
	{
		if (square[i + k][j] != '_') 
		{
			return false; 
		}
	}
	if (square[i+3][j + 1] != '_')
	{
		return false; 
	}
	for (int k = 0; k < 4; k++)
	{
		(square[i + k][j] = 'L');
	}
	(square[i+3][j + 1] = 'L');
}
bool insert_L_0_turn(string*& square, int i, int j) // передаётся координата конца хвоста 
{
	for (int k = 0; k < 4; k++)
	{
		if (square[i + k][j] != '_')
		{
			return false;
		}
	}
	if (square[i + 3][j - 1] != '_')
	{
		return false;
	}
	for (int k = 0; k < 4; k++)
	{
		(square[i + k][j] = 'L');
	}
	(square[i + 3][j - 1] = 'L');
}
bool insert_L_90_turn(string*& square, int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		if (square[i][j+k] != '_')
		{
			return false;
		}
	}
	if (square[i + 1][j + 3] != '_')
	{
		return false;
	}
	for (int k = 0; k < 4; k++)
	{
		(square[i][j+k] = 'L');
	}
	(square[i + 1][j + 3] = 'L');

}
bool insert_L_90(string*& square, int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		if (square[i][j + k] != '_')
		{
			return false;
		}
	}
	if (square[i - 1][j + 3] != '_')
	{
		return false;
	}
	for (int k = 0; k < 4; k++)
	{
		(square[i][j + k] = 'L');
	}
	(square[i - 1][j + 3] = 'L');

}
bool insert_L_180(string*& square, int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		if (square[i - k][j] != '_')
		{
			return false;
		}
	}
	if (square[i - 3][j - 1] != '_')
	{
		return false;
	}
	for (int k = 0; k < 4; k++)
	{
		square[i - k][j] = 'L';
	}
	square[i - 3][j - 1] = 'L';
	
}
bool insert_L_180_turn(string*& square, int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		if (square[i - k][j] != '_')
		{
			return false;
		}
	}
	if (square[i - 3][j + 1] != '_')
	{
		return false;
	}
	for (int k = 0; k < 4; k++)
	{
		square[i - k][j] = 'L';
	}
	square[i - 3][j + 1] = 'L';

}
bool insert_L_270_turn(string*& square, int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		if (square[i][j - k] != '_')
		{
			return false;
		}
	}
	if (square[i - 1][j - 3] != '_')
	{
		return false;
	}
	for (int k = 0; k < 4; k++)
	{
		(square[i][j - k] = 'L');
	}
	(square[i - 1][j - 3] = 'L');

}
bool insert_L_270(string*& square, int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		if (square[i][j-k] != '_')
		{
			return false;
		}
	}
	if (square[i + 1][j - 3] != '_')
	{
		return false;
	}
	for (int k = 0; k < 4; k++)
	{
		(square[i][j - k] = 'L');
	}
	(square[i + 1][j - 3] = 'L');

}

bool insert_Y(string*& square, int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		if (square[i + k][j] != '_')
		{
			return false;
		}
	}
	if (square[i + 2][j + 1] != '_')
	{
		return false;
	}
	for (int k = 0; k < 4; k++)
	{
		(square[i + k][j] = 'Y');
	}
	(square[i + 2][j + 1] = 'Y');
}
bool insert_Y_0_turn(string*& square, int i, int j) // передаётся координата конца хвоста 
{
	for (int k = 0; k < 4; k++)
	{
		if (square[i + k][j] != '_')
		{
			return false;
		}
	}
	if (square[i + 2][j - 1] != '_')
	{
		return false;
	}
	for (int k = 0; k < 4; k++)
	{
		(square[i + k][j] = 'Y');
	}
	(square[i + 2][j - 1] = 'Y');
}
bool insert_Y_90_turn(string*& square, int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		if (square[i][j + k] != '_')
		{
			return false;
		}
	}
	if (square[i + 1][j + 2] != '_')
	{
		return false;
	}
	for (int k = 0; k < 4; k++)
	{
		(square[i][j + k] = 'L');
	}
	(square[i + 1][j + 2] = 'L');

}
bool insert_Y_90(string*& square, int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		if (square[i][j + k] != '_')
		{
			return false;
		}
	}
	if (square[i - 1][j + 2] != '_')
	{
		return false;
	}
	for (int k = 0; k < 4; k++)
	{
		(square[i][j + k] = 'Y');
	}
	(square[i - 1][j + 2] = 'Y');

}
bool insert_Y_180(string*& square, int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		if (square[i - k][j] != '_')
		{
			return false;
		}
	}
	if (square[i - 2][j - 1] != '_')
	{
		return false;
	}
	for (int k = 0; k < 4; k++)
	{
		square[i - k][j] = 'L';
	}
	square[i - 2][j - 1] = 'L';

}
bool insert_Y_180_turn(string*& square, int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		if (square[i - k][j] != '_')
		{
			return false;
		}
	}
	if (square[i - 2][j + 1] != '_')
	{
		return false;
	}
	for (int k = 0; k < 4; k++)
	{
		square[i - k][j] = 'L';
	}
	square[i - 2][j + 1] = 'L';

}
bool insert_Y_270_turn(string*& square, int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		if (square[i][j - k] != '_')
		{
			return false;
		}
	}
	if (square[i - 1][j - 2] != '_')
	{
		return false;
	}
	for (int k = 0; k < 4; k++)
	{
		(square[i][j - k] = 'Y');
	}
	(square[i - 1][j - 2] = 'Y');

}
bool insert_Y_270(string*& square, int i, int j)
{
	for (int k = 0; k < 4; k++)
	{
		if (square[i][j - k] != '_')
		{
			return false;
		}
	}
	if (square[i + 1][j - 2] != '_')
	{
		return false;
	}
	for (int k = 0; k < 4; k++)
	{
		(square[i][j - k] = 'L');
	}
	(square[i + 1][j - 2] = 'L');

}

bool insert_F(string*& square , int i, int j)
{
	for (int k = -1; k < 2; k++)
	{
		if (square[i+k][j] != '_')
		{
			return false; 
		}
	}
	if (square[i][j-1] != '_')
		return false; 
	if (square[i-1][j+1] != '_')
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i+k][j] = 'F';
	}
	square[i][j - 1] = 'F';
	square[i-1][j+1] = 'F';
		
}
bool insert_F_turn(string*& square, int i, int j)
{
	for (int k = -1; k < 2; k++)
	{
		if (square[i + k][j] != '_')
		{
			return false;
		}
	}
	if (square[i][j - 1] != '_')
		return false;
	if (square[i + 1][j] != '_')
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i + k][j] = 'F';
	}
	square[i][j + 1] = 'F';
	square[i - 1][j - 1] = 'F';

}
bool insert_F_90(string*& square, int i, int j)
{
	for (int k = -1; k < 2; k++)
	{
		if (square[i][j + k] != '_')
			return false;
	}
	if (square[i + 1][j + 1] != '_' || square[i-1][j] != '_')
		return false; 

	for (int k = -1; k < 2; k++)
	{
		square[i][j + k] = 'F';
			
	}
	square[i + 1][j + 1] = 'F';  
	square[i-1][j] = 'F';
}
bool insert_F_90_turn(string*& square, int i, int j)
{
	for (int k = -1; k < 2; k++)
	{
		if (square[i][j + k] != '_')
			return false;
	}
	if (square[i - 1][j + 1] != '_' || square[i+1][j-1] != '_')
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i][j + k] = 'F';

	}
	square[i + 1][j - 1] = 'F';
	square[i - 1][j] = 'F';
}
bool insert_F_180_turn(string*& square, int i, int j)
{
	for (int k = -1; k < 2; k++)
	{
		if (square[i + k][j] != '_')
		{
			return false;
		}
	}
	if (square[i][j - 1] != '_')
		return false;
	if (square[i + 1][j+1] != '_')
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i + k][j] = 'F';
	}
	square[i][j - 1] = 'F';
	square[i + 1][j + 1] = 'F';

}
bool insert_F_180(string*& square, int i, int j)
{
	for (int k = -1; k < 2; k++)
	{
		if (square[i + k][j] != '_')
		{
			return false;
		}
	}
	if (square[i][j + 1] != '_')
		return false;
	if (square[i + 1][j - 1] != '_')
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i + k][j] = 'F';
	}
	square[i][j + 1] = 'F';
	square[i + 1][j - 1] = 'F';

}
bool insert_F_270_turn(string*& square, int i, int j)
{
	for (int k = -1; k < 2; k++)
	{
		if (square[i][j + k] != '_')
			return false;
	}
	if (square[i + 1][j - 1] != '_' || square[i - 1][j] != '_')
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i][j + k] = 'F';

	}
	square[i - 1][j - 1] = 'F';
	square[i + 1][j] = 'F';
}
bool insert_F_270(string*& square, int i, int j)
{
	for (int k = -1; k < 2; k++)
	{
		if (square[i][j + k] != '_')
			return false;
	}
	if (square[i + 1][j - 1] != '_' || square[i - 1][j] != '_')
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i][j + k] = 'F';

	}
	square[i + 1][j - 1] = 'F';
	square[i - 1][j] = 'F';
}

bool insert_N(string*& square, int i, int j , bool turn)
{
	int p; 
	if (turn == false)
		p = 1;
	else
		p = -1; 
	for (int k = 0; k < 3; k++)
	{
		if (square[i - k][j] != '_')
			return false;
	}
	if (square[i][j - p] != '_')
		return false; 
	if (square[i - 1][j - p] != '_')
		return false; 
	for (int k = 0; k < 3; k++)
	{
		square[i - k][j] = 'N';
	}
	square[i][j - p] = 'N';
	square[i + 1][j - p] = 'N';
}
bool insert_N_90(string*& square, int i, int j, bool turn)
{
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	for (int k = 0; k < 3; k++)
	{
		if (square[i][j + k] != '_')
			return false; 
	}
	if (square[i-p][j] != '_')
		return false; 
	if (square[i - p][j -1 ] != '_')
		return false; 

	for (int k = 0; k < 3; k++)
	{
		square[i][j + k] = 'N';
	}
	square[i - p][j] = 'N';
	square[i - p][j-1] = 'N';
}
bool insert_N_180(string*& square, int i, int j, bool turn, bool del)
{
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	char insert = 'N';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'N';
	}
	for (int k = 0; k < 3; k++)
	{
		if (square[i + k][j] != extract)
			return false;
	}
	if (square[i][j - p] != extract)
		return false;
	if (square[i - 1][j - p] != extract)
		return false;
	for (int k = 0; k < 3; k++)
	{
		square[i + k][j] = insert;
	}
	square[i][j - p] = insert;
	square[i - 1][j - p] = insert;

}
bool insert_N_270(string*& square, int i, int j, bool turn, bool del)
{
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	char insert = 'N';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'N';
	}
	for (int k = 0; k < 3; k++)
	{
		if (square[i][j - k] != insert)
			return false;
	}
	if (square[i + p][j] != insert)
		return false;
	if (square[i + p][j - 1] != insert)
		return false;

	for (int k = 0; k < 3; k++)
	{
		square[i][j - k] = extract;
	}
	square[i - p][j] = extract;
	square[i - p][j + 1] = extract;
}

bool insert_P(string*& square, int i, int j, bool turn, bool del)
{
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	char insert = 'N';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'N';
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i][j + k] != extract)
			return false; 
	}
	if (square[i - 1][j] != extract)
		return false;
	if (square[i - 1][j + p] != extract)
		return false; 

	for (int k = -1; k < 2; k++)
	{
		square[i][j + k] = insert;
			
	}
	square[i- 1][j] = insert;
	square[i - 1][j + p] = insert;
}
bool insert_P_180(string*& square, int i, int j, bool turn, bool del)
{
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	char insert = 'N';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'N';
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i][j - k] != extract)
			return false;
	}
	if (square[i + 1 ][j] != extract)
		return false;
	if (square[i + 1 ][j - p] != extract)
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i][j - k] = insert;

	}
	square[i + 1 ][j] = insert;
	square[i + 1][j - p] = insert;
}
bool insert_P_90(string*& square, int i, int j, bool turn, bool del)
{
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	char insert = 'N';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'N';
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i + k][j] != extract)
			return false;
	}
	if (square[i-p][j + 1] != extract)
		return false; 
	if (square[i][j + 1] != extract)
		return false; 
	for (int k = -1; k < 2; k++)
	{
		square[i + k][j] = insert;
	}
	square[i - p][j + 1] = insert;
	square[i][j + 1] = insert;
}
bool insert_P_270(string*& square, int i, int j, bool turn, bool del)
{
	int p;
	if (turn == false)
		p = 1;
	else
		p = -1;
	char insert = 'N';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'N';
	}
	for (int k = -1; k < 2; k++)
	{
		if (square[i - k][j] != extract)
			return false;
	}
	if (square[i+p][j-1] != extract)
		return false;
	if (square[i][j - 1] != extract)
		return false;
	for (int k = -1; k < 2; k++)
	{
		square[i - k][j] = insert;
	}
	square[i + p][j - 1] = insert;
	square[i][j - 1] = insert;
}

bool insert_U(string*& square, int i, int j, bool turn, bool del)
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
	square[i-1][j + p] = insert;
	square[i + 1][j + p] = insert;

}
bool insert_U_90(string*& square, int i, int j, bool turn, bool del)
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
		if (square[i][j+k] != extract)
		{
			return false;
		}
	}
	if (square[i + p][j + 1] != extract)
		return false;
	if (square[i + p][j - 1] != extract)
		return false;
	square[i + p][j+1] = insert;
	square[i + p][j-1] = insert;
	for (int k = -1; k < 2; k++)
	{
		square[i][j + k] = insert;
	}

}

bool insert_T(string*& square, int i, int j, bool turn, bool del)
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

}
bool insert_T_90(string*& square, int i, int j, bool turn, bool del)
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

}

bool insert_V(string*& square, int i, int j, bool turn, bool del)
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

}
bool insert_V_90(string*& square, int i, int j, bool turn, bool del)
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

}

bool insert_Z(string*& square, int i, int j, bool turn, bool del)
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
	if (square[i][j - p] != extract)
		return false;
	if (square[i + 1][j + p] != extract)
		return false;

	for (int k = -1; k < 2; k++)
	{
		square[i + k][j] = insert;
	}
	square[i - 1][j - p] = insert;
	square[i + 1][j + p] = insert;

}
bool insert_Z_90(string*& square, int i, int j, bool turn, bool del)
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

}

bool insert_W(string *& square,  int i , int j , bool turn , bool del)
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
		if (square[i + k*p][j + k*p] != extract)
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
		square[i + k*p][j + k*p] = insert;
	}
}
bool insert_W_90(string*& square, int i, int j, bool turn, bool del)
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
}

bool insert_X(string*& square, int i, int j, bool turn, bool del) // i , j - координаты центра 
{
	char insert = 'X';
	char extract = '_';
	if (del == true)
	{
		insert = '_';
		extract = 'X';
	}
	for (int k = -1; k < 2;k++)
	{
		if (square[i][j+k] != insert)
		{
			return false; 
		}
	}
	for (int k = -1; k < 2;k++)
	{
		if (square[i+k][j] != insert)
		{
			return false;
		}
	}
	for (int k = -1; k < 2;k++)
	{
		square[i][j + k] = extract;
	}
	for (int k = -1; k < 2;k++)
	{
		square[i + k][j] = extract;
		
	}
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
	if(!check(square))
		return EXIT_FAILURE;
	insert_I(square, 1, 1, false, false);
	print(square);

	insert_I(square, 1, 1, false, true);
	print(square);
	insert_I(square, 1, 1, true, false);
	print(square);
	insert_I(square, 1, 1, true, true);
	print(square);
	return EXIT_SUCCESS;
	
}