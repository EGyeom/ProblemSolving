#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int oddCells(int m, int n, vector<vector<int>>& indices) {
        std::vector<std::vector<int>> cells(m,vector<int>(n,0));
        std::map<int,int> rows;
        std::map<int,int> cols;
        for(auto indice : indices)
        {
            if(rows.find(indice[0]) == rows.end())
            {
                rows.insert({indice[0],1});
            }
            else rows[indice[0]]++;

            if(cols.find(indice[1]) == cols.end())
            {
                cols.insert({indice[1],1});
            }
            else cols[indice[1]]++;
        }

        for(auto row : rows)
        {
            for(int i =0; i < n; i++)
            {
                cells[row.first][i] = row.second;
            }
        }

        for(auto col : cols)
        {
            for(int i =0; i < m; i++)
            {
                cells[i][col.first] += col.second;
            }
        }
        int count = 0;
        for(int i =0; i < m; i++)
        {
            for(int j =0; j < n; j++)
            {
                if(cells[i][j] % 2 == 0) continue;
                count++;
            }
        }
    return count;
    }
};

int main()
{

}