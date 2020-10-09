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
  int diameterOfBinaryTree(TreeNode *root)
  {
    // base case
    if (!root)
      return 0;

    return max(diameterOfBinaryTree(root->left), max(diameterOfBinaryTree(root->right), depthOfTree(root->left) + depthOfTree(root->right)));
  }

  int depthOfTree(TreeNode *root)
  {
    if (!root)
      return 0;

    return 1 + max(depthOfTree(root->left), depthOfTree(root->right));
  }
};
