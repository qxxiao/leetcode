// https://www.acwing.com/problem/content/18/

#include <vector>
using namespace std;
//  * Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
    vector<int> printListReversingly(ListNode *head)
    {

        vector<int> v;
        for (; head; head = head->next)
        {
            v.push_back(head->val);
        }
        reverse(v.begin(), v.end());
        return v;
    }
};