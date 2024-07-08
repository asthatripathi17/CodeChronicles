vector<int> nodesBetweenCriticalPoints(ListNode* head) {
    ListNode* prev = head;
    ListNode* curr = head->next;
    int index = 2;
    if(curr->next == NULL){
        return {-1,-1};
    }
    int minima = INT_MAX;

    vector<int> critical_point;

    while(curr->next != NULL){
        if((prev->val < curr->val && curr->val > curr->next->val) || (prev->val > curr->val && curr->val < curr->next->val)){
            if(critical_point.size()!=0){
                minima = min(minima,index - critical_point.back());
            }
            critical_point.push_back(index);
        }
        curr = curr->next;
        prev = prev->next;
        index++;
    }
    if(critical_point.size() == 0 || critical_point.size() == 1){
        return {-1,-1};
    }
    int maxima = critical_point.back() - critical_point[0];

    return {minima,maxima}; 
}
