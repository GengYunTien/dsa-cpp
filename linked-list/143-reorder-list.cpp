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

// Solution: Find middle + Reverse second half + Merge
// Time Complexity: O(n)
// Space Complexity: O(1)
void reorderList(ListNode* head) {
    if (head == nullptr || head->next == nullptr) {
        return;
    }

    // two pointer to find median
    ListNode* slow = head;
    ListNode* fast = head;
    while (fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    // reverse the half linked list
    ListNode* current = slow->next;
    ListNode* prev = nullptr;
    slow->next = nullptr;
    while (current != nullptr) {
        ListNode* nextNode = current->next;
        current->next = prev;
        prev = current;
        current = nextNode;
    }

    // merge the two linked lists
    ListNode* first = head;
    ListNode* second = prev;
    while (second != nullptr) {
        ListNode* nextFirst = first->next;
        ListNode* nextSecond = second->next;
        first->next = second;
        second->next = nextFirst;
        first = nextFirst;
        second = nextSecond;
    }
}