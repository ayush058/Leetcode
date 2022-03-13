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
    // Idea is to consider all subtrees starting from their parent node and see
    // if we reach to a point that sum of nodes in the path traversed so far
    // gives the required targetSum.
    int ans = 0;
    int pathSum(TreeNode* root, int targetSum) {
        if(!root) {
            return 0;
        }
        dfs(root, targetSum);
        pathSum(root->left, targetSum);
        pathSum(root->right, targetSum);
        return ans;
    }

    void dfs(TreeNode *root, int target) {
        if(!root) {
            return;
        }
        if(target - root->val == 0) {
            ans++;
        }
        dfs(root->left, target - root->val);
        dfs(root->right, target - root->val);
    }
};
