// Time complexity :- O(nlog(n))
// Space complexity :- O(1)
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        int n = intervals.size();
        sort(intervals.begin(), intervals.end(), [](const vector<int>&t1, const vector<int>&t2)
                                                    {
                                                        return t1[0] <= t2[0];
                                                    });
        int ans = 0;
        int last = 0;
        for(int i=1;i<n;i++)
        {
            if(intervals[i][0] < intervals[last][1])
            {
                ans++;
                if(intervals[i][1] < intervals[last][1])    last = i;
            }
            else
                last = i;
        }
        return ans;
    }
};