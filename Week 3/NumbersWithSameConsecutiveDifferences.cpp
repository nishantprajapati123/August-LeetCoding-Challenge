// Time complexity :- O(N*2^N)
// Space complexity :- O(2^N)
#define ll long long int
class Solution {
public:
    void recur(int noDigits, ll curr, int N, int K, vector<int>&ans)
    {
        if(noDigits == N)
        {
            ans.push_back(curr);
            return;
        }
        
        int lastDigit = curr % 10;
        if(lastDigit + K <= 9)
            recur(noDigits + 1, curr * 10 + (lastDigit + K), N, K, ans);
        if(lastDigit - K >= 0 && K!=0)
            recur(noDigits + 1, curr * 10 + (lastDigit - K), N, K, ans);
            
    }
    
    vector<int> numsSameConsecDiff(int N, int K) {
        

        ll curr ;
        vector<int>ans;
        if(N == 1)  ans.push_back(0);
        for(curr = 1;curr<=9;curr++)
        {
            recur(1, curr, N, K, ans);
        }
        
        return ans;
    }
};