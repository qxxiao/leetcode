// 定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的头结点。
// 思考题：请同时实现迭代版本和递归版本。

// 样例
// 输入 : 1->2->3->4->5->NULL
// 输出 : 5->4->3->2->1->NULL

#include <iostream>
using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

//使用3个指针，迭代反转
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        //每次改变pre， cur之间的指向，next为临时保存
        ListNode *pre = head, *cur = pre->next, *next;
        while (cur)
        {
            next = cur->next;
            cur->next = pre;

            pre = cur;
            cur = next;
        }
        //pre最后指向最后一个节点
        head->next = nullptr;
        return pre;
    }

    //递归版本
    ListNode *reverseList2(ListNode *head)
    {
        if (!head || !head->next)
            return head;

        auto tail = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return tail;
    }
};
