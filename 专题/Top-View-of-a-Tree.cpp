void topView(Node * root) {
        if(root == nullptr)
            return;
        queue<pair<Node*,int>> q;
        map<int,Node*> top;
        q.push(make_pair(root,0));
        top[0]=root;
        while(!q.empty()){
            auto temp = q.front();
            q.pop();
            if(temp.first->left){
                q.push(make_pair(temp.first->left,temp.second-1));
                if(top.find(temp.second-1)==top.end())
                    top[temp.second-1]=temp.first->left;
            }
            if(temp.first->right){
                q.push(make_pair(temp.first->right,temp.second+1));
                if(top.find(temp.second+1)==top.end())
                    top[temp.second+1]=temp.first->right;
            }
        }
        for(auto x:top)
            cout<<x.second->data<<" ";
    }