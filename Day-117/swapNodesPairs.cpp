ListNode* swapPairs(ListNode* head) {
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode *temp = head, *first = head, *second = first->next;
    ListNode *temp2 = second->next, *ans = head->next;

    while(temp!=NULL && first!=NULL && second!=NULL){
        // Changing the links
        second->next = first;
        first->next = temp2;
        if(first!=head){
            temp->next = second;
        }

        // if reached the end
        if(first->next == NULL){
            break;
        }

        // Updating the links (Moving forward)
        temp = first;
        first = temp->next;
        second = first->next;
        if(second!=NULL){
            temp2 = second->next;
        }
    }

    return ans;
}
