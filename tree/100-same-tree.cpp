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
// - both null → true
// - both non-null and same value → recurse on children
// - otherwise → false
// Time Complexity: O(n)
// Space Complexity: O(h) - h is the height of the tree
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) {
        return true;
    }
    else if (p != nullptr && q != nullptr && p->val == q->val) {
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
    else {
        return false;
    }
}

// Solution 2: DFS - Iterative with stack
// - push pairs of corresponding nodes from both trees
// - compare each pair, return false if mismatch
// Time Complexity: O(n)
// Space Complexity: O(h)
bool isSameTreewithStack(TreeNode* p, TreeNode* q) {
    stack<pair<TreeNode*, TreeNode*>> stk;
    stk.push({p, q});

    while (!stk.empty()) {
        auto [p_node, q_node] = stk.top();
        stk.pop();

        if (p_node == nullptr && q_node == nullptr) {
            continue;
        }
        else if (p_node == nullptr || q_node == nullptr || p_node->val != q_node->val) {
            return false;
        }

        stk.push({p_node->right, q_node->right});
        stk.push({p_node->left, q_node->left});
    }
    return true;
}

// Solution 3: BFS - Iterative with queue
// - same logic as stack but processes level by level
// Time Complexity: O(n)
// Space Complexity: O(w) - w is the maximum width of the tree
bool isSameTreewithQueue(TreeNode* p, TreeNode* q) {
    queue<pair<TreeNode*, TreeNode*>> que;
    que.push({p, q});

    while (!que.empty()) {
        auto [p_node, q_node] = que.front();
        que.pop();

        if (p_node == nullptr && q_node == nullptr) {
            continue;
        }
        else if (p_node == nullptr || q_node == nullptr || p_node->val != q_node->val) {
            return false;
        }

        que.push({p_node->right, q_node->right});
        que.push({p_node->left, q_node->left});
    }
    return true;
}