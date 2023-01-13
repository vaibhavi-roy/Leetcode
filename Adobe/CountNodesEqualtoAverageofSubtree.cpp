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
class Solution
{
public:
    int cnt(TreeNode *root)
    {
        return !root ? 0 : 1 + cnt(root->left) + cnt(root->right);
    }
    int sum(TreeNode *root)
    {
        return !root ? 0 : root->val + sum(root->left) + sum(root->right);
    }
    int averageOfSubtree(TreeNode *root)
    {
        if (!root)
            return 0;
        int ans = averageOfSubtree(root->left) + averageOfSubtree(root->right);
        return sum(root) / cnt(root) == root->val ? ans + 1 : ans;
    }
};