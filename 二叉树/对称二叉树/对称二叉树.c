//单独判断两棵树是否对称
//如果要对称：1 两棵树的根结点值相同
//           2 树1的左子树与树2的右子树对称，树1的右子树与树2的左子树对称
bool IsSymmetricTree(struct TreeNode* tree1, struct TreeNode* tree2)
{
    if (tree1 == NULL && tree2 == NULL)
        return true;
    if (tree1 == NULL || tree2 == NULL)
        return false;
    //先判断根结点的值是否相同
    if (tree1->val != tree2->val)
        return false;
    //判断tree1的左子树和tree2的右子树是否对称
    //判断tree1的右子树和tree2的左子树是否对称
    return IsSymmetricTree(tree1->left, tree2->right) &&
        IsSymmetricTree(tree1->right, tree2->left);
}

//写单独判断两棵树是否对称的一个递归函数
bool isSymmetric(struct TreeNode* root)
{
    //空树必然是对称
    if (root == NULL)
        return true;
    //左子树和右子树对称，这棵树就是对称二叉树
    if (IsSymmetricTree(root->left, root->right))
        return true;
    return false;
}