#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

struct Student
{
	int korean;
	int english;
	int math;
	string name;
};

vector<Student> students;

int N;


int main()
{
	cin >> N;
	Student st;
	students.reserve(N);
	char tmp[20];
	for (int i = 0; i < N; ++i)
	{
		scanf("%s %d %d %d", tmp, &st.korean, &st.english, &st.math);
		st.name = tmp;
		students.push_back(st);
	}

	std::sort(students.begin(), students.end(), [](const Student& st1, const Student& st2)
	{
		if (st1.korean > st2.korean) 
			return true;
		
		if (st1.korean == st2.korean)
		{
			if (st1.english < st2.english)
				return true;
		
			if (st1.english == st2.english)
			{
				if (st1.math > st2.math)
					return true;
		
				if (st1.math == st2.math)
				{
					if (st1.name < st2.name)
						return true;
				}
			}
		}
		
		return false;
	});
	// std::sort(students.begin(), students.end(), [](const Student& st1, const Student& st2)
	// {
	// 	if (st1.korean == st2.korean)
	// 	{
	// 		
	// 	}
	// });


	for (auto& e : students)
		printf("%s\n", e.name.c_str());


	return 0;
}