/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *columnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int get_depth(struct TreeNode *root) {
    if (root == NULL) return 0;
    int l = get_depth(root->left), r = get_depth(root->right);
    return (l > r ? l : r) + 1;
}

void get_sizes(struct TreeNode *root, int *columnSizes, int level) {
    if (root == NULL) return ;
    columnSizes[level] += 1;
    get_sizes(root->left, columnSizes, level - 1);
    get_sizes(root->right, columnSizes, level - 1);
    return ;
}

void get_result(struct TreeNode *root, int**ret, int *columnSizes, int level) {
    if (root == NULL) return ;
    ret[level][columnSizes[level]++] = root->val;
    get_result(root->left, ret, columnSizes, level - 1);
    get_result(root->right, ret, columnSizes, level - 1);
    return ;
}

int** levelOrderBottom(struct TreeNode* root, int** columnSizes, int* returnSize) {
    *returnSize = get_depth(root);
    *columnSizes = (int *)calloc(*returnSize, sizeof(int));
    int **ret = (int **)malloc(sizeof(int *) * (*returnSize));
    get_sizes(root, *columnSizes, *returnSize - 1);
    for (int i = 0; i < *returnSize; i++) {
        ret[i] = (int *)malloc(columnSizes[0][i] * sizeof(int));
        columnSizes[0][i] = 0;
    }
    get_result(root, ret, *columnSizes, *returnSize - 1);
        
    return ret;
}