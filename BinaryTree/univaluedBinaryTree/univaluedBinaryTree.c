#define _CRT_SECURE_NO_WARNINGS
//˼·�������ĸ������Ӻ��Һ��ӱȽϣ�ֻҪһ������ͬ�ͷ���false
//�ݹ� �� �������ĸ����������ĸ�
bool isUnivalTree(struct TreeNode* root)
{
    //������Υ����ֵ������
    if (root == NULL)
        return true;
    //ǰ���������ӻ��Һ��ӽ�����
    //�������ӽ����ͬ���������Ƴ��ǵ�ֵ��������������ͬһ�����ǵ�ֵ������
    //�����Ӳ���ͬ����Ҫ�ٺ��Һ��ӱȽϣ�returnֱ�ӽ�����κ�������
    if (root->left != NULL && root->val != root->left->val)
        return false;
    //�����Һ��ӽ����ͬ���������Ƴ��ǵ�ֵ��������������ͬһ�����ǵ�ֵ������
    if (root->right != NULL && root->val != root->right->val)
        return false;
    //��������ʱ�����Ƴ��ǵ�ֵ������������������������Ҫ�ж��Ƿ��ǵ�ֵ���������Ƿ����false��
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}


//���������������������Ľ����val�Ƚ�
/*bool flag = true;//����ȫ�ֱ�����Ĭ���ж��ǵ�ֵ������
void PreOrderCompare(struct TreeNode* root, int val)
{

    //��ǰ��ķ�ʽ���������������������Ľ����val�Ƚ�
    //��������Ҫ�Ƚ�
    if(root == NULL)
        return;
    //����Ѿ��жϳ������ǵ�ֵ����������һ����㲻ͬ���Ͳ���Ҫȥ�Ƚ�����ʣ�µĽ��
    if(flag == false)
        return;
    //���ĸ�������׼ֵ�Ƚ�
    //���ĸ����=��׼ֵ���������Ƴ����ǵ�ֵ��������������ͬ�������Ƴ�������
    if(root->val != val)
    {
        flag = false;
        return;
    }
    //�����������Ľ��ֱ���val�Ƚ�
    PreOrderCompare(root->left,val);
    PreOrderCompare(root->right,val);
}
bool isUnivalTree(struct TreeNode* root)
{
    if(root == NULL)
        return true;
    //flag��ȫ�ֱ���������ú������������Σ���һ�β��ǵ�ֵ������,flag��false���ڶ����ǵ�ֵ������,
    //��flag����Ĭ�ϵ�true�ˣ�����ÿ�ε��øú���Ҫ��flag��true
    flag = true;
    //�����������������ÿһ������һ����׼ֵ�Ƚ�,ͨ��flag���ж��Ƿ�Ϊ��ȫ������
    PreOrderCompare(root, root->val);
    return flag;
}*/