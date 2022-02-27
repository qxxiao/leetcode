// https://www.acwing.com/problem/content/1453/

//* Definition for singly-linked list.
#include <iostream>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *quickSortList(ListNode *head)
    {

        if (!head || !head->next)
            return head;

        ListNode *left = nullptr, *mid = nullptr, *right = nullptr;
        for (auto p = head; p;)
        {
            auto cur = p->next; // next
            if (p->val == head->val)
            {
                p->next = mid;
                mid = p;
            }
            else if (p->val < head->val)
            {
                p->next = left;
                left = p;
            }
            else
            {
                p->next = right;
                right = p;
            }
            p = cur;
        }
        left = quickSortList(left);
        right = quickSortList(right);
        ListNode *p = left, *pp;
        if (p)
        {
            for (pp = p; pp->next; pp = pp->next)
                ;
            pp->next = mid;
        }
        else
            p = mid;
        if (p)
        {
            for (pp = p; pp->next; pp = pp->next)
                ;
            pp->next = right;
        }
        else
            p = right;
        return p;
    }
};