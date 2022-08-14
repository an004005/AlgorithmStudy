#include <iostream>
using namespace std;

class PriorityQ
{
public:
	void push(int i)
	{
		q[size++ + 1] = i;
		heapify_Up();
		print();
	}

	int pop()
	{
		swap(q[1], q[size]);
		int poped = q[size];
		q[size] = 0;
		--size;
		heapify_Down();
		print();
		return poped;
	}

	void print()
	{
		for (int i = 1; i <= size; ++i)
		{
			cout << q[i] << " ";
		}
		cout << endl;
	}

private:
	void heapify_Up()
	{
		int curIndex = size;

		while (curIndex != 1) // not root
		{
			int parentIndex = curIndex / 2;
			if (q[parentIndex] < q[curIndex])
			{
				swap(q[parentIndex], q[curIndex]);
				curIndex = parentIndex;
			}
			else
				break;
		}
	}

	void heapify_Down()
	{
		int curIndex = 1;
		while (true)
		{
			int leftChildIndex = curIndex * 2;
			if (leftChildIndex > size)
				break;

			if (q[leftChildIndex] > q[curIndex])
			{
				swap(q[leftChildIndex], q[curIndex]);
				curIndex = leftChildIndex;
				continue;
			}

			int rightChildIndex = leftChildIndex + 1;
			if (rightChildIndex > size)
				break;

			if (q[rightChildIndex] > q[curIndex])
			{
				swap(q[rightChildIndex], q[curIndex]);
				curIndex = rightChildIndex;
				continue;
			}
			break;
		}
	}

private:
	int q[100];
	int size = 0;
};

int main()
{
	PriorityQ q;

	q.push(1);
	q.push(5);
	q.push(9);
	q.push(2);
	q.push(13);
	q.push(3);

	q.pop();
	q.pop();


	return 0;
}