// Time complexity :- O(n)
// Space complexity :- O(n)
class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        
        int ans = INT_MAX;
        int dp[366] = {0};
        int vis[366] = {0};
        
        for(int d: days)    vis[d] = 1;
        
        for(int d=1;d<=365;d++)
        {
            int temp = INT_MAX;
            if(vis[d])
            {
                temp = min(temp, min(dp[max(0, d - 1)] + costs[0], min(dp[max(0,d - 7)] + costs[1], dp[max(0, d - 30)] + costs[2])));
                
                dp[d] = temp;
            }
            else
                dp[d] = dp[d-1];
        }
        return dp[365];
    }
};
