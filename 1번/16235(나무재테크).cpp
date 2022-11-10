#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
using namespace std;

int dy[8]{0,0,1,-1, 1,1,-1,-1};
int dx[8]{1,-1,0,0, 1,-1,1,-1};

using Tree = pair<unsigned int, bool>; // age, dead

struct Land
{
	vector<unsigned int> Trees;
	unsigned int power = 5;
};

int N, M, K;
int A[10][10]{};
Land Lands[10][10];

void springSummer()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (Lands[i][j].Trees.empty()) continue;

			vector<unsigned int> tmp;
			unsigned int diePower = 0;

			for (int k = (int)Lands[i][j].Trees.size() - 1; k >= 0; --k)
			{
				if (Lands[i][j].Trees[k] <= Lands[i][j].power)
				{
					Lands[i][j].power -= Lands[i][j].Trees[k];
					tmp.push_back(Lands[i][j].Trees[k] + 1);
				}
				else
				{
					diePower += (Lands[i][j].Trees[k] / 2);
				}
			}

			Lands[i][j].Trees.clear();
			for (int k = tmp.size() - 1; k >= 0 ; --k)
			{
				Lands[i][j].Trees.push_back(tmp[k]);
			}
			Lands[i][j].power += diePower;
		}
	}
}


void fallWinter()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			for (auto& tree : Lands[i][j].Trees)
			{
				if (tree % 5 == 0)
				{
					for (int k = 0; k < 8; ++k)
					{
						int ni = i + dy[k];
						int nj = j + dx[k];

						if (ni < 0 || nj < 0 || ni >= N || nj >= N)
							continue;

						Lands[ni][nj].Trees.push_back(1);
					}
				}
			}

			Lands[i][j].power += A[i][j];
		}
	}
}



int main()
{
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
			scanf("%d", &A[i][j]);
	}

	int x, y, z;
	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d %d", &x, &y, &z);
		Lands[x - 1][y - 1].Trees.push_back(z);
	}

	while (K--)
	{
		springSummer();
		fallWinter();
	}

	size_t lives = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			lives += Lands[i][j].Trees.size();
		}
	}
	printf("%d\n", lives);

	return 0;
}


// 아래 실패 코드 : for문 돌면서 하나씩 지우는게 오히려 느린것 같다.
// 소팅을 계속하는거도 실패 이유였음(소팅 안해도 가능한데)

// #define _CRT_SECURE_NO_WARNINGS
// #include <iostream>
// #include <vector>
// #include <algorithm>
// #include <list>
// using namespace std;
//
// int dy[8]{0,0,1,-1, 1,1,-1,-1};
// int dx[8]{1,-1,0,0, 1,-1,1,-1};
//
// using Tree = pair<unsigned int, bool>; // age, dead
//
// struct Land
// {
// 	vector<Tree> Trees;
// 	unsigned int power = 5;
// };
//
// int N, M, K;
// int A[10][10]{};
// Land Lands[10][10];
//
// void spring()
// {
// 	for (int i = 0; i < N; ++i)
// 	{
// 		for (int j = 0; j < N; ++j)
// 		{
// 			for (int k = (int)Lands[i][j].Trees.size() - 1; k >= 0; --k)
// 			{
// 				if (Lands[i][j].Trees[k].first <= Lands[i][j].power)
// 				{
// 					Lands[i][j].power -= Lands[i][j].Trees[k].first;
// 					++Lands[i][j].Trees[k].first;
// 				}
// 				else
// 				{
// 					Lands[i][j].Trees[k].second = true;
// 				}
// 				
// 			}
// 		}
// 	}
// }
//
// void summer()
// {
// 	for (int i = 0; i < N; ++i)
// 	{
// 		for (int j = 0; j < N; ++j)
// 		{
// 			Land& land = Lands[i][j];
//
// 			for (auto itr = land.Trees.begin(); itr != land.Trees.end();)
// 			{
// 				if (itr->second)
// 				{
// 					land.power += itr->first / 2;
// 					itr = land.Trees.erase(itr);
// 				}
// 				else
// 					++itr;
// 			}
// 		}
// 	}
// }
//
// void fallWinter()
// {
// 	for (int i = 0; i < N; ++i)
// 	{
// 		for (int j = 0; j < N; ++j)
// 		{
// 			for (auto& tree : Lands[i][j].Trees)
// 			{
// 				if (tree.first % 5 == 0)
// 				{
// 					for (int k = 0; k < 8; ++k)
// 					{
// 						int ni = i + dy[k];
// 						int nj = j + dx[k];
//
// 						if (ni < 0 || nj < 0 || ni >= N || nj >= N)
// 							continue;
//
// 						Lands[ni][nj].Trees.push_back({1, false});
// 					}
// 				}
// 			}
//
// 			Lands[i][j].power += A[i][j];
// 		}
// 	}
// }
//
//
//
// int main()
// {
// 	scanf("%d %d %d", &N, &M, &K);
// 	for (int i = 0; i < N; ++i)
// 	{
// 		for (int j = 0; j < N; ++j)
// 			scanf("%d", &A[i][j]);
// 	}
//
// 	int x, y, z;
// 	for (int i = 0; i < M; ++i)
// 	{
// 		scanf("%d %d %d", &x, &y, &z);
// 		Lands[x - 1][y - 1].Trees.push_back({z, false});
// 	}
//
// 	while (K--)
// 	{
// 		spring();
// 		summer();
// 		fallWinter();
// 	}
//
// 	size_t lives = 0;
// 	for (int i = 0; i < N; ++i)
// 	{
// 		for (int j = 0; j < N; ++j)
// 		{
// 			lives += Lands[i][j].Trees.size();
// 		}
// 	}
// 	printf("%d\n", lives);
//
// 	return 0;
// }