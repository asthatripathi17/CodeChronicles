// Recursive Solution
ListNode* helperFunc(ListNode* head, bool &carry){
  // Base Case
  if(head == NULL || head->next == NULL){
      int temp = head->val * 2;
      if(temp >= 10){
          carry = true;
          temp = temp%10;
      }
      head->val = temp;
      return head;
  }
  // Recursively going to end node
  ListNode *newHead = helperFunc(head->next,carry);
  int temp = head->val * 2;
  if(carry == true){
      temp += 1;
      carry = false; 
  }
  if(temp >= 10){
      carry = true;
      temp = temp%10;
  }
  head->val = temp;
  return head;
}

// Main Func
ListNode* doubleIt(ListNode* head) {
    bool carry = false;
    ListNode *newHead = helperFunc(head,carry);

    // Means we need to add 1 in the beginning
    if(carry == true){
        ListNode* extra = new ListNode(1,newHead);
        return extra;
    }
    return newHead;
}
