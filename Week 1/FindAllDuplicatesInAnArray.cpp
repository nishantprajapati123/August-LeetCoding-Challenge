// Time complexity :- O(n)
// Space complexity :- O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int next_id = abs(nums[i])-1;
            if(nums[next_id] > 0)
                nums[next_id] = -nums[next_id];
            else
                ans.push_back(next_id+1);
        }
        return ans;
    }
};