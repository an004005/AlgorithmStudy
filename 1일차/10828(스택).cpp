#include<iostream>
#include <string>
using namespace std;

struct Node
{
	int v;
	Node* next = nullptr;
	Node* prev = nullptr;
	Node() {}
	Node(int _v) : v(_v) {}
};

class stack
{
public:
	stack() : head(nullptr), tail(nullptr) {}
	~stack() {}

public:
	void push(int v)
	{
		Node* node = new Node(v);

		if (empty() == 1)
		{
			head = node;
			head->next = tail;
			tail = node;
			tail->prev = head;
		}
		else
		{
			tail->next = node;
			node->prev = tail;
			tail = node;
		}
		++isize;
	}

	int pop()
	{
		if (empty() == 1)
		{
			return -1;
		}
		else
		{
			--isize;
			if (head == tail) // last one
			{
				int ret = tail->v;
				delete tail;
				tail = nullptr;
				head = nullptr;

				return ret;
			}
			else
			{
				Node* pop = tail;
				int ret = pop->v;
				tail = pop->prev;
				tail->next = nullptr;
				delete pop;

				return ret;
			}
		}
	}

	int empty()
	{
		if (head == nullptr && tail == nullptr) // empty
			return 1;
		else 
			return 0;
	}

	int top()
	{
		if (empty() == 1)
			return -1;
		else
		{
			return tail->v;
		}
	}

	int size()
	{
		return isize;
	}

private:
	Node* head;
	Node* tail;
	int isize = 0;
};


int N;

int main()
{
	cin >> N;

	stack s;

	for (int i = 0; i < N; ++i)
	{
		string command;
		cin >> command;
		//scanf("%s", &command);

		if (command == "top")
		{
			printf("%d\n", s.top());
		}
		else if (command == "pop")
		{
			printf("%d\n", s.pop());
		}
		else if (command == "size")
		{
			printf("%d\n", s.size());
		}
		else if (command == "empty")
		{
			printf("%d\n", s.empty());
		}
		else // push
		{
			int v;
			scanf_s("%d", &v);
			s.push(v);

		}
		

	}
	return 0;
}