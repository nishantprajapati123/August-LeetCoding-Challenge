// Time complexity :- O(nlog(n))
// Space complexity :- O(1)
class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        int n = citations.size();
        sort(citations.begin(), citations.end());
        
        int l = 0, h = n-1;
        int ans = 0;
        while(l <= h)
        {
            int mid = l + (h-l)/2;
            int d = n - mid;
            if(citations[mid] >= d)
            {
                ans = max(ans, d);
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        return ans;
    }
};