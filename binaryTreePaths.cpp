/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution
{
public:
  vector<string> binaryTreePaths(TreeNode *root)
  {
    vector<string> ans;

    // base case
    if (!root)
      return ans;

    string curr = "";

    dfsUtil(root, curr, ans);

    return ans;
  }

  void dfsUtil(TreeNode *root, string curr, vector<string> &ans)
  {
    if (!root)
      return;

    if (isLeaf(root))
    {
      curr += to_string(root->val);
      ans.push_back(curr);

      return;
    }

    curr += to_string(root->val) + "->";

    // recurse on left subtree
    dfsUtil(root->left, curr, ans);

    // recurese on right subtree
    dfsUtil(root->right, curr, ans);
  }

  bool isLeaf(TreeNode *node)
  {
    return (node && !node->left && !node->right);
  }
};
