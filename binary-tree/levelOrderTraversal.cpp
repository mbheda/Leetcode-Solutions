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
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> ans;

    // base case
    if (!root)
      return ans;

    queue<TreeNode *> Q;
    Q.push(root);
    Q.push(NULL);

    vector<int> level;

    TreeNode *curr = root;

    while (Q.empty() == false)
    {
      TreeNode *curr = Q.front();
      Q.pop();

      if (curr)
      {
        level.push_back(curr->val);
        if (curr->left)
          Q.push(curr->left);

        if (curr->right)
          Q.push(curr->right);
      }
      else
      {
        ans.push_back(level);
        level.resize(0);

        if (Q.empty() == false)
          Q.push(NULL);
      }
    }

    return ans;
  }
};
