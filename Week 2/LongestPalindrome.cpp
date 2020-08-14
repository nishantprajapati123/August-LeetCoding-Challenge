// Time complexity :- O(n)
// Space complexity :- O(256) = O(1)
class Solution {
public:
    int longestPalindrome(string s) {
        
        vector<int>freq(256, 0);
        
        int max_odd = 0, tot_even = 0;
        for(char c: s)
            freq[c]++;
        
        int total = 0;
        bool flag  =false;
        for(int val: freq)
        {
            if(val%2 == 0)
                total += val;
            else
            {
                flag = true;
                if(val >= 3)    total += val - 1;
            }
        }
        
        if(flag)    total ++;
        return total;
    }
};