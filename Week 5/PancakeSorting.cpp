// Time complexity :- O(n^2)
// Space complexity :- O(1)
class Solution {
public:
    void change(vector<int>&A, int x)
    {
        for(int i=0;i<=x/2;i++)
        {
            swap(A[i], A[x-i]);
        }
    }
    vector<int> pancakeSort(vector<int>& A) {
        
        int n = A.size();
        vector<int>ans;
        for(int i=n; i>=1 ;i--)
        {
            for(int j=0;j<=i-1;j++)
            {
                if(A[j] == i)
                {
                    change(A, j);
                    ans.push_back(j+1);
                    break;
                }
            }
            change(A, i-1);
            ans.push_back(i);
        }
        
        return ans;
    }
};