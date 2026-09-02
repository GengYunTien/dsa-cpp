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

// Solution 1: Iterative
// Time Complexity: O(n + m) where n and m are the lengths of the two lists
// Space Complexity: O(1)
ListNode* mergeTwoListsIterative(ListNode* list1, ListNode* list2) {
    ListNode dummy(0);
    ListNode* current = &dummy;

    while (list1 && list2) {
        if (list1->val < list2->val) {
            current->next = list1;
            list1 = list1->next;
        }
        else {
            current->next=list2;
            list2 = list2->next;
        }
        current = current->next;
    }

    current->next = list1 ? list1 : list2; 
    return dummy.next;
}

// Solution2: Recursive
// Time Complexity: O(n + m) where n and m are the lengths of the two lists
// Space Complexity: O(n + m) - recursion call stack
ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
    if (list1 == nullptr) {
        return list2;
    }
    if (list2 == nullptr) {
        return list1;
    }

    if (list1->val < list2->val) {
        list1->next = mergeTwoLists(list1->next, list2);
        return list1;
    }
    else {
        list2->next = mergeTwoLists(list1, list2->next);
        return list2;
    }
}