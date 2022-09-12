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

//�ݹ鷽ʽ����������
BTNode* CreateBinaryTree(char* str, int* index)
{
    //ע������#���ؿգ��±�ҲҪ������
    if (str[*index] == '#')
    {
        (*index)++;
        return NULL;
    }
    //�ȹ������ĸ�
    BTNode* root = (BTNode*)malloc(sizeof(BTNode));
    root->x = str[(*index)++];
    //�ٹ�����������������
    root->left = CreateBinaryTree(str, index);
    root->right = CreateBinaryTree(str, index);
    //�������ĸ����
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