ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *node = new ListNode(-1);
    ListNode *temp = node;
    ListNode *node1 = l1;
    ListNode *node2 = l2;
    int sum = 0, carry = 0;
    while(node1!=NULL || node2!=NULL){
        sum = carry;
        if(node1!=NULL){
            sum += node1->val;
            node1 = node1->next;
        }
        if(node2!=NULL){
            sum += node2->val;
            node2 = node2->next;
        }
        carry = 0;
        if(sum>9){
            carry = 1;
            sum = sum-10;
        }
        ListNode *newNode = new ListNode(sum);
        temp->next = newNode;
        temp = newNode;
    }
    if(carry!=0){
        ListNode *newNode = new ListNode(carry);
        temp->next = newNode;
    }
    ListNode *result = node->next;
    node->next = NULL;
    return result;
}
