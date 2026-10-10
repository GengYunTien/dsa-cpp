// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution 1: Recursive
// - if root is null, create and return new node
// - if val < root, recurse left; if val > root, recurse right
// - BST guarantees no duplicates
// Time Complexity: O(h) - O(log n) balanced, O(n) skewed
// Space Complexity: O(h) - recursion call stack
TreeNode* insertIntoBST(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (root->val > val) {
        root->left = insertIntoBST(root->left, val);
    }
    if (root->val < val) {
        root->right = insertIntoBST(root->right, val);
    }
    return root;
}

// Solution 2: Iterative
// - traverse tree to find the correct insertion point
// - insert new node when reaching a null child
// - no stack needed since we only move forward without backtracking
// Time Complexity: O(h) - O(log n) balanced, O(n) skewed
// Space Complexity: O(1)
TreeNode* insertIntoBSTusingIterative(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    TreeNode* current = root;
    while(true) {
        if (current->val > val) {
            if (current->left == nullptr) {
                current->left = new TreeNode(val);
                break;
            }
            current = current->left;
        }
        else {
            if (current->right == nullptr) {
                current->right = new TreeNode(val);
                break;
            }
            current = current->right;
        }
    }
    return root;
}