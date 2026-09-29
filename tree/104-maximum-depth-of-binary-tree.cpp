#include <algorithm>
#include <stack>
#include <queue>
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

// Solution 1: DFS - Recursive
// - depth = 1 + max(left subtree depth, right subtree depth)
// Time Complexity: O(n)
// Space Complexity: O(h) - h is the height of the tree
int maxDepth(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// Solution 2: DFS - Iterative with stack
// - store each node with its current depth as a pair
// - update maxDepth whenever a deeper node is found
// Time Complexity: O(n)
// Space Complexity: O(h)
int maxDepthwithStack(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    stack<pair<TreeNode*, int>> stk;
    stk.push({root, 1});
    int maxD = 0;

    while (!stk.empty()) {
        auto [node, depth] = stk.top();
        stk.pop();
        maxD = max(maxD, depth);
        
        if (node->right != nullptr) {
            stk.push({node->right, depth + 1});
        }
        if (node->left != nullptr) {
            stk.push({node->left, depth + 1});
        }
    }
    return maxD;
}

// Solution 3: BFS - count levels
// - process nodes level by level using levelSize
// - each completed level increments depth by 1
// Time Complexity: O(n)
// Space Complexity: O(w) - w is the maximum width of the tree
int maxDepthwithQueue(TreeNode* root) {
    if (root == nullptr) {
        return 0;
    }

    queue<TreeNode*> q;
    q.push(root);
    int depth = 0;

    while (!q.empty()) {
        int levelSize = q.size();
        depth++;

        for (int i = 0; i < levelSize; i++) {
            TreeNode* node = q.front();
            q.pop();
            
            if (node->left != nullptr) {
                q.push(node->left);
            }
            if (node->right != nullptr) {
                q.push(node->right);
            }
        }
    }
    return depth;
}