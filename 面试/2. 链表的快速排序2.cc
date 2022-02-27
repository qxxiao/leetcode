// https://www.acwing.com/problem/content/1453/

//*  Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *get_tail(ListNode *head)
    {
        while (head->next)
            head = head->next;
        return head;
    }

    ListNode *quickSortList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        auto left = new ListNode(-1), mid = new ListNode(-1), right = new ListNode(-1);
        auto ltail = left, mtail = mid, rtail = right;
        int val = head->val;

        for (auto p = head; p; p = p->next)
        {
            if (p->val < val)
                ltail = ltail->next = p;
            else if (p->val == val)
                mtail = mtail->next = p;
            else
                rtail = rtail->next = p;
        }

        ltail->next = mtail->next = rtail->next = nullptr;
        left->next = quickSortList(left->next);
        right->next = quickSortList(right->next);

        // 拼接三个链表
        get_tail(left)->next = mid->next;
        get_tail(left)->next = right->next;

        auto p = left->next;
        delete left;
        delete mid;
        delete right;
        return p;
    }
};
