#include <iostream>

int main()
{
	int K;
	int num;
	int top = -1;
	std::cin >> K;
	int* arr = new int[K];
	for (int i = 0; i < K; i++)
	{
		std::cin >> num;
		if (num == 0)
		{
			--top;
		}
		else
		{
			++top;
			arr[top] = num;
		}
	}

	int result = 0;
	
	for (int i = 0; i <= top; i++)
	{
		result += arr[i];
	}

	std::cout << result;

}