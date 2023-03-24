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
    ListNode* temp = head;
    signed char cur;

    while (temp != nullptr) {
        cur = temp->val;
        
        while (temp->next != nullptr && !(cur ^ temp->next->val)) { 
            // while loop so that when a duplicate is detected the program checks all its instances            
            temp->next = temp->next->next;
        }

        temp = temp->next;
    }

    return head;
  }
