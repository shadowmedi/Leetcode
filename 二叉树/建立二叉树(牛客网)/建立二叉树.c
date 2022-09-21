#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef char BTDataType;
typedef struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode* right;
    BTDataType x;
}BTNode;

//递归方式构建二叉树
BTNode* CreateBinaryTree(char* str, int* index)
{
    //注意遇到#返回空，下标也要往后走
    if (str[*index] == '#')
    {
        (*index)++;
        return NULL;
    }
    //先构建树的根
    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
    root->x = str[(*index)++];
    //再构建左子树和右子树
    root->left = CreateBinaryTree(str, index);
    root->right = CreateBinaryTree(str, index);
    //返回树的根结点
    return root;
}

void InOrder(BTNode* root)
{
    if (root == NULL)
        return;
    InOrder(root->left);
    printf("%c ", root->x);
    InOrder(root->right);
}

int main()
{
    char str[101] = { 0 };
    scanf("%s", str);
    int index = 0;
    BTNode* root = CreateBinaryTree(str, &index);
    InOrder(root);
    return 0;
}