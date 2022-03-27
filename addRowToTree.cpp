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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        int currDepth = 1;
        if(depth == 1) {
            TreeNode *newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        }
        dfs(root, currDepth, depth, val);
        return root;
    }
    
    void dfs(TreeNode *root, int currDepth, int depth, int val) {
        if(!root) return;
        if(currDepth + 1 == depth) {
            TreeNode *tempLeft = root->left;
            TreeNode *tempRight = root->right;
            root->left = new TreeNode(val);
            root->right = new TreeNode(val);
            root->left->left = tempLeft;
            root->right->right = tempRight;
        }
        
        dfs(root->left, currDepth + 1, depth, val);
        dfs(root->right, currDepth + 1, depth, val);
    }
};
