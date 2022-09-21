//����������Ľ����
int BinaryTreeSize(struct TreeNode* root)
{
    if (root == NULL)
        return 0;
    return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}

//�Եݹ�ķ�ʽʵ��ǰ���������index����ָ�룬�����β���ʵ�ε���ʱ����

//ÿ�������ж�����һ��index��ÿ��������index�ĸı䲻��Ӱ�����������е�index

//���Ҫ��index��ָ�룬��ֻ֤��һ���±�ֵ�ĸı�
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
    //����������������ȷ��Ҫ���Ŀռ��С
    int size = BinaryTreeSize(root);
    *returnSize = size;
    int* re = (int*)malloc(sizeof(int) * size);
    //���������е�������/������ݵ���һ���±�λ��
    int num = 0;
    int* index = &num;
    //�ݹ鷽ʽ����ǰ���������������������Ľ��ֵ�ŵ�������
    PreOrder(root, re, index);
    return re;
}