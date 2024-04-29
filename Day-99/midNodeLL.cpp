ListNode* middleNode(ListNode* head) {
        
        if(head->next == NULL){ // edge case when only 1 node is present
            return head;
        }
        ListNode *slow = head, *fast = head;
        while(fast != NULL || fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(fast == NULL || fast->next == NULL){
                // Reached the middle node
                break;
            }
        }
        return slow;
    }
