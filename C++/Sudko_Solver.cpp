#include <iostream>
#include <cmath>
using namespace std;

bool canPlace(int mat[][100], int i, int j, int n, int number)
{
	// check for row and column
	for (int x = 0 ; x < n ; x++)
	{
		if (mat[x][j] == number || mat[i][x] == number)
			return false;
	}
	// check for subgrid
	int rn = sqrt(n);
	int sx = (i / rn) * rn;
	int sy = (j / rn) * rn;

	for (int x = sx ; x < sx + rn ; x++)
	{
		for (int y = sy; y < sy + rn ; y++)
		{
			if (mat[x][y] == number)	return false;
		}
	}
	return true;



}

bool SudokoSolver(int mat[][100], int i, int j, int n)
{

	// base case
	if (i == n)
	{
		// print the matrix

		for (int i = 0 ; i < n ; i++)
		{
			for (int j = 0 ; j < n ; j++)
				cout << mat[i][j] << " ";
			cout << endl;
		}

		return true;
	}
	// if a row end
	if (j == n)
	{
		return SudokoSolver(mat, i + 1, 0, n);
	}
	// skip the prefilled cells
	if (mat[i][j] != 0)
		return SudokoSolver(mat, i, j + 1, n);

	// rec case
	//Fill the current cell with possible options
	for (int number = 1 ; number <= 9 ; number++ )
	{
		if (canPlace(mat, i, j, n, number))
		{
			// assume current number is right number
			mat[i][j] = number;
			bool ifcomplete = SudokoSolver(mat, i, j + 1, n);
			if (ifcomplete)
				return true;


		}
	}
	// backtrack here
	mat[i][j] = 0;
	return false;


}

int main()
{
	int n;
	cin >> n;
	int mat[100][100];
	for (int i = 0 ; i < n ; i++)
	{
		for (int j = 0 ; j < n ; j++)	cin >> mat[i][j];
	}
	SudokoSolver(mat, 0, 0, n);
}
