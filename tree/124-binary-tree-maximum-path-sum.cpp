#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// Solution: DFS Recursive (Post-order)
// - for each node, calculate max gain from left and right subtrees
// - discard negative subtrees with max(0, ...)
// - update global maxSum with left + root + right (path through current node)
// - return root + max(left, right) to parent (can only extend one side)
class Solution {
    public:
        int maxPathSum(TreeNode* root) {
            int maxSum = INT_MIN;
            maxPath(root, maxSum);
            return maxSum;
        }
    
    private:
        int maxPath(TreeNode* root, int& maxSum) {
            if (root == nullptr) {
                return 0;
            }

            int leftSum = max(0, maxPath(root->left, maxSum));
            int rightSum = max(0, maxPath(root->right, maxSum));
            int currentPathSum = leftSum + root->val + rightSum;

            maxSum = max(maxSum, currentPathSum);
            
            return root->val + max(leftSum, rightSum);
        }
};