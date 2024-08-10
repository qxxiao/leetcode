//* 二叉树的前序遍历
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
    vector<int> preorderTraversal(TreeNode *root) {
        if (!root)
            return res;

        res.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return res;
    }
};

//* 迭代写法---------------------------------------------

class Solution {
    vector<int> res;
    stack<TreeNode *> stk;

    vector<int> preorderTraversal(TreeNode *root) {
        // 根-左-右
        //* 迭代发现，可以看作是每次访问最左链，并且满足 根-左-右
        while (root || stk.size()) {
            while (root) {                // 遍历左链
                res.push_back(root->val); // 先访问根
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            root = root->right;
        }
    }
};

// // * 该思路，每次出栈时访问元素
// class Solution {
//     vector<int> res;
//     stack<TreeNode *> stk;

// public:
//     vector<int> preorderTraversal(TreeNode *root) {

//         // 规范化，出栈时访问
//         if (root)
//             stk.push(root);
//         while (stk.size()) {
//             auto pr = stk.top();
//             stk.pop();
//             res.push_back(pr->val);

//             if (pr->right)
//                 stk.push(pr->right);
//             if (pr->left)
//                 stk.push(pr->left);
//         }
//         return res;
//     }
// };
