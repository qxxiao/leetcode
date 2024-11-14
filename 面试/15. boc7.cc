/**
 * @file 15. boc7.cc
 * @brief 一颗二叉树中，相邻2个节点的值如果一奇一偶，该条边称为重要边。
 * 一个节点的价值：以该节点为根节点的子树中，重要边的条数。
 * 求树的价值。
 */

#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    long res = 0;
    int value(TreeNode *root) {
        dfs(root);
        return res;
    }

    int dfs(TreeNode *root) {
        if (!root) {
            return 0;
        }
        int lv = dfs(root->left);
        int rv = dfs(root->right);
        int v = lv + rv;
        if (root->left && (root->val + root->left->val) % 2 == 1)
            v++;
        if (root->right && (root->val + root->right->val) % 2 == 1)
            v++;
        res += v;
        return v;
    }
};

int main() {
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(4);

    Solution s;
    cout << s.value(root) << endl;
}