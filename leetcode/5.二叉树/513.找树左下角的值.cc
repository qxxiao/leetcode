struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

/**
 * 深度遍历/广度遍历
 * 深度遍历时，先左后右遍历，记录最大深度即可。（前序遍历）每层/相同深度，第一个访问的节点就是树的左下角节点
 *
 */

class Solution {
public:
    int res = 0, maxDepth = 0;
    int findBottomLeftValue(TreeNode *root) {
        dfs(root, 1);
        return res;
    }

    void dfs(TreeNode *root, int d) {
        if (!root)
            return;
        if (d > maxDepth) {
            maxDepth = d;
            res = root->val;
        }
        dfs(root->left, d + 1);
        dfs(root->right, d + 1);
    }
};