vector<int> nextLargerNodes(ListNode* head) {

    stack<pair<int,ListNode*>> ms;
    int n = 0; // calc the length of LL while traversing
    vector<int> output;
    ListNode *temp = head;

    while(temp!=NULL){
        while (!ms.empty() && ms.top().second->val < temp->val) {
            output[ms.top().first] = temp->val;
            ms.pop();
        }
        ms.push({n, temp});
        output.push_back(0);
        n++;
        temp = temp->next;
    }

    return output;
}
