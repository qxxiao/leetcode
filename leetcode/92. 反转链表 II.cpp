//反转[left, right]之间的链表
//引入虚拟的头节点，避免边界问题（head可能变）

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
    ListNode *reverseBetween(ListNode *head, int left, int right)
    {
        auto dummy = new ListNode(-1, head);

        //a指向区间前一个节点，b,c改变指向
        auto a = dummy;
        for (int i = 0; i < left - 1; i++)
            a = a->next;
        auto b = a->next, c = b->next;

        for (int i = 0; i < right - left; i++)
        {
            auto d = c->next;
            c->next = b;
            b = c;
            c = d;
        }
        a->next->next = c;
        a->next = b;
        return dummy->next;
    }
};