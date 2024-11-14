// 对连续非相同的节点进行反转

#include <iostream>
#include <string>

struct Node {
public:
    int val;
    Node *next;
    Node(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    Node *reverse(Node *list) {
        if (!list || !list->next)
            return list;

        Node *dummy = new Node(-1);
        dummy->next = list;
        Node *tail = dummy; // 当前完成翻转的尾节点

        Node *first = tail->next, *last = first;
        // 1 2 2 3 4 3 3 4 5 6
        while (last) {
            // 移动到（连续）最后一个相同的位置
            while (last->next && last->next->val == first->val) {
                last = last->next;
            }
            if (first != last) {
                // 忽略连续相同的节点
                tail = last;
                first = last = (!last) ? nullptr : last->next;
            }
            // 查找连续非相同
            // 不同, 4 3 3 / 4 3 2 1
            if (!last)
                break;
            auto p = last->next;
            while (p && p->val != last->val && (!p->next || p->next->val != p->val)) {
                last = last->next;
                p = last->next;
            }
            if (first != last) {
                // 翻转
                auto t = last->next;
                reverse_(first, last);
                tail->next = last;
                tail = first;
                first->next = t;
                first = last = t;
            }
            else {
                // 1步
                tail = last;
                first = last = last->next;
            }
        }
        return dummy->next;
    }

    void reverse_(Node *head, Node *tail) {
        if (head == tail)
            return;
        Node *p = head, *cur = p->next;
        while (cur && p != tail) {
            auto pt = cur->next;
            cur->next = p;
            p = cur;
            cur = pt;
        }
    }
};

int main() {
    Solution s;
    // 1 2 2 3 4 3 3 4 5 6
    Node *head = new Node(1), *t = head;
    t->next = new Node(2);
    t = t->next;

    t->next = new Node(2);
    t = t->next;
    t->next = new Node(3);
    t = t->next;
    t->next = new Node(4);
    t = t->next;
    t->next = new Node(3);
    t = t->next;
    t->next = new Node(3);
    t = t->next;
    t->next = new Node(4);
    t = t->next;
    t->next = new Node(5);
    t = t->next;
    t->next = new Node(6);
    t = t->next;

    auto h = s.reverse(head);

    while (h) {
        std::cout << h->val << " ";
        h = h->next;
    }
    std::cout << std::endl;
}