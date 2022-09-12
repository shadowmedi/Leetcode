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
    //���ǿ���
    if (p == NULL && q == NULL)
        return true;
    //����һ�ÿ�������һ�����ǿ�
    if (p == NULL || q == NULL)
        return false;
    //���������ǿ�
    //�ȱȽϵ�ǰ��㣬������ֱͬ���ж�
    if (p->val != q->val)
        return false;
    //Ȼ�����ǵ����������������Ƿ���ͬ
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}