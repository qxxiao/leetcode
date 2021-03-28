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
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    ListNode *findKthToTail(ListNode *pListHead, int k)
    {
        vector<ListNode *> v;
        while (pListHead)
        {
            v.push_back(pListHead);
            pListHead = pListHead->next;
        }
        if (k == 0 || k > v.size())
            return nullptr;
        return v[v.size() - k];
    }
};