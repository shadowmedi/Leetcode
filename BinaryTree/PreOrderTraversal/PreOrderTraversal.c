//计算二叉树的结点数
int BinaryTreeSize(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//以递归的方式实现前序遍历，若index不是指针，由于形参是实参的临时拷贝

//每个函数中都会有一个index，每个函数中index的改变不会影响其它函数中的index

//因此要传index的指针，保证只有一个下标值的改变
void PreOrder(struct TreeNode* root, int* arr, int* index)
{
    if (root == NULL)
        return;
    arr[*index] = root->val;
    (*index)++;
    PreOrder(root->left, arr, index);
    PreOrder(root->right, arr, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize)
{
    //计算二叉树结点数，确定要开的空间大小
    int size = BinaryTreeSize(root);
    *returnSize = size;
    int* re = (int*)malloc(sizeof(int) * size);
    //数组中已有的数据量/存放数据的下一个下标位置
    int num = 0;
    int* index = &num;
    //递归方式——前序遍历这棵树，将遍历到的结点值放到数组中
    PreOrder(root, re, index);
    return re;
}