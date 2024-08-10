// 乱序的非重复的 1~n 的数组，进行排序，要求时间复杂度为 O(n)，空间复杂度为 O(1)
// answer: nsort funciton

#include <vector>
#include <iostream>
#include <algorithm>
#include <random>

using namespace std;

// 用随机设备作为随机数生成器的种子
std::random_device rd;
std::mt19937 g(rd());
// default_random_engine(time(0))

void nsort(vector<int> &nums) {

    int n = nums.size();
    for (int i = 0; i < n; i++) {
        // 1~n
        while (nums[i] != i + 1)
            swap(nums[i], nums[nums[i] - 1]);
    }
}

void print(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << " ";
    }
    cout << endl;
}

// 随机生成一个乱序的非重复的 1~n 的数组, 进行测试 Times 次
bool test(int n, int Times = 100) {
    vector<int> arr(n);
    // random 1~N
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }

    for (int i = 0; i < Times; i++) {
        shuffle(arr.begin(), arr.end(), g);
        print(arr);
        nsort(arr);
        for (int i = 0; i < n; i++) {
            if (arr[i] != i + 1) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    // auto arr = initializer_list<int>{1, 2, 3, 4, 5, 6};

    if (!test(20, 1000)) {
        cout << endl << "Test failed!" << endl;
    }
    else
        cout << endl << "Test passed!" << endl;
    return 0;
}