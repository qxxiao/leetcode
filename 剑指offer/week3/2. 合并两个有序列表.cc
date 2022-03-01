// https://www.acwing.com/problem/content/description/34/

//* Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *merge(ListNode *l1, ListNode *l2)
    {

        ListNode *dummy = new ListNode(-1), *p = dummy;
        while (l1 && l2)
        {
            if (l1->val <= l2->val)
                p->next = l1, l1 = l1->next, p = p->next;
            else
                p->next = l2, l2 = l2->next, p = p->next;
        }
        if (l1)
            p->next = l1;
        if (l2)
            p->next = l2;
        return dummy->next;
    }
};