//* 二叉树的中序遍历
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
    vector<int> inorderTraversal(TreeNode *root) {
        if (!root)
            return res;

        inorderTraversal(root->left);
        res.push_back(root->val);
        inorderTraversal(root->right);
        return res;
    }
};

class Solution {
    vector<int> res;
    stack<TreeNode *> stk;

public:
    vector<int> inorderTraversal(TreeNode *root) {
        while (root || stk.size()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }

            root = stk.top();
            stk.pop();
            res.push_back(root->val); // 在弹出栈才访问根（弹栈，表示左子树的节点都以出栈病访问了）
            root = root->right;
        }
        return res;
    }
};

// // 二叉树的中序遍历，使用Mirrors遍历, 不太直观
// // Morris的好处，空间会从O(h) ，h 最大高度，变成O(1)
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode *root) {
//         vector<int> res;
//         TreeNode *predecessor = nullptr;

//         while (root) {
//             if (!root->left) {
//                 res.push_back(root->val);
//                 root = root->right;
//                 continue;
//             }
//             // 找到predecessor
//             predecessor = root->left;
//             while (predecessor->right && predecessor->right != root) // 注意可能已经设定了
//                 predecessor = predecessor->right;

//             // 判断predecessor是否已经设定，若没有设定，则设定
//             if (predecessor->right == nullptr) {
//                 predecessor->right = root;
//                 root = root->left;
//             }
//             else { // 否则设定过，说明左子树已经遍历完
//                 predecessor->right = nullptr;
//                 res.push_back(root->val);
//                 root = root->right;
//             }
//         }
//         return res;
//     }
// };