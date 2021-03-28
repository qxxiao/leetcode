/**
 * Definition for singly-linked list.
 */
#include <iostream>
#include <vector>
using namespace std;

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
    ListNode *rotateRight(ListNode *head, int k)
    {

        if (k == 0 || !head || !head->next)
            return head;
        vector<ListNode *> v;
        while (head)
        {
            v.push_back(head);
            head = head->next;
        }
        k = k % v.size();
        if (k == 0)
            return v[0];
        int nhead = v.size() - k;
        int pre_head = nhead - 1;

        v[pre_head]->next = nullptr;
        v[v.size() - 1]->next = v[0];
        return v[nhead];
    }
};