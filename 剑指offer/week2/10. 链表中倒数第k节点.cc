// https://www.acwing.com/problem/content/32/

// *Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *findKthToTail(ListNode *pListHead, int k)
    {

        int i = 0;
        ListNode *p = pListHead;
        while (p)
        {
            i++;
            p = p->next;
        }
        if (k > i)
            return nullptr;

        p = pListHead;
        for (int j = 0; j < i - k; j++)
        {
            p = p->next;
        }
        return p;
    }
};