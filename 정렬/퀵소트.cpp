#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

void swap(int* a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


void qsort(int left, int right, int* data)
{
	int pivot = left;
	int j = pivot;
	int i = left + 1;

	if (left < right)
	{
		for (; i <= right; ++i)
		{
			if (data[i] < data[pivot])
			{
				++j;
				swap(&data[j], &data[i]);
			}
		}

		swap(&data[left], &data[j]);
		pivot = j;

		qsort(left, pivot - 1, data);
		qsort(pivot + 1, right, data);
	}
	
}

int main()
{
	int arr[10]{ 1,-4,10,3,8,9,11,20, 2,22  };

	qsort(0, 9, arr);

	for (auto& e : arr)
		cout << e << endl;

	return 0;
}