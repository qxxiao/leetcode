#include <atomic>
#include <ios>
#include <iostream>
#include <thread>

using namespace std;

int i = 0;

void unlock(int times) {
    for (int j = 0; j < times; j++) {
        int expected = i;
        int target = expected + 1;
        while (!__sync_bool_compare_and_swap(
            &i, expected, target)) { // 使用i++，i,i+1都会不一致
            // do something
            expected = i;
            target = expected + 1;
            cout << this_thread::get_id() << dec << "  +1失败, i=" << i << endl;
        }
    }
    cout << this_thread::get_id() << " unlock " << dec << times << " times"
         << endl;
}

int main() {

    int t = 1000000;
    thread t1(unlock, t), t2(unlock, t);
    t1.join();
    t2.join();

    cout << "main: i=" << i << endl;
    return 0;
}