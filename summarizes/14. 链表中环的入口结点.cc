// https://www.acwing.com/problem/content/86/

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *entryNodeOfLoop(ListNode *head)
    {

        ListNode *s = head, *f = head;

        while (f && f->next && f->next->next)
        {
            s = s->next;
            f = f->next->next;

            // 有环
            if (s == f)
            {
                s = head;

                // 慢指针和快指针相遇
                // 慢指针返回head，快指针位置不变，都没次一步，再次相遇的地点就是环的入口
                while (s != f)
                {
                    s = s->next;
                    f = f->next;
                }
                return s;
            }
        }
        return nullptr;
    }
};