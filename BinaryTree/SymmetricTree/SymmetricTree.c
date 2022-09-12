//�����ж��������Ƿ�Գ�
//���Ҫ�Գƣ�1 �������ĸ����ֵ��ͬ
//           2 ��1������������2���������Գƣ���1������������2���������Գ�
bool IsSymmetricTree(struct TreeNode* tree1, struct TreeNode* tree2)
{
    if (tree1 == NULL && tree2 == NULL)
        return true;
    if (tree1 == NULL || tree2 == NULL)
        return false;
    //���жϸ�����ֵ�Ƿ���ͬ
    if (tree1->val != tree2->val)
        return false;
    //�ж�tree1����������tree2���������Ƿ�Գ�
    //�ж�tree1����������tree2���������Ƿ�Գ�
    return IsSymmetricTree(tree1->left, tree2->right) &&
        IsSymmetricTree(tree1->right, tree2->left);
}

//д�����ж��������Ƿ�ԳƵ�һ���ݹ麯��
bool isSymmetric(struct TreeNode* root)
{
    //������Ȼ�ǶԳ�
    if (root == NULL)
        return true;
    //���������������Գƣ���������ǶԳƶ�����
    if (IsSymmetricTree(root->left, root->right))
        return true;
    return false;
}