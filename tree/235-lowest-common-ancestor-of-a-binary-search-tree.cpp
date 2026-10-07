// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution 1: iterative - use BST property to find split point
// - if both p and q are smaller than root, go left
// - if both p and q are larger than root, go right
// - otherwise, root is the lowest common ancestor
// Time Complexity: O(h) - O(log n) for balanced BST, O(n) for skewed tree
// Space Complexity: O(1)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    while (root != nullptr) {
        if (p->val < root->val && q->val < root->val) {
            root = root->left;
        }
        else if (p->val > root->val && q->val > root->val) {
            root = root->right;
        }
        else {
            return root;
        }
    }
    return nullptr;
}

// Solution 2: Recursive - use BST property to find split point
// - if both p and q are smaller than root, recurse left
// - if both p and q are larger than root, recurse right
// - otherwise, root is the lowest common ancestor
// Time Complexity: O(h) - O(log n) for balanced BST, O(n) for skewed tree
// Space Complexity: O(h) - recursion call stack
TreeNode* lowestCommonAncestorWithRecursive(TreeNode* root, TreeNode* p, TreeNode* q) {
    if (root == nullptr) {
        return nullptr;
    }

    if (p->val < root->val && q->val < root->val) {
        return lowestCommonAncestorWithRecursive(root->left, p, q);
    }
    else if (p->val > root->val && q->val > root->val) {
        return lowestCommonAncestorWithRecursive(root->right, p, q);
    }
    else {
        return root;
    }
}