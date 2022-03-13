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
    int maxCount = 0;
    unordered_map<int, int> count;
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> ans;

        for(auto e : count) {
            if (e.second == maxCount) {
                ans.push_back(e.first);
            }
        }
        return ans;
    }

    int dfs(TreeNode *root) {
        if(!root) {
            return 0;
        }
        int s = root->val + dfs(root->left) + dfs(root->right);
        maxCount = max(maxCount, ++count[s]);
        return s;
    }
};
