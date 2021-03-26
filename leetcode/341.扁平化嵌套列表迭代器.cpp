//两种思路：

//1.伪迭代器，先用dfs遍历所有的元素存储在数组中，然后进行迭代
//2.迭代器：不取元素，使用栈依次遍历

//思考：迭代器最终应该：next获取下一个元素，而hasnext多次调用不会影响next
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class NestedInteger
{
public:
    bool isInteger() const;
    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;
    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator
{ //看懂题意即可（其实就是列表的嵌套用深搜就行了）
public:
    vector<int> v;
    int index = 0;
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        dfs(nestedList);
    }
    int next()
    {
        return v[index++];
    }
    bool hasNext()
    {
        if (index == v.size())
            return false;
        else
            return true;
    }
    void dfs(const vector<NestedInteger> &nestedList)
    {
        for (int i = 0; i < nestedList.size(); i++)
        {
            if (nestedList[i].isInteger())
                v.push_back(nestedList[i].getInteger());
            else
                dfs(nestedList[i].getList());
        }
    }
};

//=================================================================
//
class NestedIterator
{
public:
    stack<const NestedInteger *> st;
    NestedIterator(vector<NestedInteger> &nestedList)
    {
        //逆序入栈
        for (int i = nestedList.size() - 1; i >= 0; i--)
            st.push(&nestedList[i]);
    }

    int next()
    {
        int ret = st.top()->getInteger();
        st.pop();
        return ret;
    }

    //遍历nestList，直到将栈顶元素为Integer
    bool hasNext()
    {
        if (st.empty())
            return false;
        const NestedInteger *tmp = st.top();
        while (!tmp->isInteger())
        {
            st.pop();
            const vector<NestedInteger> &list = tmp->getList();
            for (int i = list.size() - 1; i >= 0; i--)
                st.push(&list[i]);
            //列表可能为空
            if (st.empty())
                return false;
            tmp = st.top();
        }
        return true;
    }
};