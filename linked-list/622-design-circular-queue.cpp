// Solution: circular linked list with tail pointer
// - tail->next always points to head (front of queue)
// - tail always points to the most recently added node (rear)
// - O(1) access to both front and rear without traversal
// Time Complexity: O(1) for all operations
// Space Complexity: O(n) - n is the capacity
class MyCircularQueue {
    public:
        MyCircularQueue(int k) {
            capacity = k;
            size = 0;
            tail = nullptr;
        }

        bool enQueue(int value) {
            if (size == capacity) {
                return false;
            }

            if (size == 0) {
                tail = new ListNode(value);
                tail->next = tail;
            }
            else {
                ListNode* head = tail->next;
                tail->next = new ListNode(value);
                tail = tail->next;
                tail->next = head;
            }
            size++;
            return true;
        }

        bool deQueue() {
            if (size == 0) {
                return false;
            }

            ListNode* head = tail->next;

            if (size == 1) {
                tail = nullptr;
            }
            else {
                tail->next = head->next;
            }
            delete head;
            size--;
            return true;
        }

        int Front() {
            if (size == 0) {
                return -1;
            }
            return tail->next->val;
        }

        int Rear() {
            if (size == 0) {
                return -1;
            }
            return tail->val;
        }

        bool isEmpty() {
            return size == 0;
        }

        bool isFull() {
            return size == capacity;
        }

    private:
        struct ListNode {
            int val;
            ListNode* next;
            ListNode(int x) : val(x), next(nullptr) {}
        };

        ListNode* tail;
        int capacity;
        int size;
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */