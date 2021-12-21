#include <psinclude.h>

std::vector<int> v_values(100000,0);

int BinarySearch(int left, int right, int key)
{
    while(left <= right)
    {
        int middle = (left+right)/2;
        
        if(v_values[middle] > key)
        {
            right = middle-1;
        }
        else if(v_values[middle] < key)
        {
            left = middle +1;
        }
        else
        {
            return 1;
        }
    }
    return 0;
}


int main()
{
    int n,m;
    scanf("%d", &n);
    for(int i =0; i < n; i++)
    {
        scanf("%d", &v_values[i]);
    }

    std::sort(v_values.begin(), v_values.begin() + n);

    scanf("%d", &m);
    for(int i = 0; i < m; i++)
    {
        int input;
        scanf("%d", &input);
        printf("%d\n", BinarySearch(0,n-1,input));
    }
}