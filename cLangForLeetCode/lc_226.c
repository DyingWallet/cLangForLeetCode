/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include"leetCode.h"
#include"leetCodeStructs.h"

typedef struct TreeNode treeNode;

treeNode* inv(treeNode* node);
treeNode* invertTree(treeNode* root) {
	if (root)
		return inv(root);
	return root;
}

treeNode* inv(treeNode* node) {
	treeNode* temp = node->left;
	node->left = node->right;
	node->right = temp;
	if (node->left) node->left = inv(node->left);
	if (node->right) node->right = inv(node->right);
	return node;
}