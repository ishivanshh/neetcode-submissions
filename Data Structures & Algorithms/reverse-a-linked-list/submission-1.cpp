class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        ListNode* current = head;
        while(current != nullptr){
            ListNode* nextnode = current -> next;
            current -> next = prev;
            prev = current;
            current = nextnode;
        }
        return prev;
    }
};


// reverse linked list 1 -> 2 // 2 <- 1