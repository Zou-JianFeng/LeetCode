/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int getDepth(struct TreeNode* root){
     if (root == NULL) return 0;
     int depthl = getDepth(root->left);
     int depthr = getDepth(root->right);
     return depthl>depthr?depthl+1:depthr+1;
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) return true;
    if (!isBalanced(root->left)) return false;
    if (!isBalanced(root->right)) return false;
    int depthl = getDepth(root->left);
    int depthr = getDepth(root->right);
    int diff = depthl - depthr;
    if (diff < 2 && diff > -2){
        return true;
    }
    else return false;
}