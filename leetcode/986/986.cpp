#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int firstListSize = firstList.size();
        int secondListSize = secondList.size();
        int i=0, j=0;
        int start =0, end =0;
        vector<vector<int>> ans;
        ans.clear();
        while(i != firstListSize && j != secondListSize)
        {
            start = firstList[i][0] > secondList[j][0] ? firstList[i][0] : secondList[j][0];
            end = firstList[i][1] > secondList[j][1] ? secondList[j][1] : firstList[i][0];

            if(start <= end)
                ans.push_back({start,end});
            
            if(firstList[i][1] < secondList[j][1])
            {
                i++;
            }
            else
            {
                j++;
            }
        }
    }
};


int main()
{
  vector<vector<int>> first = {{0,2},{5,10},{13,23},{24,25}};
  vector<vector<int>> second = {{1,5},{8,12},{15,24},{25,26}};

  Solution s;
  s.intervalIntersection(first, second);
}