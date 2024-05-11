// Using Hashmap
ListNode *detectCycle(ListNode *head) {
    ListNode *temp = head;
    map<ListNode*,int> nodes;
    int index = 0;

    while(temp!=NULL){
        if(nodes.find(temp) != nodes.end()){
            // Repetition of Node
            return temp;
        }
        nodes[temp] = index;
        temp = temp->next;
        index++;
    }

    return NULL;
}
