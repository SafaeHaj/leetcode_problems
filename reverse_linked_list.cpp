#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0) , next(nullptr) {}
    ListNode(int v) : val(v) , next(nullptr) {}
    ListNode(int v, ListNode* node) : val(v) , next(node) {} 
};

// this recursive methode consists of using two stacks of linked lists:
// one to push nodes into, and another to pop the nodes from
ListNode* reverse(ListNode *push, ListNode *pop) {
    if (pop == nullptr)
        return push;

    ListNode *rest = pop->next;
    pop->next = push;
    // recursive call to the rest each time
    return reverse(pop, rest);
}
    
ListNode* reverseList(ListNode* head) {
    return reverse(nullptr, head);
}
