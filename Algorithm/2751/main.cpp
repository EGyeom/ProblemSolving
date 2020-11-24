#include <iostream>
int main()
{

	int num = 0;
	std::cin >> num;
	int L = 0, R = num-1;
	int pivot;
	int check = 0;
	int* arr = new int[num];
	for (int i = 0; i < num; i++)
	{
		std::cin >> arr[i];
	}
	
	pivot = arr[L];

	while (1)
	{
		if (L == R)
		{
			arr[L] = pivot;
			R = L;
			L = 0;
		}
		if (check == 0)
		{
			if (pivot > arr[R])
			{
				arr[L] = arr[R];
				check = 1;
			}
			else R--;
		}
		else
		{
			if (pivot > arr[R])
			{
				arr[L] = arr[R];
				check = 0;
			}
			else L++;
		}
	}



	for (int i = 0; i < num; i++)
	{
		std::cout << arr[i] << "\n";
	}

}