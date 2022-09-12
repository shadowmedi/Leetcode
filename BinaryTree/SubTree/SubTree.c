
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

//��ԭ���е����������ó�����subRoot�Ƚ�
bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
{
    if (root == NULL)
        return false;
    //�Ⱥ͵�ǰ���Ƚϣ�subRoot�Ƿ��� �Ը���ʼ�������������
    if (IsSameTree(root, subRoot))
        return true;
    //�ж�subRoot�Ƿ����������������Ƿ�������������
    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
}