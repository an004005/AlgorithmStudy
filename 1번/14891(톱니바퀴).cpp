#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <math.h>
using namespace std;


// ȸ���� ���� ���� ��� ȸ������ �ʰ� �ٸ� ���̸� �ݴ�������� ȸ���Ѵ�.
struct Gear
{
	Gear(){}
	Gear(string gearState)
	{
		gear = 0;
		for (unsigned int i = 0; i < gearState.size(); ++i)
		{
			if (gearState[i] == '1') // s��
				gear |= 1 << (7 - i);
		}
	}

	void Rotate(int rot) // 1 : �ð�, -1 �ݽð�
	{
		if (rot == 1)
		{
			bool bLastS = gear & 1;
			gear >>= 1;
			if (bLastS) gear |= 1 << 7;
		}
		else
		{
			bool bFirstS = gear & 1 << 7;
			gear <<= 1;
			if (bFirstS) gear |= 1;
		}
	}

	unsigned char gear;
};

array<Gear, 4> Gears{};
int K;

unsigned char GearLeftMask = 1 << 1;
unsigned char GearRightMask = 1 << 5;

void RotateGearAt(int from, int gearNum, int rot)
{
	bool bRightMove = false;
	bool bLeftMove = false;

	if (gearNum + 1 != from && gearNum + 1 < 4) // ������ ����
	{
		bRightMove = static_cast<bool>(Gears[gearNum].gear & GearRightMask) !=  static_cast<bool>(Gears[gearNum + 1].gear & GearLeftMask);
	}

	if (gearNum - 1 != from && gearNum - 1 >= 0) // ���� ����
	{
		bLeftMove = static_cast<bool>(Gears[gearNum].gear & GearLeftMask) != static_cast<bool>(Gears[gearNum - 1].gear & GearRightMask);
	}

	Gears[gearNum].Rotate(rot);

	if (bRightMove)
		RotateGearAt(gearNum, gearNum + 1, -rot);
	if (bLeftMove)
		RotateGearAt(gearNum, gearNum - 1, -rot);
}

int main()
{
	string gearState;
	for (int i = 0; i < 4; ++i)
	{
		cin >> gearState;
		Gears[i] = Gear{gearState};
	}

	cin >> K;

	while (K--)
	{
		int gearNum, Rot;
		cin >> gearNum >> Rot;
		gearNum -= 1; // 1~4 => 0~3
		RotateGearAt(-10, gearNum, Rot);
	}

	int sum = 0;
	for (int i = 0; i < 4; ++i)
	{
		if (Gears[i].gear & 1 << 7)
		{
			sum += static_cast<int>(pow(2, i));
		}
	}

	cout << sum << endl;

	return 0;
}