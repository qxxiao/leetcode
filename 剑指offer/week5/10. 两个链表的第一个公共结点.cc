// https://www.acwing.com/problem/content/62/

//** Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
// 开一个map的解法
// class Solution {
// public:
//     unordered_map<ListNode*, bool> map;
//     ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB) {
//         if(!headA || !headB) return nullptr;

//         while(headB){
//             map[headB]=true;
//             headB=headB->next;
//         }

//         while(headA && map.find(headA)==map.end()){
//             headA=headA->next;
//         }
//         return headA?headA:nullptr;
//     }
// };

class Solution
{
public:
    ListNode *findFirstCommonNode(ListNode *headA, ListNode *headB)
    {
        // 每个链表走一遍，最后会相遇或者都在null
        auto p = headA, q = headB;
        while (p != q)
        {
            if (p)
                p = p->next;
            else
                p = headB;
            if (q)
                q = q->next;
            else
                q = headA;
        }
        return p;
    }
};