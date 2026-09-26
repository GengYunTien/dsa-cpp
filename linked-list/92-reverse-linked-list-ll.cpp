// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution: reverse sublist between left and right using boundary pointers
// - find prevLeft (node before left) and nextRight (node after right)
// - reverse nodes from left to right using nextRight as the stop condition
// Time Complexity: O(n)
// Space Complexity: O(1)
ListNode* reverseBetween(ListNode* head, int left, int right) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode* prevLeft = &dummy;
    for (int i = 0; i < left - 1; i++) {
        prevLeft = prevLeft->next;
    }
    ListNode* nextRight = &dummy;
    for (int i = 0; i < right + 1; i++) {
        nextRight = nextRight->next;
    }

    ListNode* current = prevLeft->next;
    ListNode* prev = nextRight;
    while (current != nextRight) {
        ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    prevLeft->next = prev;
    return dummy.next;
}