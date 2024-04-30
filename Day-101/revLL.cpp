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
