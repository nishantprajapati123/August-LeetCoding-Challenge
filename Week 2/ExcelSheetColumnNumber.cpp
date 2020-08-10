// Time complexity :- O(n)
// Space complexity :- O(1)
class Solution {
public:
    long int power(long int n, long int e)
    {
        long int res = 1;
        while(e > 0)
        {
            if(e&1)
                res = res * n;
            e >>=1;
            n *= n;
        }
        return res;
    }
    int titleToNumber(string s) {
        
        long int n = s.length();
        int res = 0;
        for(int i=0;i<n;i++)
        {
            res += power(26, n-i-1) * (s[i] - 'A' + 1);
        }
        return res;
    }
};