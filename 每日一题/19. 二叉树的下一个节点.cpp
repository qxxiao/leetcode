/**
 * Definition for a binary tree node.
 */
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode *father;
    TreeNode(int x) : val(x), left(NULL), right(NULL), father(NULL) {}
};

class Solution
{
    TreeNode *findMin(TreeNode *root)
    {
        if (!root)
            return nullptr;
        while (root->left)
            root = root->left;
        return root;
    }

public:
    TreeNode *inorderSuccessor(TreeNode *p)
    {
        //有right
        if (p->right)
            return findMin(p->right);
        //无right
        //往上追溯
        TreeNode *pf = p->father;
        while (pf && pf->right == p)
        {
            p = pf;
            pf = pf->father;
        }
        return pf;
    }
};