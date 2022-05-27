 ListNode* cur=head;
        vector<ListNode*> res;
        int len=0;
        while(cur!=nullptr){
            len++;
            res.push_back(cur);
            cur=cur->next;
        }
        return res[len/2];
