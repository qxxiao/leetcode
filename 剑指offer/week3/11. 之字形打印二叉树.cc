// https://www.acwing.com/problem/content/43/

// 添加一个zigzag标记即可
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
    vector<vector<int>> printFromTopToBottom(TreeNode *root)
    {

        vector<vector<int>> v;
        if (!root)
            return v;

        queue<TreeNode *> q;
        q.push(root), q.push(nullptr);

        vector<int> level;
        bool zigzag = false;
        while (q.size())
        {
            auto t = q.front();
            q.pop();
            if (!t)
            {
                if (level.empty())
                    break;
                if (zigzag)
                    reverse(level.begin(), level.end());
                v.push_back(level);
                zigzag = !zigzag;
                level.clear();
                q.push(nullptr);
                continue;
            }
            level.push_back(t->val);
            if (t->left)
                q.push(t->left);
            if (t->right)
                q.push(t->right);
        }
        return v;
    }
};