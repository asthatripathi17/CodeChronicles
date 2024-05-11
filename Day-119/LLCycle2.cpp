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

// Using Hare and Tortoise Algorithm (Floyd's Cycle Finding Algorithm)
ListNode *detectCycle(ListNode *head) {
    
    if(head == NULL || head->next == NULL){
        return NULL;
    }

    ListNode *temp = head, *slow = head, *fast = head;
    bool cycle = false;

    // Find whether cycle is present or not using Hare and Tortoise Algo
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            // cycle detected
            while(slow!=temp){
                // L1 = nk - L2 ; where temp and s meets is the starting point
                slow = slow->next;
                temp = temp->next;
            }
            return temp;
        }
    }
    return NULL;
}
