Node* linkdelete(Node* head, int n, int m) {

    if(!head || head->next == NULL)   return head;
    
    Node *temp = head;
    
    while(temp){
        
        // skip m nodes
        for(int i = 1; i<m && temp; i++){
            temp = temp->next;
        }
        
        if(!temp || !temp->next) break;
        
        // delete n nodes
        Node *del = temp->next;
        for(int i = 0; i<n && del; i++){
            Node *curr = del->next;
            delete del;
            del = curr;
        }
        
        temp->next = del;
        temp = del;
        
    }
    
    return head;
}
