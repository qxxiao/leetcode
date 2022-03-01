// https://www.acwing.com/problem/content/85/
// 思维题

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
    void deleteNode(ListNode *node)
    {

        node->val = node->next->val;
        node->next = node->next->next;
    }
};