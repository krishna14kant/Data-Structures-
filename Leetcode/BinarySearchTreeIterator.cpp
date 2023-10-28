// URL : https://leetcode.com/problems/binary-search-tree-iterator/

// Time:  O(1)
// Space: O(h)

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        traverseLeft(root);
    }
    
    bool hasNext() {
        return !empty(stk_);
    }
    
    int next() {
        TreeNode *node = stk_.back(); stk_.pop_back();
        traverseLeft(node->right);
        return node->val;
    }

private:
    void traverseLeft(TreeNode *node) {
        for (; node != nullptr; node = node->left) {
            stk_.emplace_back(node);
        }
    }

    vector<TreeNode *> stk_;
};