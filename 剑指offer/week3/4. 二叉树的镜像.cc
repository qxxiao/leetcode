// https : // www.acwing.com/problem/content/37/

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
    void mirror(TreeNode *root)
    {

        if (!root)
            return;

        swap(root->left, root->right);
        mirror(root->left);
        mirror(root->right);
    }
};