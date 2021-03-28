/**
 * Definition for a binary tree node.
 */

#include <stack>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator
{
    //栈顶指针为当前访问的树的节点
    stack<TreeNode *> stk;

    void jump(TreeNode *root)
    {
        while (root)
        {
            stk.push(root);
            root = root->left;
        }
    }

public:
    BSTIterator(TreeNode *root)
    {
        jump(root);
    }

    int next()
    {
        TreeNode *cur = stk.top();
        int val = cur->val;
        stk.pop();

        jump(cur->right);
        return val;
    }

    bool hasNext()
    {
        return !stk.empty();
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */