#include <iostream>

int main()
{
	int N, K;
	int top = 0;
	int count = 0;
	int arr[10] = { 0, };
	std::cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
	}
	
	top = (N - 1);
	int temp = K;
	while (1)
	{
		if (temp <= arr[top])
		{
			if (temp == arr[top])
			{
				count += 1;
				std::cout << count;
				break;
			}
			top--;
			continue;
		}
		if ((temp / arr[top]) >= 1)
		{
			count += (temp / arr[top]);
			temp -= arr[top] * (temp/arr[top]);
			if (temp == 0)
			{
				std::cout << count;
				break;
			}
		}
		else top--;

	}


}