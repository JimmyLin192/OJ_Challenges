/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool isSame (TreeNode* p, TreeNode* q) {
        if (!p and !q) return true;
        else if (!p or !q) return false;
        return (p->val == q->val) 
           and isSame(p->left, q->left) 
           and isSame(p->right, q->right);
    }
    void reverse (TreeNode* root) {
        if (!root) return;
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        reverse(root->left);
        reverse(root->right);
    }
    bool isSymmetric(TreeNode* root) {
        if (!root) return true;
        reverse(root->right);
        return isSame(root->left, root->right);
    }
};
