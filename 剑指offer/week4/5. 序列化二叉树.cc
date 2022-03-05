// https://www.acwing.com/problem/content/46/

#include <vector>
#include <queue>
#include <string>
using namespace std;
//* Definition for a binary tree node.
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root)
    {
        string res;
        if (!root)
            return res;
        // 利用level遍历
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            if (t)
            {
                res += to_string(t->val);
                res += " ";
                if (t->left)
                    q.push(t->left);
                else
                    q.push(nullptr);
                if (t->right)
                    q.push(t->right);
                else
                    q.push(nullptr);
            }
            else
            {
                res += "null ";
            }
        }
        return res; // 末尾也有一个空格
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data)
    {

        if (data.empty())
            return nullptr;
        vector<string> nodes;
        int i = 0, j = 0;
        for (; j < data.size(); j++)
        {
            if (data[j] != ' ')
                continue;
            else
            {
                nodes.push_back(data.substr(i, j - i));
                i = j + 1;
            }
        }

        TreeNode *root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode *> q;
        q.push(root);
        int index = 1;
        while (!q.empty())
        {
            auto t = q.front();
            q.pop();
            if (!t)
                continue;

            TreeNode *left, *right;
            if (nodes[index] == "null")
                left = nullptr;
            else
                left = new TreeNode(stoi(nodes[index]));
            t->left = left;
            index++;
            q.push(left);

            if (nodes[index] == "null")
                right = nullptr;
            else
                right = new TreeNode(stoi(nodes[index]));
            t->right = right;
            index++;
            q.push(right);
        }
        return root;
    }
};