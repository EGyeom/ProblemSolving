/*
Input: trips = [[2,1,5],[3,3,7]], capacity = 4
Output: false

Input: trips = [[2,1,5],[3,3,7]], capacity = 5
Output: true 
*/
#include <bits/stdc++.h>
using namespace std;

bool compare(vector<int> a, vector<int> b)
{
    return a[1] < b[1];
}

class Solution {
public:
    bool carPooling(vector<vector<int>> trips, int capacity) {
        std::sort(trips.begin(),trips.end(),compare);
        int tripSize = trips.size();
        int max =0;
        int count = 0;
        for(int i =trips[0][1]; i <= 1000; i++)
        {
            if(count == tripSize && max <= capacity) return true;
            else if(max > capacity) return false;
            else
            {
                for(int j =0 ; j < tripSize; j++)
                {
                    if( i == trips[j][1]) {
                        max += trips[j][0];
                        count++;
                    }
                    if( i == trips[j][2])
                    {
                        max -= trips[j][0];
                    }
                }
            }
        }
        return true;   
    }
};

int main()
{
    Solution s;
    printf("%d\n",s.carPooling({{2,4,5},{3,3,7}},5));
}