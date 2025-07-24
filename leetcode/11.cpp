class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0 ;
        int indexR = height.size()-1;
        int indexL = 0 ;

        while(indexL < indexR)
        {
            int curwidth = indexR - indexL;
            int curheight = min(height[indexR], height[indexL]);
            area = max(area, curwidth*curheight);
            if(curheight != height[indexR]) indexL++;
            else indexR--;
        }
        return area;
    }
};