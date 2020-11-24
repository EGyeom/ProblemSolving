#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

typedef struct _STACK
{
	int arr[100000] = { 0, };
	int top = 0;
} stack;

typedef _STACK* pst;

void push(int num, pst st)
{
	st->arr[st->top] = num;
	(st->top)++;
}

int pop(pst st)
{
	if (st->top == 0) return -1;
	return st->arr[--(st->top)];
}

int topNum(pst st)
{
	if (st->top == 0) return -1;
	return st->arr[(st->top)-1];
}

int empty(pst st)
{
	if (st->top == 0) return 1;
	else return 0;

}

int size(pst st)
{
	return st->top;
}

int main()
{
	int n;
	stack st;
	scanf("%d" ,&n);
	fgetc(stdin);

	for (int i = 0; i < n; i++)
	{
		char str[10] = { 0, };
		scanf("%s", str);
		fgetc(stdin);
		if (!strcmp(str, "push"))
		{
			int num;
			scanf("%d", &num);
			push(num, &st);
		}
		else if (!strcmp(str, "pop"))
		{
			printf("%d\n", pop(&st));
		}
		else if (!strcmp(str, "top"))
		{
			printf("%d\n",topNum(&st));
		}
		else if (!strcmp(str, "empty"))
		{
			printf("%d\n",empty(&st));
		}
		else if (!strcmp(str, "size"))
		{
			printf("%d\n",size(&st));
		}

	}
}
/*
int arr[100000];
int top = 0;

int topNum()
{
	if (top == 0) return -1;
	return arr[top-1];
}

int size()
{
	return top;
}

int isEmpty()
{
	if (top == 0)
	{
		return 1;
	}
	else return 0;
}

int pop()
{
	if (top == 0) return -1;
	return arr[--top];
}

void push(int n)
{
	arr[top] = n;
	top++;
}

int main()
{
	int num;
	std::cin >> num;
	std::cin.ignore();
	char str[10];
	for (int i = 0; i < num; i++)
	{
		std::cin.getline(str, sizeof(str));
		int len = strlen(str);
		if (str[0] == 'p' && len >= 6)
		{
			push(atoi(const_cast<const char*>(&str[5])));
		}
		if (str[0] == 's')
		{
			std::cout << size() << "\n";
		}
		if (str[0] == 'p' && len == 3)
		{
			std::cout << pop() << "\n";
		}
		if (str[0] == 'e')
		{
			std::cout << isEmpty() << "\n";
		}
		if (str[0] == 't')
		{
			std::cout << topNum() << "\n";
		}
	}


}
*/