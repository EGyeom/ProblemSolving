#include <iostream>
int arr[10001];

void D(int num)
{
	if (num > 10000)
	{
		return;
	}
	if (arr[num] == true)
	{
		int temp = num;
		int next = 0;
		while (temp)
		{
			next += temp % 10;
			temp /= 10;
		}
		D(num + next);
		arr[num + next] = 0;
	}
}


int main()
{
	for (int i = 0; i <= 10000; i++)
	{
		arr[i] = 1;
	}
	for(int i =1; i<= 10000; i++)
	{
		D(i);
	}

	for (int i = 1; i <= 10000; i++)
	{
		if (arr[i] == true)
		{
			std::cout << i << std::endl;
		}
	}

}