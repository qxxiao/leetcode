// https://www.acwing.com/problem/content/87/

// 要求不能创建任何新的结点，只能调整树中结点指针的指向

// * Definition for a binary tree node.
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
    TreeNode *convert(TreeNode *root)
    {

        auto head = dfs(root);
        if (head)
            head->left = nullptr;
        for (auto p = head; p && p->right; p = p->right)
        {
            p->right->left = p;
        }
        return head;
    }

    TreeNode *dfs(TreeNode *root)
    {

        if (!root)
            return nullptr;
        auto left = dfs(root->left);
        auto right = dfs(root->right);
        if (!left)
        {
            root->right = right;
            return root;
        }
        auto p = left;
        while (p->right)
            p = p->right;
        p->right = root;
        root->right = right;
        return left;
    }
};