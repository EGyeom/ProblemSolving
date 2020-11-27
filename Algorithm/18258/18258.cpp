#include <iostream>
#include <string.h>
typedef struct Queue {
	int arr[1000000] = { 0, };
	int front = 0;
	int back = 0;
}queue;
queue q;

void push(int n)
{
	q.arr[q.back++] = n;
}

int empty()
{
	if (q.back == q.front) return 1;
	else return 0;
}

int pop()
{
	if (empty())
	{
		return -1;
	}
	else return q.arr[q.front++];
}



int size()
{
	return q.back - q.front;
}



int front()
{
	if (empty())
	{
		return -1;
	}
	else return q.arr[q.front];
}

int back()
{
	if (empty())
	{
		return -1;
	}
	else return q.arr[q.back - 1];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);
	int n;
	char str[20] = { 0, };
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		std::cin >> str;
		if (!strcmp(str, "push"))
		{
			int num = 0;
			std::cin >> num;
			push(num);
		}
		else if (!strcmp(str, "pop"))
		{
			std::cout << pop() << "\n";
		}
		else if (!strcmp(str, "size"))
		{
			std::cout << size() << "\n";
		}
		else if (!strcmp(str, "empty"))
		{
			std::cout << empty() << "\n";
		}
		else if (!strcmp(str, "front"))
		{
			std::cout << front() << "\n";
		}
		else if (!strcmp(str, "back"))
		{
			std::cout << back() << "\n";
		}
	}
}
