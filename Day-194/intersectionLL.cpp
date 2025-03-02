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

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // two pointer approach
    ListNode *p1 = headA, *p2 = headB;
    
    while(p1 || p2){
        if(p1 == p2){
            break;
        }
        else if(!p1){
            p1 = headB;
        }
        else if(!p2){
            p2 = headA;
        }
        else{
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    return p1;
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    // two pointer approach with adjusted while loop condition
    ListNode *p1 = headA, *p2 = headB;

    while(p1 != p2){
        p1 = p1?p1->next:headB;
        p2 = p2?p2->next:headA;
    }

    return p1;
}
