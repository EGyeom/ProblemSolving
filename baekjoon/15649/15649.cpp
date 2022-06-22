#include <bits/stdc++.h>
using namespace std;

vector<int> v;
int n,m;
int visited[9];
void dfs()
{
    if(v.size() == m)
    {
        for(int& iter : v)
        {
            printf("%d ", iter);
        }
        printf("\n");
        return ;
    }
    for(int i =1; i <= n; i++)
    {
        if(visited[i]) continue;
        visited[i] = true;
        v.push_back(i);
        dfs();
        visited[i] = false;
        v.pop_back();
    }
}

int main()
{
    scanf("%d %d", &n, &m);
    dfs();
}

/*
#include <iostream>

using namespace std;
int check[8] = {0,};
int result[8] = {0,};
int len = 0;
int m,n;

void function(){

    if(len == m)
    {
        for(int i =0; i < m; i++)
        {
            printf("%d ", result[i]);
        }
        printf("\n");
        return;
    }
    for(int i =1 ; i<= n; i++)
    {
        if(check[i-1] == 0)
        {
            check[i-1] = 1;
            result[len++] = i;
            function();
            len--;
            check[i-1] = 0;
        }
    }

}

int main()
{

    std::cin >> n >> m;
    for(int i =1 ; i <=n; i++)
    {
        if(check[i-1] == 0)
        {
            check[i-1] = 1;
            result[len++] = i;
            function();
            len--;
            check[i-1] = 0;
        }
    }
}


*/


/*#include <cstdio>
char a[16]="               ";
int n,m,v[8]; 
void d(int c) {
	if(c==m){printf("%s\n", a);return;}
	for(int i=0;i<n;i++)
		if(!v[i]) {
			a[c] = i + '1';
			v[i] = 1;
			d(c + 2);
			v[i] = 0;
		}
}
int main() {
	scanf("%d%d", &n, &m);
	m += m;
	a[m] = 0;
	d(0);
}
*/