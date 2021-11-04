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
{
	vector<int> v;
	int index;

	void dfs(const NestedInteger &nest)
	{
		if (nest.isInteger())
		{
			v.push_back(nest.getInteger());
			return;
		}
		auto &list = nest.getList();
		for (const auto &n : list)
		{
			if (n.isInteger())
				v.push_back(n.getInteger());
			else
				dfs(n);
		}
	}

public:
	NestedIterator(vector<NestedInteger> &nestedList)
	{
		for (auto &nest : nestedList)
			dfs(nest);
		index = 0;
	}

	int next()
	{
		return v[index++];
	}

	bool hasNext()
	{
		return index < v.size();
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

//官方题解
class NestedIterator
{
private:
	vector<int> vals;
	vector<int>::iterator cur;

	void dfs(const vector<NestedInteger> &nestedList)
	{
		for (auto &nest : nestedList)
		{
			if (nest.isInteger())
			{
				vals.push_back(nest.getInteger());
			}
			else
			{
				dfs(nest.getList());
			}
		}
	}

public:
	NestedIterator(vector<NestedInteger> &nestedList)
	{
		dfs(nestedList);
		cur = vals.begin();
	}

	int next()
	{
		return *cur++;
	}

	bool hasNext()
	{
		return cur != vals.end();
	}
};

class NestedIterator
{
private:
	// pair 中存储的是列表的当前遍历位置，以及一个尾后迭代器用于判断是否遍历到了列表末尾
	stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> stk;

public:
	NestedIterator(vector<NestedInteger> &nestedList)
	{
		stk.emplace(nestedList.begin(), nestedList.end());
	}

	int next()
	{
		// 由于保证调用 next 之前会调用 hasNext，直接返回栈顶列表的当前元素，然后迭代器指向下一个元素
		return stk.top().first++->getInteger();
	}

	bool hasNext()
	{
		while (!stk.empty())
		{
			auto &p = stk.top();
			if (p.first == p.second)
			{ // 遍历到当前列表末尾，出栈
				stk.pop();
				continue;
			}
			if (p.first->isInteger())
			{
				return true;
			}
			// 若当前元素为列表，则将其入栈，且迭代器指向下一个元素
			auto &lst = p.first++->getList();
			stk.emplace(lst.begin(), lst.end());
		}
		return false;
	}
};

/////////////////////////////////////////////////////////
//使用迭代器的思想：不过内存开销比较大，每次位置都记录下了
/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator
{
public:
	struct Node
	{
		vector<NestedInteger> l;
		int k;
	};
	stack<Node> stk;

	//跳到下一个int操作
	void jump()
	{
		while (stk.size())
		{
			auto t = stk.top();
			if (t.k == t.l.size())
			{
				stk.pop();
				continue;
			}
			if (t.l[t.k].isInteger())
				break;
			stk.pop();
			stk.push({t.l, t.k + 1});
			stk.push({t.l[t.k].getList(), 0});
		}
	}

	NestedIterator(vector<NestedInteger> &nestedList)
	{
		stk.push({nestedList, 0});
		jump();
	}

	int next()
	{
		auto t = stk.top();
		stk.pop();
		stk.push({t.l, t.k + 1}); //可能不存在
		jump();
		return t.l[t.k].getInteger();
	}

	bool hasNext()
	{
		return stk.size();
	}
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */