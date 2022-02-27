// https://leetcode-cn.com/problems/sort-list/
// 迭代版本

//* Definition for singly-linked list.
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
    ListNode *sortList(ListNode *head)
    {
        int n = 0;
        for (auto p = head; p; p = p->next)
            n++;
        // 虚拟节点
        auto dummy = new ListNode(-1);
        dummy->next = head;

        for (int i = 1; i < n; i *= 2) // 每段的长度
        {
            auto cur = dummy;
            for (int j = 0; j + i < n; j += i * 2)
            {
                auto left = cur->next, right = left;
                for (int k = 0; k < i; k++)
                    right = right->next;

                int l = 0, r = 0;
                while (l < i && r < i && right)
                    if (left->val <= right->val)
                    {
                        cur->next = left;
                        cur = left;
                        left = left->next;
                        l++;
                    }
                    else
                    {
                        cur->next = right;
                        cur = right;
                        right = right->next;
                        r++;
                    }
                while (l < i)
                {
                    cur->next = left;
                    cur = left;
                    left = left->next;
                    l++;
                }
                while (r < i && right)
                {
                    cur->next = right;
                    cur = right;
                    right = right->next;
                    r++;
                }

                cur->next = right;
            }
        }
        return dummy->next;
    }
};
