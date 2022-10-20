#include <iostream>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

bool hasCycle(ListNode *head)
{
    if (head == nullptr || head->next == nullptr)
        return false;

    ListNode *first = head;
    ListNode *second = first;

    while (second != nullptr && second->next != nullptr)
    {
        if (second->next == first)
            return true;

        first = first->next;
        second = second->next->next;
    }

    return false;
}