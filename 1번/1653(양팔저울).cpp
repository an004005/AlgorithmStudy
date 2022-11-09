#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

int n;
bool w[10]{};
bool LeftW[10]{};
int k;

vector<int> vecEqNum;
vector<pair<int, int>> vecPosW; // left, right weight

bool checkCanMake(int weights)
{
	bool tmpW[10];
	memcpy(tmpW, w, sizeof (w));

	string tmp = to_string(weights);
	for (char& c : tmp)
	{
		if (tmpW[(c - '0')] == false)
			return false;

		tmpW[(c - '0')] = false;
	}

	memcpy(LeftW, w, sizeof(w));
	for (char& c : tmp)
		LeftW[(c - '0')] = false;

	return true;
}

bool checkCanMakeRight(int weights)
{
	string tmp = to_string(weights);
	for (char& c : tmp)
	{
		if (LeftW[(c - '0')] == false)
			return false;
	}
	return true;
}

int main()
{
	vecEqNum.push_back(0);
	vecPosW.resize(98766, {-1, -1});

	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		int num;
		cin >> num;
		w[num] = true;
	}
	cin >> k;

	for (size_t i = 1; i < vecPosW.size(); ++i)
	{
		if (checkCanMake((int)i) == false) continue;
		pair<int, int>& lr_W = vecPosW[i];

		string tmp = to_string(i);

		for (size_t j = 0; j < tmp.size(); ++j)
			lr_W.first += (tmp.size() - j) * (tmp[j] - '0');
		for (size_t j = 0; j < tmp.size(); ++j)
			lr_W.second += (j + 1) * (tmp[j] - '0');
	}

	for (size_t i = 1; i < vecPosW.size(); ++i) // left
	{
		if (vecPosW[i].first == -1) continue;
		if (checkCanMake((int)i) == false) continue;

		for (size_t j = 1; j < vecPosW.size(); ++j) // right
		{
			if (vecPosW[j].second == -1) continue;
			if (checkCanMakeRight((int)j) == false) continue;

			if (vecPosW[i].first == vecPosW[j].second)
			{
				vecEqNum.push_back(i * 100'000 + j);
			}
		}
	}

	sort(vecEqNum.begin(), vecEqNum.end());

	if (vecEqNum.size() <= k)
		cout << vecEqNum.back() << endl;
	else
		cout << vecEqNum[k] << endl;

	return 0;
}