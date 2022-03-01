// https://www.acwing.com/problem/content/41/

#include <vector>
#include <queue>
using namespace std;
//* Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
    vector<int> printFromTopToBottom(TreeNode *root)
    {

        vector<int> v;
        if (!root)
            return v;

        queue<TreeNode *> q;
        q.push(root);

        while (q.size())
        {
            auto p = q.front();
            q.pop();
            v.push_back(p->val);
            if (p->left)
                q.push(p->left);
            if (p->right)
                q.push(p->right);
        }
        return v;
    }
};