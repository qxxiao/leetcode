// https://www.acwing.com/problem/content/89/

// 解法1: 使用map来保存位置，需要额外的存储空间
#include <map>
using namespace std;
//* Definition for singly-linked list with a random pointer.
struct ListNode
{
    int val;
    ListNode *next, *random;
    ListNode(int x) : val(x), next(nullptr), random(nullptr) {}
};

class Solution
{
    map<ListNode *, int> m1;
    map<int, ListNode *> m2;

public:
    ListNode *copyRandomList(ListNode *head)
    {

        if (!head)
            return nullptr;

        ListNode *nh = new ListNode(head->val);
        ListNode *p1 = head, *p2 = nh;
        while (p1->next)
        {
            p2->next = new ListNode(p1->next->val);
            p1 = p1->next;
            p2 = p2->next;
        }
        // 添加map
        p1 = head, p2 = nh;
        int n = 1;
        while (p1)
        {
            m1[p1] = n++;
            p1 = p1->next;
        }
        n = 1;
        while (p2)
        {
            m2[n++] = p2;
            p2 = p2->next;
        }

        p1 = head, p2 = nh;
        while (p1)
        {
            if (p1->random == nullptr)
                p2->random = nullptr;
            else
                p2->random = m2[m1[p1->random]];
            p1 = p1->next;
            p2 = p2->next;
        }
        return nh;
    }
};

// 解法2: 不需要额外的存储空间, 使用相对位置来复制链表

/**
 * Definition for singly-linked list with a random pointer.
 * struct ListNode {
 *     int val;
 *     ListNode *next, *random;
 *     ListNode(int x) : val(x), next(NULL), random(NULL) {}
 * };
 */
class Solution2
{
public:
    ListNode *copyRandomList(ListNode *head)
    {

        // 在路径上复制原来的节点，相对位置不变
        ListNode *p = head;
        while (p)
        {
            ListNode *node = new ListNode(p->val);
            node->next = p->next;
            p->next = node;
            p = p->next->next;
        }

        // 修改复制节点的random指针
        p = head;
        while (p)
        {
            if (p->random)
                p->next->random = p->random->next;
            p = p->next->next;
        }

        // 取出复制的节点并且恢复原来的链表
        p = head;
        ListNode *dummy = new ListNode(-1), *cur = dummy;
        while (p)
        {
            cur->next = p->next;
            p->next = p->next->next;
            cur = cur->next;
            p = p->next;
        }
        return dummy->next;
    }
};
