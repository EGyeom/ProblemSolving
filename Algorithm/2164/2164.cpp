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
	int n, k, count = 0;
	std::cin >> n >> k;
	int index = k - 1;
	int check[1001] = { 0, };
	int arr[1001] = { 0, };
	int qsize = n;
	for (int i = 0; i < n; i++)
	{
		push(i + 1);
	}
	while (1)
	{
		if (size() == 1)
		{
			printf("%d", q.arr[q.front]);
			break;
		}
		pop();
		push(q.arr[q.front]);
		pop();
	}
}
