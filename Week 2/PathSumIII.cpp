// Time complexity :- O(n)
// Space complexity :- O(1)
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int include(TreeNode* root, int sum)
    {
        if(root == NULL)    return 0;
        int ans = 0;
        if(root->val == sum)    ans++;
        ans += include(root->left, sum - root->val);
        ans += include(root->right, sum - root->val);
        
        return ans;
    }
    int pathSum(TreeNode* root, int sum) {
        
        if(root == NULL)    return 0;
        return pathSum(root->left, sum) + include(root, sum) + pathSum(root->right, sum);
    }
};