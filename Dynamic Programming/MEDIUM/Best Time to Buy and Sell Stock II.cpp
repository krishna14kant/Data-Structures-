#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int profit = 0;
        int buy = prices[0];
        int sell = prices[0];
        
        for(int i = 1; i < prices.size(); ++i)
        {
            if(prices[i] < buy)
            {
                buy = prices[i];
                sell = prices[i];
            }
            else if(prices[i] > sell)
            {
                sell = prices[i];
                profit += (sell - buy);
                buy = prices[i];
            }
        }
        return profit;
    }
};

int main()
{
    return 0;
}