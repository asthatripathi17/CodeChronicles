ListNode* mergeNodes(ListNode* head) {
    
    if(!head)   return head;

    ListNode *pz = head;

    while(pz->next != NULL){
        
        ListNode *curr = pz->next;
        if(curr->val == 0){
            pz = curr;
            curr = pz->next;
        }
        if(curr){

            if(curr->next->next == NULL){ // to remove the last zero
                curr->next = NULL;
            }

            pz->val += curr->val; // adding

            // delete the nodes
            pz->next = curr->next;
            curr->next = NULL;
            curr = pz->next;
        }
    }

    return head;
}
