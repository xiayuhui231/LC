class Solution {
 public:
  TreeNode* pruneTree(TreeNode* root) {
    if (!root) return NULL;
    TreeNode* l = pruneTree(root->left);
    TreeNode* r = pruneTree(root->right);
    if (!l && !r && !root->val) return NULL;
    root->left = l;
    root->right = r;
    return root;
  }
};