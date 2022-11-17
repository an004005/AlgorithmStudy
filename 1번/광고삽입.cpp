#include <string>
#include <vector>
#include <algorithm>
using namespace std;

unsigned long long  Timeline[360000]{};

int str2sec(const string& str) // "00:00:00" -> sec
{
	int hour = stoi(str.substr(0, 2));
	int min = stoi(str.substr(3, 2));
	int sec = stoi(str.substr(6, 2));
	return hour * 3600 + min * 60 + sec;
}

string sec2str(int sec)
{
	int hour = sec / 3600;
	sec %= 3600;
	int min = sec / 60;
	sec%=60;

	char tmp[256];
	sprintf_s(tmp, "%02d:%02d:%02d", hour, min, sec);
	
	return tmp;
}

string solution(string play_time, string adv_time, vector<string> logs) {

	int TimelineLen = str2sec(play_time);

	for (auto& log : logs)
	{
		int from = str2sec(log.substr(0, 8));
		int to = str2sec(log.substr(9, 8));

		for (int i = from; i < to; ++i) // [] 구간이 아니라 [) 구간 이었습니다..... 문제를 잘 읽자
			++Timeline[i];
	}


	unsigned long long  maxTime = 0;
	int maxTimeStart = 0;

	unsigned long long  sumTime = 0;
	int end = 0;
	int advLen = str2sec(adv_time);

	for (; end < advLen ; ++end)
		sumTime += Timeline[end];

	// end == advLen;

	maxTime = sumTime;

	for (; end < TimelineLen; ++end)
	{
		sumTime += Timeline[end];
		sumTime -= Timeline[end - advLen];

		if (sumTime > maxTime)
		{
			maxTime = sumTime;
			maxTimeStart = end - advLen + 1;
		}
	}


    return sec2str(maxTimeStart);
}
#include <iostream>
int main()
{
	solution("02:03:55", "00:14:15", {"01:20:15-01:45:14", "00:40:31-01:00:00", "00:25:50-00:48:29", "01:30:59-01:53:29", "01:37:44-02:02:30"});
	// solution("99:59:59", "25:00:00", {"69:59:59-89:59:59", "01:00:00-21:00:00", "79:59:59-99:59:59", "11:00:00-31:00:00"});



	return 0;
}