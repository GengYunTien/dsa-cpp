#include <unordered_map>
using namespace std;

// Solution: Recursive
// - preorder first element is always the root
// - use hashmap to find root index in inorder in O(1)
// - leftSize determines the boundary of left and right subtrees
// - recursively build left and right subtrees
// Time Complexity: O(n) - each node is visited once
// Space Complexity: O(n) - hashmap + recursion call stack
class Solution {
    public:
        TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
            unordered_map<int, int> m;
            for (int i = 0; i < inorder.size(); i++) {
                m[inorder[i]] = i;
            }
            return builder(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, m);
        }
    
    private:
        TreeNode* builder(vector<int>& preorder, int preStart, int preEnd,
                            vector<int>& inorder, int inStart, int inEnd,
                            unordered_map<int, int>& m) {
            if (preStart > preEnd) {
                return nullptr;
            }

            int rootVal = preorder[preStart];
            TreeNode* root = new TreeNode(rootVal);

            int rootIndex = m[rootVal];
            int leftSize = rootIndex - inStart;

            root->left = builder(
                preorder, preStart + 1, preStart + leftSize,
                inorder, inStart, rootIndex - 1, 
                m
            );
            root->right = builder(
                preorder, preStart + leftSize + 1, preEnd,
                inorder, rootIndex + 1, inEnd,
                m
            );
            return root;
        }
};

