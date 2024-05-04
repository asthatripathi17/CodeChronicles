ListNode* removeNthFromEnd(ListNode* head, int n) {
  
    // If only 1 node is present
    if (head == NULL || head->next == NULL) {
        if (n == 1)
            return NULL;
    }
    
    // Finding the size of list using a fast pointer
    ListNode *fast = head;
    int count = 0, size = 1;
    while (fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        count++;
    }
    
    // if size is even
    if (fast == NULL) {
        size = 2 * count;
    } else { // size is odd
        size = (2 * count) + 1;
    }
  
    // Finding the index to be deleted from left
    int realIndex = size - n;
    fast = head;
    count = 0;
  
    // Special Case when head needs to be deleted
    if (realIndex == 0) {
        ListNode *temp = head->next;
        head->next = NULL;
        return temp;
    }
  
    // Making fast reach one node before the target node
    while (count < realIndex - 1) {
        fast = fast->next;
        count++;
    }
  
    // Deleting the target
    ListNode* temp = fast->next;
    fast->next = temp->next;
    temp->next = NULL;
  
    return head;
  }
