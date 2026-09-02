class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        ListNode* prev = nullptr; // temp
        ListNode* curr = head; 

        while(curr){
            ListNode* temp = curr -> next; // always move temp
            curr -> next = prev; 
            prev = curr;
            curr = temp;
        }
        return prev;
    }
};


// reverse linked list 1 -> 2 // 2 <- 1