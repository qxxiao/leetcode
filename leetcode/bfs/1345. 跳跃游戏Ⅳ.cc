// bfs 求最短步数
// 注意: 等值的点只扩展一次

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr) {

        unordered_map<int, vector<int>> hash;
        int n = arr.size(), INF = 1e9;
        for (int i = 0; i < n; i++) {
            hash[arr[i]].push_back(i);
        }

        vector<int> dist(n, INF);
        queue<int> q; //下标
        dist[0] = 0;
        q.push(0);

        while (q.size()) {
            auto t = q.front();
            q.pop();

            // 左右相邻点
            for (int i = t - 1; i <= t + 1; i += 2) {
                if (i >= 0 && i < n && dist[i] > dist[t] + 1) {
                    dist[i] = dist[t] + 1;
                    q.push(i);
                }
            }

            // 扩展等值点
            int val = arr[t];
            if (hash.count(val)) {
                for (int i : hash[val]) {
                    if (dist[i] > dist[t] + 1) {
                        dist[i] = dist[t] + 1;
                        q.push(i);
                    }
                }
                // 只扩展一次
                hash.erase(val);
            }
        }

        return dist[n - 1];
    }
};