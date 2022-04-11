class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head, * fast = head;
        while(fast && fast->next){
            slow = slow -> next;
            fast = fast->next->next;
            if(slow == fast){
                ListNode* cur = head;
                while(cur != slow){
                    cur = cur->next;
                    slow = slow->next;
                }
                return cur;
            }
        }
        return NULL;
        
    }
};