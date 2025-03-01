ListNode* rotateRight(ListNode* head, int k) {
    if(k == 0 || !head || head->next == NULL) return head;

    // cal length of LL
    int len = 0;
    ListNode *end = head;
    while(end->next!=NULL){
        len++;
        end = end->next;
    }
    len++;

    if(k>=len)   k = k%len;
    if(k == 0)  return head;

    ListNode *temp = head;

    for(int i = 1; i<len-k; i++){
        temp = temp->next;
    }

    ListNode *newHead = temp->next;
    temp->next = NULL;
    end->next = head;
    head = newHead;

    return head;
}
