// Time complexity :- O(n*sqrt(max(A[i])))
// Space complexity :- O(max(A[i]))
class Solution {
public:
    int _find(int x, vector<int>&parent)
    {
        while(parent[x] != -1)
        {
            x = parent[x];
        }
        return x;
    }
    void _union(int x, int y, vector<int>&parent)
    {
        int f1 = _find(x, parent);
        int f2 = _find(y, parent);
        
        if(f1 != f2)
            parent[f2] = f1;
    }
    int largestComponentSize(vector<int>& A) {
        
        int n = A.size();
        vector<int>parent(100005, -1);
        
        for(int num: A)
        {
            for(int e=2;e*e<=num;e++)
            {
                if(num % e == 0)
                {
                    _union(e, num, parent);
                    _union(num, num/e, parent);
                }
            }
        }
        int ans = 0;
        unordered_map<int, int>mp;
        for(int num: A)
        {
            int f = _find(num, parent);
            mp[f]++;
            ans = max(ans, mp[f]);
        }
        
        return ans;
    }
};