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
    unordered_map<TreeNode *, int> lookup;
    int rob(TreeNode *root)
    {
        return helper(root);
    }
    int helper(TreeNode *node)
    {
        if (!node)
            return 0;
        if (lookup.count(node))
            return lookup[node];
        int left = helper(node->left);
        int right = helper(node->right);
        int left_grandchild = helper(node->left ? node->left->left : nullptr) + helper(node->left ? node->left->right : nullptr);

        int right_grandchild = helper(node->right ? node->right->left : nullptr) + helper(node->right ? node->right->right : nullptr);

        int result = max(node->val + left_grandchild + right_grandchild, left + right);

        lookup[node] = result;
        return result;
    }
};