#include <utility>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// Solution: recursion + reverse linked list (#206)
// - check if remaining nodes >= k, if not return head as is
// - reverse k nodes at a time (same approach as #206)
// - recursively process the next group and connect to current tail
// Time Complexity: O(n)
// Space Complexity: O(n/k) - recursion stack depth
class Solution {
    public:
        ListNode* reverseKGroup(ListNode* head, int k) {
            ListNode* check = head;
            for (int i = 0; i < k; i++) {
                if (check == nullptr) {
                    return head;
                }
                check = check->next;
            }

            pair<ListNode*, ListNode*> result = reverseKNodes(head, k);
            ListNode* newHead = result.first;
            ListNode* newStart = result.second;
            ListNode* newTail = head;

            ListNode* nextGroupHead = reverseKGroup(newStart, k);
            newTail->next = nextGroupHead;
            return newHead;

        }
    
    private:
        pair<ListNode*, ListNode*> reverseKNodes(ListNode* head, int k) {
            ListNode* current = head;
            ListNode* prev = nullptr;
            
            for (int i = 0; i < k; i++) {
                ListNode* next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            return {prev, current};
        }
};