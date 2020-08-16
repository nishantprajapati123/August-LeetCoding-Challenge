// Time complexity :- O(n)
// Space complexity:- O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int n = prices.size();
        if(n == 0)  return 0;
        /*
        Space complexity :- O(n)
        
        
        int left[n], right[n];
        int buy = prices[0], sell = prices[n-1];
        
        left[0] = right[n-1] = 0;
        for(int i=1;i<n;i++)
        {
            buy = min(buy, prices[i]);
            left[i] = max(left[i-1], prices[i] - buy);
        }
        
        for(int i=n-2;i>=0;i--)
        {
            sell = max(sell, prices[i]);
            right[i] = max(right[i+1], sell - prices[i]);
        }
        
        int ans = 0;
        for(int i=0;i<n;i++)
            ans = max(ans, left[i] + right[i]);
        
        return ans;
        */
        
        int buy_t1 = INT_MAX, sell_t1 = 0;
        int buy_t2 = INT_MIN, sell_t2 = 0;
        for(int i=0;i<n;i++)
        {
            buy_t1 = min(buy_t1, prices[i]);
            sell_t1 = max(sell_t1, prices[i] - buy_t1);
            buy_t2 = max(buy_t2, sell_t1 - prices[i]);    //also contains profit from previous transaction thats                                                            why we are maximising it.
            sell_t2 = max(sell_t2, buy_t2 + prices[i]);
        }
        return sell_t2;
    }
};