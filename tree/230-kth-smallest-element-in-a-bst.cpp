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

// Solution 1: Inorder Recursive
// - inorder traversal of BST gives nodes in ascending order
// - count each visited node until reaching the kth node
// Time Complexity: O(n)
// Space Complexity: O(h) - h is the height of the tree
class Solution {
    public:
        int kthSmallest(TreeNode* root, int k) {
            int count = 0;
            int ans;
            traversal(root, count, ans, k);
            return ans;
        }

    private:
        void traversal(TreeNode* root, int& count, int& ans, int k) {
            if (root != nullptr) {
                traversal(root->left, count, ans, k);
                
                count++;
                if (count == k) {
                    ans = root->val;
                    return;
                }

                traversal(root->right, count, ans, k);
            }
        }
};

// Solution 2: Inorder Iterative with stack
// - same logic as Solution 1 but uses explicit stack
// - traverse all the way left first, then process node, then go right
// Time Complexity: O(n)
// Space Complexity: O(h) - h is the height of the tree
int kthSmallestwithStack(TreeNode* root, int k) {
    int count = 0;
    stack<TreeNode*> stk;
    TreeNode* current = root;

    while (current != nullptr || !stk.empty()) {
        while (current != nullptr) {
            stk.push(current);
            current = current->left;
        }

        current = stk.top();
        stk.pop();
        
        count++;
        if (count == k) {
            return current->val;
        }
        
        current = current->right;
    }
    return 0;
}