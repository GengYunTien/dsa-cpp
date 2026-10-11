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
// - find target node by BST property
// - case 1: no left child → replace with right child
// - case 2: no right child → replace with left child
// - case 3: both children exist → replace with inorder successor (leftmost node in right subtree)
// Time Complexity: O(h) - O(log n) balanced, O(n) skewed
// Space Complexity: O(h) - recursion call stack
TreeNode* deleteNode(TreeNode* root, int key) {
    if (root == nullptr) {
        return root;
    }

    if (root->val > key) {
        root->left = deleteNode(root->left, key);
    }
    else if (root->val < key) {
        root->right = deleteNode(root->right, key);
    }
    else {
        if (root->left == nullptr) {
            return root->right;
        }
        if (root->right == nullptr) {
            return root->left;
        }

        TreeNode* current = root->right;
        while (current->left != nullptr) {
            current = current->left;
        }
        root->val = current->val;

        root->right = deleteNode(root->right, root->val);
    }
    return root;
}

// Solution 2: Iterative
// - find target node and its parent
// - if target has two children, find inorder successor and its parent
// - replace target value with successor, then remove successor
// - no stack needed since we only move forward without backtracking
// Time Complexity: O(h)
// Space Complexity: O(1)
TreeNode* deleteNodeusingIterative(TreeNode* root, int key) {
    TreeNode* parent = nullptr;
    TreeNode* current = root;

    while (current != nullptr && current->val != key) {
        parent = current;
        if (current->val > key) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }

    if (current == nullptr) {
        return root;
    }

    if (current->left != nullptr && current->right != nullptr) {
        TreeNode* parentSucc = current;
        TreeNode* succ = current->right;

        while (succ->left != nullptr) {
            parentSucc = succ;
            succ = succ->left;
        }

        current->val = succ->val;

        current = succ;
        parent = parentSucc;
    }

    TreeNode* child = (current->left != nullptr) ? current->left : current->right;
    
    if (parent == nullptr) {
        return child;
    }

    if (parent->left == current) {
        parent->left = child;
    }
    else {
        parent->right = child;
    }

    return root;
}