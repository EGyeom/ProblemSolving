#include <iostream>
#include <cstdio>
using namespace std;
template <typename T>
void printArray(T arr, int size)
{
    for(int i =0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}