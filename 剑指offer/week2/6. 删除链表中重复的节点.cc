// https://www.acwing.com/problem/content/27/
// 如果重复的节点保留一个，做法类似

/**
 * Definition for singly-linked list.
 */
#include <cstddef>
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *deleteDuplication(ListNode *head)
    {

        if (!head)
            return head;
        int *st = new int[101]();
        ListNode *h = head;
        while (h)
        {
            st[h->val]++;
            h = h->next;
        }
        // 找到head 注意head移动到最后可能为null
        while (head && st[head->val] > 1)
            head = head->next;

        ListNode *p1 = head, *p2 = head;
        while (p2)
        {
            if (st[p2->val] == 1)
            {
                p1 = p2;
                p2 = p2->next;
            }
            else
            {
                p1->next = p2->next;
                p2 = p2->next;
            }
        }
        delete[] st;
        return head;

        // 对于排序的链表，这种方法更加简单
        // auto dummy = new ListNode(-1);
        // dummy->next = head;

        // auto p = dummy; // 一段前一个节点
        // while (p->next)
        // {
        //     auto q = p->next;
        //     while (q && p->next->val == q->val)
        //         q = q->next;

        //     if (p->next->next == q)
        //         p = p->next;
        //     else
        //         p->next = q;
        // }
        // return dummy->next;
    }

    // 保留重复节点中的一个节点
    ListNode *delete2(ListNode *head)
    {

        if (!head)
            return head;
        ListNode *p1 = head, *p2 = head;
        while (p2)
        {
            if (p2->next && p2->val == p2->next->val)
            {
                p2 = p2->next;
            }
            else
            {
                p1->next = p2->next;
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return head;
    }
};