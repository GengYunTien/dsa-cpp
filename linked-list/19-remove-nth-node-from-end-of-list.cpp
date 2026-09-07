#include <iostream>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution: use dummy node to prevent handling edge case
// - right pointer moves n steps ahead first
// - then both left and right move together until right reaches the last node
// - at this point, left is just before the target node
// Time Complexity: O(n)
// Space Complexity: O(1)
ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode* left = &dummy;
    ListNode* right = &dummy;

    for (int i = 0; i < n; i++) {
        right = right->next;
    }

    while (right->next != nullptr) {
        left = left->next;
        right = right->next;
    }
    left->next = left->next->next;

    return dummy.next;
}