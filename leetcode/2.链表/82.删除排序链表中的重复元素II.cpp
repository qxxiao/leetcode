/**
 * Definition for singly-linked list.
 */

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {

        if (!head || !head->next)
            return head;

        ListNode *nhead = new ListNode(-500, head);
        ListNode *pre = nhead, *cur = head, *next = cur->next;

        while (next)
        {
            while (next && next->val == cur->val)
                next = next->next;
            if (next != cur->next) //删除[cur,next)
                pre->next = next;
            else
                pre = pre->next;
            //调整cur,next
            cur = next;
            if (cur)
                next = cur->next;
        }
        return nhead->next;
    }
};