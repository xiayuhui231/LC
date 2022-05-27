class Solution {
public:
    map<int, multiset<int>> res;
    void helpr(TreeNode* node,int m, int n){
        if(!node) return ;
        res[m].insert(n*10000+node->val);
        helpr(node->left,m-1,n+1);
        helpr(node->right,m+1,n+1);
        return;
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helpr(root,0,0);
        vector<vector<int>>num;
        for(auto x:res){
            vector<int>cur;
            for(auto v:x.second){
                cur.push_back(v%10000);
            }
                num.push_back(cur);
        }
        return num;

    }
};