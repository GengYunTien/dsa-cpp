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

// Solution 1: Recursive - left -> root -> right
// Time Complexity: O(n)
// Space Complexity: O(n) - recursion call stack
class Solution {
    public:
        vector<int> inorderTraversal(TreeNode* root) {
            vector<int> ans;
            traverse(root, ans);
            return ans;
        }

    private:
        void traverse(TreeNode* root, vector<int>& ans) {
            if (root != nullptr) {
                traverse(root->left, ans);
                ans.push_back(root->val);
                traverse(root->right, ans);
            }
        }
};

// Solution 2: Iterative with stack
// - push all left nodes onto stack first
// - pop and process, then move to right subtree
// Time Complexity: O(n)
// Space Complexity: O(n) - stack
vector<int> inorderTraversalwithStack(TreeNode* root) {
    vector<int> ans;
    if (root == nullptr) {
        return ans;
    }

    stack<TreeNode*> stk;
    TreeNode* current = root;

    while (current != nullptr || !stk.empty()) {
        while(current != nullptr) {
            stk.push(current);
            current = current->left;
        }

        current = stk.top();
        stk.pop();
        ans.push_back(current->val);

        current = current->right;
    }
    return ans;
}