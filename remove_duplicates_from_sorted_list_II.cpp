// Remove ALL duplicates from sorted linked list
// Difficulty: Medium

/**
 * Leetcode definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */ 

ListNode* deleteDuplicates(ListNode* head) {   
        ListNode* cur = head;
        ListNode* prev = new ListNode; 
        prev->next = cur;
        ListNode* h = prev;

        signed char check = 0, cur_val;
        
        while (cur != nullptr) {

            cur_val = cur->val;
          
            while (cur->next != nullptr && !(cur_val ^ cur->next->val)) {
                cur->next = cur->next->next;
                check = 1;
            }
            if (check) {
                prev->next = prev->next->next;
                check = 0;
            } 
            else {
                prev = prev->next;
            }
            
            cur = cur->next;
        }

        return h->next;
    }
