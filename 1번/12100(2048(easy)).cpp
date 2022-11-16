#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

// right, left, down, up
int dy[4]{0,0,1,-1};
int dx[4]{1,-1,0,0};

int N;
int init[20][20];

int maxVal = 0;

void MoveCell(int Dir, int y, int x, int(*board)[20], bool(*bCombined)[20])
{
	if (board[y][x] == 0) return;

	while (true)
	{
		int ny = y + dy[Dir];
		int nx = x + dx[Dir];

		if (ny < 0 || nx < 0 || ny >= N || nx >= N)
			return;

		if (board[ny][nx] == 0)
		{
			board[ny][nx] = board[y][x];
			board[y][x] = 0;
			y = ny;
			x = nx;
			continue;
		}

		if (board[ny][nx] == board[y][x])
		{
			if (bCombined[ny][nx]) 
				return;

			board[ny][nx] *= 2;
			board[y][x] = 0;
			bCombined[ny][nx] = true;
		}

		return;
	}
}

void print(const int(*preBoard)[20])
{
	cout << endl;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cout << preBoard[i][j] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void dfs(int depth, const int(*preBoard)[20])
{

	if (depth == 0)
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
				maxVal = max(maxVal, preBoard[i][j]);
		}
		return;
	}

	int board[20][20];
	bool bCombined[20][20];
	
	for (int Dir = 0; Dir < 4; ++Dir)
	{
		memcpy(board, preBoard, sizeof(board));
		memset(bCombined, false, sizeof(bCombined));

		if (Dir == 0) // right
		{
			for (int i = 0; i < N; ++i)
			{
				for (int j = N - 2; j >= 0 ; --j)
				{
					MoveCell(Dir, i, j, board, bCombined);
				}
			}

		}
		else if (Dir == 1) // left
		{
			for (int i = 0; i < N; ++i)
			{
				for (int j = 1; j < N ; ++j)
				{
					MoveCell(Dir, i, j, board, bCombined);
				}
			}
		}
		else if (Dir == 2) // down
		{
			for (int j = 0; j < N ; ++j)
			{
				for (int i = N - 2; i >= 0; --i)
				{
					MoveCell(Dir, i, j, board, bCombined);
				}
			}

		}
		else // up
		{
			for (int j = 0; j < N ; ++j)
			{
				for (int i = 1; i < N; ++i)
				{
					MoveCell(Dir, i, j, board, bCombined);
				}
			}

		}
		dfs(depth - 1, board);

	}
}

int main()
{
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			cin >> init[i][j];
		}
	}

	dfs(5, init);

	cout << maxVal << endl;

	return 0;
}