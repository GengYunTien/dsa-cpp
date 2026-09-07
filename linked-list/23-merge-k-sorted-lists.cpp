#include <iostream>
#include <queue>
#include <vector>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution: use min heap to always get the smallest node
// - push all list heads into min heap
// - each time pop the smallest node and push its next node
// Time Complexity O(n log k) - n is total nodes, k is number of lists
// Space Complexity O(k) - heap stores at most k nodes
struct Compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, Compare> minHeap;
    for (ListNode* list : lists) {
        if (list) {
            minHeap.push(list);
        }
    }

    ListNode dummy(0);
    ListNode* current = &dummy;
    while (!minHeap.empty()) {
        ListNode* nextNode = minHeap.top();
        minHeap.pop();
        
        current->next = nextNode;
        current = current->next;
        if (nextNode->next) {
            minHeap.push(nextNode->next);
        }
    }
    return dummy.next;
}