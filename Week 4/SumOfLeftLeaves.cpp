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
    int sum(TreeNode* root, int status)
    {
        if(root == NULL)    return 0;
        if(root->left == NULL && root->right == NULL && status == 1)    return root->val;
        
        return sum(root->left, 1) + sum(root->right, 2);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        
        return sum(root, 0);
    }
};