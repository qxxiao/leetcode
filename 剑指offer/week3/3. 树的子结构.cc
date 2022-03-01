// https://www.acwing.com/problem/content/35/

//* Definition for a binary tree node.
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
    bool hasSubtree(TreeNode *pRoot1, TreeNode *pRoot2)
    {

        if (!pRoot1 || !pRoot2)
            return false;
        if (pRoot1->val == pRoot2->val)
        {
            if ((!pRoot2->left || hasSubtree(pRoot1->left, pRoot2->left)) &&
                (!pRoot2->right || hasSubtree(pRoot1->right, pRoot2->right)))
                return true;
        }
        if (hasSubtree(pRoot1->left, pRoot2) || hasSubtree(pRoot1->right, pRoot2))
            return true;
        return false;
    }
};