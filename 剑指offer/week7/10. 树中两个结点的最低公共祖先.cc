// https://www.acwing.com/problem/content/84/

//* Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    // 返回的节点代表的子树包含p或q，如果为nullptr则不包含
    // 递归函数表示的意思：
    // 1. 如果 p,q都在root，返回最近公共祖先
    // 2. 如果 p,q只有一个在，返回该节点（单个节点的祖先就是自己）
    // 3. 如果都不在，返回nullptr
    // 题目保证了存在，最外层肯定会返回正确的最近祖先root
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {

        if (!root)
            return nullptr;

        if (root == p || root == q)
            return root; // 两个都在，或者只有一个在 root子树
        auto left = lowestCommonAncestor(root->left, p, q);
        auto right = lowestCommonAncestor(root->right, p, q);

        if (left && right)
            return root;
        if (left)
            return left;
        return right;
    }
};