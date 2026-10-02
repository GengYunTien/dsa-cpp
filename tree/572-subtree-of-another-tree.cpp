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

// Solution 1: DFS Recursive (isSubtree) + DFS Recursive (isSameTree)
// Time Complexity: O(n * m) - n is root size, m is subRoot size
// Space Complexity: O(h) - h is the height of root tree
class Solution1 {
    public:
        bool isSubtree (TreeNode* root, TreeNode* subRoot) {
            if (root == nullptr) {
                return false;
            }
            if (isSameTree(root, subRoot)) {
                return true;
            }
            return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
        }
    
    private:
        bool isSameTree (TreeNode* p, TreeNode* q) {
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
};

// Solution 2: DFS Iterative with stack (isSubtree) + DFS Iterative with stack (isSameTree)
// Time Complexity: O(n * m)
// Space Complexity: O(h)
class Solution2 {
    public:
        bool isSubtree (TreeNode* root, TreeNode* subRoot) {
            if (root == nullptr) {
                return false;
            }
            if (subRoot == nullptr) {
                return true;
            }

            stack<TreeNode*> stkRoot;
            stkRoot.push(root); 
            while(!stkRoot.empty()) {
                TreeNode* node = stkRoot.top();
                stkRoot.pop();

                if (node->val == subRoot->val) {
                    if (isSameTree(node, subRoot)) {
                        return true;
                    }
                }

                if (node->right != nullptr) {
                    stkRoot.push(node->right);
                }
                if (node->left != nullptr) {
                    stkRoot.push(node->left);
                }
            }
            return false;
        }
    
    private:
        bool isSameTree(TreeNode* p, TreeNode* q) {
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
};

// Solution 3: BFS Iterative with queue (isSubtree) + BFS Iterative with queue (isSameTree)
// Time Complexity: O(n * m)
// Space Complexity: O(w) - w is the maximum width of the tree
class Solution3 {
    public:
        bool isSubtree (TreeNode* root, TreeNode* subRoot) {
            if (root == nullptr) {
                return false;
            }
            if (subRoot == nullptr) {
                return true;
            }

            queue<TreeNode*> queRoot;
            queRoot.push(root); 
            while(!queRoot.empty()) {
                TreeNode* node = queRoot.front();
                queRoot.pop();

                if (node->val == subRoot->val) {
                    if (isSameTree(node, subRoot)) {
                        return true;
                    }
                }

                if (node->left != nullptr) {
                    queRoot.push(node->left);
                }
                if (node->right != nullptr) {
                    queRoot.push(node->right);
                }
            }
            return false;
        }
    
    private:
        bool isSameTree(TreeNode* p, TreeNode* q) {
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
};

// Note: isSubtree and isSameTree can be mixed freely between recursive and iterative approaches
// All combinations are valid:
// - isSubtree Recursive + isSameTree Stack   (Solution 4)
// - isSubtree Recursive + isSameTree Queue
// - isSubtree Stack     + isSameTree Recursive
// - isSubtree Queue     + isSameTree Recursive
// The choice only affects traversal order, not correctness