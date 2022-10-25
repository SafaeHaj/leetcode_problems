#include <iostream>
#include <vector>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *removeElements(ListNode *head, int val)
{
    ListNode *newhead = new ListNode();
    ListNode *tracker = newhead;

    while (head != nullptr)
    {
        if (head->val != val)
        {
            tracker->next = head;
            tracker = tracker->next;
        }

        head = head->next;
        tracker->next = nullptr;
    }

    return newhead->next;
}