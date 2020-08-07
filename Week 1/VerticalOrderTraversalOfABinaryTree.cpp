// Time complexity :- O(nlog(n))
// Space complexity :- O(n)
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
    void dfs(TreeNode* root, int* low, int* high, int curr)
    {
        if(root == NULL) return;
        *low = min(*low, curr);
        *high = max(*high, curr);
        dfs(root->left, low, high, curr-1);
        dfs(root->right, low, high, curr+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int> >ans;
        if(root == NULL)    return ans;
        int low = 0, high = 0, curr = 0;
        dfs(root, &low, &high, curr);
        ans.resize(high - low + 1);
        // cout<<low<<" "<<high<<"\n"<<ans.size();
        queue<pair<TreeNode*, int> >que;
        que.push({root, 0});
        // mp[0 + abs(low)].insert(root->val);
        
        while(!que.empty())
        {
            int sz = que.size();
            map<int, set<int> >mp;
            while(sz--)
            {
                int id = que.front().second;
                TreeNode* node = que.front().first;
                que.pop();
                mp[id + abs(low)].insert(node->val);
                
                if(node->left)  que.push({node->left, id-1});
                if(node->right) que.push({node->right, id+1});
            }
            for(auto x: mp)
            {
                for(auto y: x.second)
                    ans[x.first].push_back(y);
            }
        }
        
        
        return ans;
    }
};