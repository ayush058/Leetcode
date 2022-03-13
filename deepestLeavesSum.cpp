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
    int deepestLeavesSum(TreeNode* root) {
        int sum = 0;
        int level = 0;
        int maxLevel = INT_MIN;
        dfs(root, sum, level, maxLevel);
        return sum;
    }

    void dfs(TreeNode *root, int& sum, int level, int& maxLevel) {
        if (!root) {
            return;
        }
        if (!root->left && !root->right) {   // Leaf node
            if (level > maxLevel) { // deepest level seen; reset sum & update maxLevel
                sum = root->val;
                maxLevel = level;
            } else if (level == maxLevel) {
                sum += root->val;
            }
        }
        dfs(root->left, sum, level + 1, maxLevel);
        dfs(root->right, sum, level + 1, maxLevel);
    }
};
