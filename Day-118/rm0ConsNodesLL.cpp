  ListNode* removeZeroSumSublists(ListNode* head) {
  if(head->next == NULL){
    if(head->val == 0){
        return NULL;
    }
    return head;
  }
  
  ListNode *dummy = new ListNode(0,head); // to keep the hold of LL
  ListNode *temp = dummy;
  map<int,ListNode*> store;
  int pSum = 0;
  
  while(temp!=NULL){
    pSum += temp->val;
    
    if(store.find(pSum) == store.end()){
        store[pSum] = temp;
        temp = temp->next;
    }
    else{
        // removing entries from hashmap
        ListNode *temp2 = store[pSum]->next;
        int newPsum = pSum;
        while(temp2!=temp){
            newPsum += temp2->val;
            store.erase(newPsum);
            temp2 = temp2->next;
        }
        // Establishing new link
        store[pSum]->next = temp->next;
        temp->next = NULL;
        temp = store[pSum]->next;
    }

  }
  return dummy->next;
}
