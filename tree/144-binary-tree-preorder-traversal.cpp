#include <vector>
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

// Solution 1: Recursive - root -> left -> right
// Time Complexity: O(n)
// Space Complexity: O(n) - recursion call stack
class Solution {
    public:
        vector<int> preorderTraversal(TreeNode* root) {
            vector<int> ans;
            traverse(root, ans);
            return ans;
        }

    private:
        void traverse(TreeNode* root, vector<int>& ans) {
            if (root != nullptr) {
                ans.push_back(root->val);
                traverse(root->left, ans);
                traverse(root->right, ans);
            }
        }
};

// Solution 2: Iterative with stack
// - push right first, then left (LIFO ensures left is processed first)
// Time Complexity: O(n)
// Space Complexity: O(n) - stack
vector<int> preorderTraversalwithStack(TreeNode* root) {
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

        if (node->right != nullptr) {
            stk.push(node->right);
        }
        if (node->left != nullptr) {
            stk.push(node->left);
        }
    }
    return ans;
}