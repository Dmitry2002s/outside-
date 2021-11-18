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

bool insert_I_0(string*& square, int i , int j) // i - Строка , j - столбец 
{
	for (int k = 0; k < 5; k++)
	{
		if (square[i+k][j] != '_')
		{
			return false; 
		}
	}
	for (int k = 0; k < 5; k++)
	{
		square[i+k][j] = 'I';
	}
}
bool  extract_I_0(string* square, int i, int j)
{
	for (int k = 0; k < 5; k++)
	{
		if (square[i + k][j] != 'I')
		{
			return false;
		}
	}
	for (int k = 0; k < 5; k++)
	{
		square[i + k][j] = '_';
	}
}
bool insert_I_90(string* square, int i, int j)
{

	for (int k = 0; k < 5; k++)
	{
		if (square[i][j+k] != '_')
		{
			return false;
		}
	}
	for (int k = 0; k < 5; k++)
	{
		square[i][j + k] = 'I';
	}
}
bool extract_I_90(string* square, int i, int j)
{
	for (int k = 0; k < 5; k++)
	{
		if (square[i][j + k] != 'I')
		{
			return false;
		}
	}
	for (int k = 0; k < 5; k++)
	{
		square[i][j + k] = '_';
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

bool insert_X(string*& square, int i, int j) // i , j - координаты центра 
{
	for (int k = -1; k < 2;k++)
	{
		if (square[i][j+k] != '_')
		{
			return false; 
		}
	}
	for (int k = -1; k < 2;k++)
	{
		if (square[i+k][j] != '_')
		{
			return false;
		}
	}
	for (int k = -1; k < 2;k++)
	{
		square[i][j + k] = 'X';
	}
	for (int k = -1; k < 2;k++)
	{
		square[i + k][j] = 'X';
		
	}
}
bool extract_X(string*& square, int i, int j)
{
	for (int k = -1; k < 2;k++)
	{
		if (square[i][j + k] != 'X')
		{
			return false;
		}
	}
	for (int k = -1; k < 2;k++)
	{
		if (square[i + k][j] != 'X')
		{
			return false;
		}
	}
	for (int k = -1; k < 2;k++)
	{
		square[i][j + k] = '_';
	}
	for (int k = -1; k < 2;k++)
	{
		square[i + k][j] = '_';

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
	insert_I_0(square, 1, 1);
	print(square);
	extract_I_0(square, 1, 1);
	insert_I_90(square, 1, 1);
	print(square);
	insert_X(square, 3, 3);
	print(square);
	extract_X(square, 3, 3);
	print(square);
	insert_Y(square, 6, 3);

	print(square);
	return EXIT_SUCCESS;
	
}