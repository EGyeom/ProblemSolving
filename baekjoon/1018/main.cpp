#include <iostream>

int main()
{
	const int W = 1, B = 0;
	char arr[50][50];
	int check = 0;
	int N, M;
	std::cin >> N >> M;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			std::cin >> arr[i];
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[0][0] == 'W')
			{
				if ((i + j) % 2 == 0)
				{
					if (arr[i][j] == 'W') continue;
					else
					{
						check = 1;
						break;
					}

				}
				else
				{
					if (arr[i][j] == 'B') continue;
					else
					{
						check = 1;
						break;
					}
				}
			}
			else
			{
				if ((i + j) % 2 == 0)
				{
					if (arr[i][j] == 'B') continue;
					else
					{
						check = 1;
						break;
					}

				}
				else
				{
					if (arr[i][j] == 'W') continue;
					else
					{
						check = 1;
						break;
					}
				}
			}
		}
	}
	if (check == 0)
	{
		std::cout << 0 << std::endl;
	}

}