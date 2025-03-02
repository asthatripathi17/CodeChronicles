ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // hash based approach, T.C = O(m+n) and S.C.= O(m)
    unordered_set<ListNode*> store;
    ListNode *temp = headA;
    while(temp){
        store.insert(temp);
        temp = temp->next;
    }

    temp = headB;
    while(temp){
        if(store.find(temp)!=store.end()){
            break;
        }
        temp = temp->next;
    }

    return temp;
}
