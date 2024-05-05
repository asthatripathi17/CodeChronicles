void deleteNode(ListNode* node) {
        // Just copy the values as predecessor node is not given therefore can't delete
        while(node->next!=NULL){
            node->val = node->next->val; // gets rid of val for target node
            if(node->next->next == NULL){ // need to stop before last node
                break;
            }
            // Removing last node to decrease the length of list
            node = node->next;
        }

        node->next = NULL;

    }
