// https://www.acwing.com/video/4265/

/**
 * Definition for a binary tree node.
 */
#include <stack>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// class Solution {
// public:
//     TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
//         if(nums.size()==0) return nullptr;
//         int idx =-1, m = -1;
//         for(int i=0; i<nums.size(); i++){
//             if(nums[i]>m) idx=i, m=nums[i];
//         }

//         TreeNode* root = new TreeNode(m);
//         auto l = vector<int>(nums.begin(), nums.begin()+idx);
//         auto r = vector<int>(nums.begin()+idx+1, nums.end());
//         root->left = constructMaximumBinaryTree(l);
//         root->right = constructMaximumBinaryTree(r);
//         return root;
//     }
// };

// 单调栈做法
// 利用递增的思想构建最大二叉树，并且存储最右分支节点
// 每插入一个数，查询应该插入的位置--第一个大于该值的右孩子

class Solution {
   public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        stack<TreeNode *> stk;  // 倒序
        for (int x : nums) {
            auto node = new TreeNode(x);
            while (stk.size() && stk.top()->val < x) {
                node->left = stk.top();  // 只需要最后一个 >x 节点赋值即可
                stk.pop();
            }
            if (stk.size()) stk.top()->right = node;
            stk.push(node);
        }
        while (stk.size() > 1) stk.pop();
        return stk.top();
    }
};