#include <bits/stdc++.h>

class Solution {
public:
    bool compare(vector<int> left, vector<int> right)
    {
        return left[0] < right[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        std::sort(points.begin(), points.end(), compare);
    }
};


int main()
{

}