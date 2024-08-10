//* 二叉树的后序遍历
//* 1. 递归写法
//* 2. 迭代写法

#include <vector>
#include <stack>
using namespace std;
/**
 * Definition for a binary tree node.
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution1 {
    vector<int> res;

public:
    vector<int> postorderTraversal(TreeNode *root) {
        if (!root)
            return res;

        postorderTraversal(root->left);
        postorderTraversal(root->right);
        res.push_back(root->val);
        return res;
    }
};

//* 迭代写法---------------------------------------------

//* (1) 常规写法
class Solution {
    vector<int> res;
    stack<pair<TreeNode *, bool>> stk;

public:
    vector<int> postorderTraversal(TreeNode *root) {
        while (root || stk.size()) {
            while (root) {
                stk.push({root, false});
                root = root->left;
            }

            auto &t = stk.top(); // pair<TreeNode*, bool>&
            if (t.second) {
                res.push_back(t.first->val);
                stk.pop();
            }
            else {
                t.second = true; // 标记已经访问过
                root = t.first->right;
            }
        }
        return res;
    }
};

//* (2) 另一种写法, 对前序方式调整遍历顺序，最后整体翻转
class Solution2 {
public:
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> res;

        stack<TreeNode *> stk;

        while (root || !stk.empty()) {

            while (root) {
                res.push_back(root->val);
                stk.push(root);
                root = root->right;
            }

            auto t = stk.top();
            stk.pop();
            root = t->left;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};