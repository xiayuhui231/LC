class Solution {
public:
    TreeNode* targtNode;
    int maxHigh = 0;
    int findBottomLeftValue(TreeNode* root) {
       dfs(root, 1);
       return targtNode->val;
    }
    
    void dfs (TreeNode* node, int higt){
        if(!node->left && !node->right){
            if(higt > maxHigh){
                targtNode = node;
                maxHigh = higt;
            }
            return;
        }
        if(node->left) dfs(node->left, higt+1);
        if(node->right) dfs(node->right, higt+1);
    }
};