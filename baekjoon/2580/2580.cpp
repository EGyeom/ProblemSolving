#include <bits/stdc++.h>
using namespace std;

int sdoku[9][9];
int checkCount;
void print_sdoku()
{
    printf("\n");

    for(int i =0; i <9; i++)
    {
        for(int j =0; j < 9; j++)
        {
            printf("%d ", sdoku[i][j]);
        }
        printf("\n");
    }
}

bool check(int y, int x)
{
    checkCount++;
    for(int i = 0; i < 9; i++)
    {
        if(i != y && sdoku[i][x] == sdoku[y][x]) return false;
        if(i != x && sdoku[y][i] == sdoku[y][x]) return false;
    }
    int y3 = y/3;
    int x3 = x/3;
    for(int i =y3; i < y3+3; i++)
    {
        for(int j = x3; j < x3+3; j++)
        {
            if(i != y && j != x && sdoku[i][j] == sdoku[y][x]) return false;
        }
    }
    checkCount = 0;
    return true;
}

int findZero(int y)
{
    for(int j =0; j < 9; j++)
    {
        if(sdoku[y][j] == 0) return j;
    }
    return -1;
}

void traverse(int y, int x)
{
    while(findZero(y) = -1)
    for(int j = 1; j <= 9; j++)
    {

    }

}


int main()
{
    for(int i =0; i <9; i++)
    {
        for(int j =0; j < 9; j++)
        {
            scanf("%d",&sdoku[i][j]);
        }
    }
    traverse(0,0);
    printf("\n");
    print_sdoku();

}