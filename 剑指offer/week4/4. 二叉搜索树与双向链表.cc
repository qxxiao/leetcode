// https://www.acwing.com/problem/content/87/

// 要求不能创建任何新的结点，只能调整树中结点指针的指向

#include <iostream>
using namespace std;
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

    // 这里返回的是单链表，最后才转化为双链表
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

// 直接在dfs中改变指针的指向
class Solution2
{
public:
    TreeNode *convert(TreeNode *root)
    {
        if (!root)
            return nullptr;
        auto sides = dfs(root);
        return sides.first;
    }

    // 返回root子数形成的双向链表的头节点和尾节点
    pair<TreeNode *, TreeNode *> dfs(TreeNode *root)
    {
        // 叶子节点
        if (!root->left && !root->right)
            return {root, root};
        if (root->left && root->right)
        {
            auto lside = dfs(root->left), rside = dfs(root->right);
            lside.second->right = root, root->left = lside.second;
            root->right = rside.first, rside.first->left = root;
            return {lside.first, rside.second};
        }
        // 只有左子树
        if (root->left)
        {
            auto lside = dfs(root->left);
            lside.second->right = root, root->left = lside.second;
            return {lside.first, root};
        }
        if (root->right)
        {
            auto rside = dfs(root->right);
            root->right = rside.first, rside.first->left = root;
            return {root, rside.second};
        }
    }
};