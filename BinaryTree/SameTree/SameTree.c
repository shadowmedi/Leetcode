/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isSameTree(struct TreeNode* p, struct TreeNode* q)
{
    //都是空树
    if (p == NULL && q == NULL)
        return true;
    //其中一棵空树，另一棵树非空
    if (p == NULL || q == NULL)
        return false;
    //两棵树都非空
    //先比较当前结点，若不相同直接判断
    if (p->val != q->val)
        return false;
    //然后看它们的左子树和右子树是否都相同
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}