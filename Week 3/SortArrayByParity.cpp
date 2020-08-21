// Time complexity :- O(n)
// Space complexity :- O(1)
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        
        int i = 0, j = A.size()-1, k = 0;
        while(k < j)
        {
            if(A[k] % 2 == 0)
                swap(A[i++], A[k++]);
            else
                swap(A[k], A[j--]);
        }
        return A;
    }
};