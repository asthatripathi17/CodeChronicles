void reorderList(ListNode* head) {

    if (!head || !head->next) return; 

    deque<ListNode*> store;
    ListNode *temp = head;

    while(temp != NULL){
        store.push_front(temp);
        temp = temp->next;
    }

    bool flag = true;

    temp = head;

    while(store.size()>1){
        ListNode *curr;
        
        if(flag){
            curr = store.back();
            store.pop_back();
        }
        else{
            curr = store.front();
            store.pop_front();
        }

        temp->next = curr;
        temp = curr;
        flag = !flag;
    }

    if (!store.empty()) {
        temp->next = store.front();
        temp = temp->next;
    }

    temp->next = NULL;
}
