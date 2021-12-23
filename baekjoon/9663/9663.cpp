#include <psinclude.h>
#include <unistd.h>

int count = 0;
int blockCount = 0;
int result = 0;
int n;
int **map;

void blocking(int y, int x)
{
    map[y][x] += 1;
    for(int i =1; i < n; i++)
    {
        int left_dx = x-i;
        int right_dx = x+i;
        int up_dy = y-i;
        int down_dy = y+i;
        if(left_dx >= 0)
        {
            map[y][left_dx] += 1;
        }
        if(right_dx < n)
        {
            map[y][right_dx] += 1;
        }
        if(up_dy >= 0)
        {
            map[up_dy][x] +=1;
        }
        if(down_dy < n)
        {
            map[down_dy][x] +=1;
        }

        if(left_dx >= 0 && up_dy >= 0)
        {
            map[up_dy][left_dx] += 1;
        }
        if(left_dx >= 0 && down_dy < n)
        {
            map[down_dy][left_dx] += 1;
        }
        if(right_dx < n && up_dy >= 0)
        {
            map[up_dy][right_dx] += 1;
        }
        if(right_dx < n && down_dy < n)
        {
            map[down_dy][right_dx] += 1;
        }
    }

}

void unBlocking(int y, int x)
{
    map[y][x] -= 1;
    for(int i =1; i < n; i++)
    {
        int left_dx = x-i;
        int right_dx = x+i;
        int up_dy = y-i;
        int down_dy = y+i;
        if(left_dx >= 0)
        {
            map[y][left_dx] -= 1;
        }
        if(right_dx < n)
        {
            map[y][right_dx] -= 1;
        }
        if(up_dy >= 0)
        {
            map[up_dy][x] -=1;
        }
        if(down_dy < n)
        {
            map[down_dy][x] -=1;
        }

        if(left_dx >= 0 && up_dy >= 0)
        {
            map[up_dy][left_dx] -= 1;
        }
        if(left_dx >= 0 && down_dy < n)
        {
            map[down_dy][left_dx] -= 1;
        }
        if(right_dx < n && up_dy >= 0)
        {
            map[up_dy][right_dx] -= 1;
        }
        if(right_dx < n && down_dy < n)
        {
            map[down_dy][right_dx] -= 1;
        }
    }

}

void traversal(int y)
{   
    if(n-y < n-count) return;
    if(count == n)
    {
        result++;
        return;
    }
    for(int i =0; i <n; i++)
    {
        if(map[y][i] == 0)
        {
            count++;
            blocking(y,i);
            traversal(y+1);
            unBlocking(y,i);
            count--;
        }
    }
}

int main()
{
    scanf("%d", &n);
    map = new int*[n];
    for(int i =0; i < n; i++)
    {
        map[i] = new int[n];
    }

    traversal(0);
    printf("%d\n", result);
}





// #include <psinclude.h>
// int n;
// int map[15][15];
// int count = 0;
// int result = 0;

// bool checker(int y, int x)
// {
//     for(int i =0; i < n; i++)
//     {
//         if(map[i][x] == 1 || map[y][i] == 1) return false;
//         if(y - i >= 0 && x - i >= 0 && map[y-i][x-i] == 1) return false;
//         if(y - i >= 0 && x + i < n && map[y-i][x+i] == 1) return false;
//     }
//     return true;
// }

// void nQueen(int y)
// {
//     if(n == count)
//     {
//         result++;
//         return;
//     }
//     for(int i = 0; i < n; i++)
//     {
//         if(map[y][i] == 0)
//         {
//             if(checker(y,i))
//             {
//                 count++;
//                 map[y][i] = 1;
//                 nQueen(y+1);
//                 map[y][i] = 0;
//                 count--;
//             } 
//         }
//     }
// }

// int main()
// {
//     scanf("%d", &n);
//     nQueen(0);

//     printf("%d\n", result);
// }



















