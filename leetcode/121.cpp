class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int lowestPrice = prices[0];
        for(int i = 1; i < prices.size(); i++)
        {
            if(prices[i] < lowestPrice)
            {
                lowestPrice = prices[i];
            }
            else if(prices[i] > lowestPrice)
            {
                int currentProfit = prices[i] - lowestPrice;
                profit = profit > currentProfit ? profit : currentProfit;
            }
        }
        return profit;
    }
};