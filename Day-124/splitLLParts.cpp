vector<ListNode*> splitListToParts(ListNode* head, int k) {
    // Count the number of nodes in a LL
    int n = 0;
    ListNode *temp = head;
    while(temp!=NULL){
        temp = temp->next;
        n++;
    }
    // Find n/k(for min no of nodes in each LL) and n%k(for extras)
    temp = head;
    int minNodes = n/k, extra = n%k;

    vector<ListNode*> output;
    // Splitting the LL
    while(temp!=NULL && k>0){
        ListNode *newHead = temp;
        int totalNodes = minNodes + (extra>0?1:0) - 1;
        extra--;
        while(totalNodes!=0){
            temp = temp->next;
            totalNodes--;
        }
        ListNode *newTail = temp;
        temp = temp->next;
        newTail->next = NULL;
        output.push_back(newHead);
        k--;
        }

    while(k>0){
        output.push_back(NULL);
        k--;
    }

    return output;
}
