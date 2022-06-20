#include <bits/stdc++.h>
using namespace std;

int sdoku[9][9];
int checkCount;
bool isFind = false;
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
    for(int i = 0; i < 9; i++)
    {
        if(i != y && sdoku[i][x] == sdoku[y][x]) return false;
        if(i != x && sdoku[y][i] == sdoku[y][x]) return false;
    }
    int y3 = y/3;
    int x3 = x/3;
    for(int i =y3*3; i < y3*3+3; i++)
    {
        for(int j = x3*3; j < x3*3+3; j++)
        {
            if(i != y && j != x && sdoku[i][j] == sdoku[y][x]) return false;
        }
    }
    return true;
}


void traverse(int y, int x)
{
    int zero_y = y;
    int zero_x = x;
    while(sdoku[zero_y][zero_x] != 0)
    {
        zero_x++;
        if(zero_x == 9)
        {
            zero_x = 0;
            zero_y++;
            if(zero_y == 9) 
            {
                isFind =true;
                return;
            }
        }
    }
    printf("%d %d\n", zero_y, zero_x);
    for(int i = 1; i <= 9; i++)
    {
        sdoku[zero_y][zero_x] = i;
        if(check(zero_y,zero_x))
        {
            print_sdoku();
            traverse(zero_y,zero_x);
            if(isFind == true) return;
        }
    }
    sdoku[zero_y][zero_x] = 0;
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
    printf("\n");
    traverse(0,0);
    print_sdoku();

}