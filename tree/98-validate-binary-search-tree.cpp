#include <climits>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution 1: DFS Recursive with min/max boundary
// - each node must satisfy minVal < node->val < maxVal
// - use LLONG_MIN/LLONG_MAX to handle int overflow edge cases
// Time Complexity: O(n)
// Space Complexity: O(h) - h is the height of the tree
class Solution1 {
    public:
        bool isValidBST(TreeNode* root) {
            return checker(root, LLONG_MIN, LLONG_MAX);
        }
    
    private:
        bool checker(TreeNode* root, long long minVal, long long maxVal) {
            if (root == nullptr) {
                return true;
            }
            else if (root->val <= minVal || root->val >= maxVal) {
                return false;
            }
            return checker(root->left, minVal, root->val) && checker(root->right, root->val, maxVal);
        }
};

// Solution 2: Inorder Recursive
// - inorder traversal of BST must be strictly increasing
// - use prev to track previous node value
// - && short-circuit naturally stops recursion on failure
// Time Complexity: O(n)
// Space Complexity: O(h) - h is the height of the tree
class Solution2 {
    public:
        bool isValidBST(TreeNode* root) {
            long long prev = LLONG_MIN;
            return inorder(root, prev);
        }
    
    private:
        bool inorder(TreeNode* root, long long& prev) {
            if (root == nullptr) {
                return true;
            }
            if (!inorder(root->left, prev)) {
                return false;
            }
            if (root->val <= prev) {
                return false;
            }

            prev = root->val;
            return inorder(root->right, prev);
        }
};

// Solution 3: Inorder Iterative with stack
// - same logic as Solution 2 but uses explicit stack
// Time Complexity: O(n)
// Space Complexity: O(h)
class Solution3 {
    public:
        bool isValidBST(TreeNode* root) {
            if (root == nullptr) {
                return true;
            }

            stack<TreeNode*> stk;
            TreeNode* current = root;
            long long prev = LLONG_MIN;

            while (current != nullptr || !stk.empty()) {
                while (current != nullptr) {
                    stk.push(current);
                    current = current->left;
                }

                current = stk.top();
                stk.pop();
                if (current->val <= prev) {
                    return false;
                }
                prev = current->val;
                current = current->right;
            }
            return true;
        }
};