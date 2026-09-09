#include <iostream>
using namespace std;

// Definition for a Node.
class Node {
    public:
        int val;
        Node* next;
        Node* random;
        
        Node(int _val) {
            val = _val;
            next = NULL;
            random = NULL;
        }
    };

// Solution: interleave new nodes between original nodes
// - Step 1: insert new node after each original node
// - Step 2: set random pointer for each new node
// - Step 3: separate the two linked lists
// Time Complexity: O(n)
// Space Complexity: O(1)
Node* copyRandomList(Node* head) {
    if (head == nullptr) {
        return head;
    }

    Node* current = head;
    while (current != nullptr) {
        Node* newNode = new Node(current->val);
        newNode->next = current->next;
        current->next = newNode;
        current = newNode->next;
    }

    current = head;
    while (current != nullptr) {
        if (current->random != nullptr) {
            current->next->random = current->random->next;
        }
        current = current->next->next;
    }

    current = head;
    Node* newHead = head->next;
    Node* newCurrent = newHead;
    while (current != nullptr) {
        current->next = newCurrent->next;
        current = current->next;
        if (newCurrent->next != nullptr) {
            newCurrent->next = newCurrent->next->next;
            newCurrent = newCurrent->next;
        }
    }
    return newHead;
}