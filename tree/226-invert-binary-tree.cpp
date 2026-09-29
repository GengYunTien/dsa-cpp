#include <stack>
#include <queue>
#include <utility>
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

// Solution 1: DFS - Recursive (Preorder)
// - swap left and right at each node, then recurse
// Time Complexity: O(n)
// Space Complexity: O(h) - h is the height of the tree
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    swap(root->left, root->right);
    invertTree(root->left);
    invertTree(root->right);
    return root;
}

// Solution 2: DFS - Iterative with stack
// - same logic as recursive DFS but uses explicit stack
// Time Complexity: O(n)
// Space Complexity: O(h) - h is the height of the tree
TreeNode* invertTreewithStack(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    stack<TreeNode*> stk;
    stk.push(root);

    while(!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();

        swap(node->left, node->right);
        
        if (node->right != nullptr) {
            stk.push(node->right);
        }
        if (node->left != nullptr) {
            stk.push(node->left);
        }
    }
    return root;
}

// Solution 3: BFS - Iterative with queue
// - level by level, swap left and right at each node
// Time Complexity: O(n)
// Space Complexity: O(w) - w is the maximum width of the tree
TreeNode* invertTreewithQueue(TreeNode* root) {
    if (root == nullptr) {
        return nullptr;
    }

    queue<TreeNode*> q;
    q.push(root);

    while(!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        swap(node->left, node->right);

        if (node->left != nullptr) {
            q.push(node->left);
        }
        if (node->right != nullptr) {
            q.push(node->right);
        }
    }
    return root;
}