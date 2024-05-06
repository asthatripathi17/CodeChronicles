// Recursive Solution
ListNode* helperFunc(ListNode* head, int &maxi){
        // Base Case
        if(head == NULL || head->next == NULL){
            maxi = head->val; // max value yet
            return head; // last node
        }

        ListNode *newHead = helperFunc(head->next,maxi);
        if(head->val<maxi){ // like 3 --> 8
            head->next = NULL; // removing 3 node
            return newHead; // returning 8 node
        }
        else{
            maxi = head->val; // else updating the value
            head->next = newHead; // connecting to returned list
        }
        return head;
    }
    ListNode* removeNodes(ListNode* head) {
        int maxi = INT_MIN;
        ListNode *newHead = helperFunc(head,maxi);
        return newHead;
    }
