#include <vector>
#include <stack>
#include <algorithm>  // for reverse()
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

// Solution 1: Recursive - left -> right -> root
// Time Complexity: O(n)
// Space Complexity: O(n) - recursion call stack
class Solution {
    public:
        vector<int> postorderTraversal(TreeNode* root) {
            vector<int> ans;
            traverse(root, ans);
            return ans;
        }

    private:
        void traverse(TreeNode* root, vector<int>& ans) {
            if (root != nullptr) {
                traverse(root->left, ans);
                traverse(root->right, ans);
                ans.push_back(root->val);
            }
        }
};

// Solution 2: Iterative with stack
// - collect nodes in reverse postorder (root -> right -> left)
// - push left first, then right (LIFO ensures right is processed first)
// - reverse the result to get left -> right -> root
// Time Complexity: O(n)
// Space Complexity: O(n) - stack
vector<int> postorderTraversalwithStack(TreeNode* root) {
    vector<int> ans;
    if (root == nullptr) {
        return ans;
    }
    
    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty()) {
        TreeNode* node = stk.top();
        stk.pop();
        ans.push_back(node->val);

        if (node->left != nullptr) {
            stk.push(node->left);
        }
        if (node->right != nullptr) {
            stk.push(node->right);
        }
    }
    reverse(ans.begin(), ans.end());
    return ans;
}