#include <iostream>
#include <algorithm>
int main()
{
	int  N;
	int average=0, middle, max=-4001, min=4001, range;
	int countMax = 0;
	std::cin >> N;
	int* arr = new int[N];
	int count[500001] = { 0, };
	for (int i = 0; i < N; i++)
	{
		std::cin >> arr[i];
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
	}
	for (int i = 0; i < N; i++)
	{
		average += arr[i];
	}
	std::sort(arr,arr+N);
	if (N == 1)
	{
		middle = average = arr[0];
	}
	else
	{
		middle = arr[((N - 1) / 2)];
		if (average < 0)	average = (average - 1) / N;
		else if (average > 0)	average = (average + 1) / N;
		else average = 0;
	}
	range = max - min;
	std::cout << average << "\n";
	std::cout << middle <<"\n";
	std::cout << range <<"\n";


}