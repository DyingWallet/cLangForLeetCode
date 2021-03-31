/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include"leetCode.h"

typedef struct TreeNode treeNode;
bool isSym(treeNode*, treeNode*);

bool isSymmetric(struct TreeNode* root) {
    if (root)
        return isSym(root->left, root->right);
    return true;
}

bool isSym(treeNode* left, treeNode* right) {
    if (left || right) {
        if (left && right) {
            if (left->val != right->val) return false;
            return isSym(left->left, right->right) && isSym(left->right, right->left);
        } else
            return false;
    }
    return true;
}