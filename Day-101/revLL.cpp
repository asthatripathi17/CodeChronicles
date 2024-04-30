ListNode* reverseList(ListNode* head) {
        
        // Only changes and reverses the data not the nodes
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode *temp = head;
        stack<int> st; // as it is LIFO --> reversal
        while(temp!=NULL){
            st.push(temp->val);
            temp = temp->next;
        }
        temp = head;
        while(temp!=NULL){
            temp->val = st.top();
            st.pop();
            temp = temp->next;
        }

        return head;
    }

ListNode* reverseList(ListNode* head) {
        
        // Reversing the LL without using extra space (Iterative Solution)
        if(head == NULL || head->next == NULL){
            return head;
        }

        ListNode *curr = head, *prev = NULL, *front;
        while(curr!=NULL){
            // Saving the front node
            front = curr->next;
            // Reversing
            curr->next = prev;
            // Updating the nodes
            prev = curr;
            curr = front;
        }

        return prev;
    }

ListNode* reverseList(ListNode* head) {
        
        // Reversing the LL
        if(head == NULL || head->next == NULL){
            return head;
        }
        // Recursive Solution
        ListNode *newHead = reverseList(head->next);
        ListNode *front = head->next;
        front->next = head;
        head->next = NULL;

        return newHead;
    }
