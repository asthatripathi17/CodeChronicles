bool isPalindrome(ListNode* head) {
        
        if(head == NULL || head->next == NULL){
            return true;
        }
        ListNode *temp = head;
        stack<int> check;
        
        while(temp!=NULL){
            check.push(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(!check.empty()){
            if(check.top() == temp->val){
                check.pop();
            }
            else{
                return false;
            }
            temp = temp->next;
        }

        return true;
    }
