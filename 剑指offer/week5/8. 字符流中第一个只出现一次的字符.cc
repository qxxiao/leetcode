// https://www.acwing.com/problem/content/60/

#include <unordered_map>
#include <queue>
using namespace std;
// class Solution{
// public:
//     unordered_map<char, int> map;
//     vector<char> v;
//     int i=-1;
//     //Insert one char from stringstream
//     void insert(char ch){
//         map[ch]++;
//         v.push_back(ch);
//         if(i==-1){
//             if(map[ch]==1)
//                 i=v.size()-1;
//             return;
//         }
//         if(ch!=v[i]) return;
//         while(i<v.size() && map[v[i]]>1) i++;
//         if(i>=v.size()) i=-1;
//     }
//     //return the first appearence once char in current stringstream
//     char firstAppearingOnce(){
//         if(i==-1) return '#';
//         else return v[i];
//     }
// };

// 使用queue进行优化
class Solution
{
public:
    unordered_map<char, int> count;
    queue<int> q;
    // Insert one char from stringstream
    void insert(char ch)
    {
        if (++count[ch] > 1)
        {
            while (q.size() && count[q.front()] > 1)
                q.pop();
        }
        else
            q.push(ch);
    }

    // return the first appearence once char in current stringstream
    char firstAppearingOnce()
    {
        return q.empty() ? '#' : q.front();
    }
};