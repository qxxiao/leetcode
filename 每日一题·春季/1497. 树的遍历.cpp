//一个二叉树，树中每个节点的权值互不相同。
//现在给出它的后序遍历和中序遍历，请你输出它的层序遍历。

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>

using namespace std;

const int N = 40;
int n;
queue<int> q;
//后序和前序
int post[N], mid[N];
//后序对应的下标
unordered_map<int, int> pmap;
//保存左子树集合，右子树集合
unordered_set<int> lt, rt;
//加速查找左右子树
bool p[N], m[N];

void lr(int root)
{
    lt.clear();
    rt.clear();
    int index;
    for (index = 1; index <= n; index++)
        if (mid[index] == root)
        {
            m[index] = true;
            break;
        }
    for (int i = index - 1; i > 0 && !m[i]; i--)
        lt.insert(mid[i]);
    for (int i = index + 1; i <= n && !m[i]; i++)
        rt.insert(mid[i]);
}
void level()
{
    while (!q.empty())
    {
        int root = q.front();
        q.pop();
        cout << root << " ";

        lr(root);
        int lroot = 0, rroot = 0;
        if (rt.size())
            rroot = post[pmap[root] - 1];
        if (lt.size())
            lroot = post[pmap[root] - 1 - rt.size()];

        if (lroot)
            q.push(lroot);
        if (rroot)
            q.push(rroot);
    }
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> post[i];
        pmap[post[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        cin >> mid[i];

    p[n] = true;
    //按层序将根节点存入队列
    q.push(post[n]);

    level();
    return 0;
}

//模版
/* 
#include <iostream>
#include <algorithm>
#include <cstring>
#include <unordered_map>
#include <queue>

using namespace std;

const int N = 40;

int n;
int postorder[N], inorder[N];
unordered_map<int, int> l, r, pos;

int build(int il, int ir, int pl, int pr)
{
    int root = postorder[pr];
    int k = pos[root];
    //左子树
    if (il < k)
        l[root] = build(il, k - 1, pl, pl + k - 1 - il);
    if (ir > k)
        r[root] = build(k + 1, ir, pl + k - il, pr - 1);
    return root;
}

void bfs(int root)
{
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int t = q.front();
        cout << t << " ";
        q.pop();
        if (l.count(t))
            q.push(l[t]);
        if (r.count(t))
            q.push(r[t]);
    }
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> postorder[i];
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
        pos[inorder[i]] = i;
    }

    int root = build(0, n - 1, 0, n - 1);
    bfs(root);
    return 0;
}
*/