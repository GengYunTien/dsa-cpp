#include <iostream>
#include <unordered_map>
using namespace std;

// Solution: Doubly Linked List + Hash Map
// - Hash Map: O(1) lookup by key
// - Doubly Linked List: O(1) insert and remove
// - most recently used → head, least recently used → tail
// Time Complexity: O(1) for both get and put
// Space Complexity: O(n) - n is the capacity
class LRUCache {
    public:
        LRUCache (int capacity) {
            cap = capacity;
            head = new Node(0, 0);
            tail = new Node(0, 0);
            head->next = tail;
            tail->prev = head;
        }

        int get(int key) {
            if (m.find(key) == m.end()) {
                return -1;
            }
            moveToHead(m[key]);
            return m[key]->value;
        }

        void put(int key, int value) {
            if (m.find(key) != m.end()) {
                m[key]->value = value;
                moveToHead(m[key]);
            }
            else {
                Node* node = new Node(key, value);
                m[key] = node;
                addToHead(node);

                if (m.size() > cap) {
                    Node* tailNode = removeTail();
                    m.erase(tailNode->key);
                    delete tailNode;
                }
            }
        }

    private:
        struct Node {
            int key;
            int value;
            Node* prev;
            Node* next;
            Node(int k, int v) : key(k), value(v), prev(nullptr), next(nullptr) {}
        };

        int cap;
        Node* head;
        Node* tail;
        unordered_map<int, Node*> m;

        void removeNode(Node* node) {
            node->next->prev = node->prev;
            node->prev->next = node->next;
        }

        void addToHead(Node* node) {
            head->next->prev = node;
            node->next = head->next;
            head->next = node;
            node->prev = head;
        }

        void moveToHead(Node* node) {
            removeNode(node);
            addToHead(node);
        }

        Node* removeTail() {
            Node* node = tail->prev;
            removeNode(node);
            return node;
        }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */