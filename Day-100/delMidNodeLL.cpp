ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL){ // edge case when only 1 node is present
            return NULL;
        }
        // Finding the middle node slow->next is middle node
        ListNode *slow = head, *fast = head;
        while(fast != NULL || fast->next != NULL){
            fast = fast->next->next;

            slow = slow->next;
        }
        // Connecting mid-1 to mid+1 and pointing mid to null
        ListNode *temp = slow->next;
        slow->next = temp->next;
        temp->next = NULL;

        return head;
    }
