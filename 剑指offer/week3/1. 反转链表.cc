// https://www.acwing.com/problem/content/33/

// 迭代+递归版本

//* Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {

        // if(!head || !head->next) return head;
    
        // ListNode *pre=nullptr, *cur=head;
        // while(cur){
        //     auto tmp=cur->next;
        //     cur->next=pre;
        //     pre=cur, cur=tmp;
        // }
        // return pre;

        if (!head || !head->next)
            return head;
        auto t = reverseList(head->next);
        head->next->next = head;
        head->next = nullptr;
        return t;
    }
};