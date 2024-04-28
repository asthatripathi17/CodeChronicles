/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    // Approach 1
    bool hasCycle(ListNode *head) {
        // Using Hashing to keep track of visited nodes
        unordered_map<ListNode*,bool> mpp;
        ListNode *temp = head;

        while(temp!=NULL){
            if(mpp.find(temp) != mpp.end()){
                return true;
            }
            else{
                mpp[temp] = true;
            }
            temp = temp->next;
        }

        return false;
    }

    // Approach 2
    bool hasCycle(ListNode *head) {
        // Tortoise and Hare Algorithm
        ListNode *slow = head, *fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};
