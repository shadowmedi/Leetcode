
bool IsSameTree(struct TreeNode* root1, struct TreeNode* root2)
{
    if (root1 == NULL && root2 == NULL)
        return true;
    if (root1 == NULL || root2 == NULL)
        return false;
    if (root1->val != root2->val)
        return false;
    return IsSameTree(root1->left, root2->left) && IsSameTree(root1->right, root2->right);
}

//将原树中的所有子树拿出来和subRoot比较
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (root == NULL)
        return false;
    //先和当前树比较，subRoot是否是 以根开始的这棵树的子树
    if (IsSameTree(root, subRoot))
        return true;
    //判断subRoot是否是左树的子树，是否是右树的子树
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}