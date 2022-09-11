#define _CRT_SECURE_NO_WARNINGS
//思路：将树的根与左孩子和右孩子比较，只要一个不相同就返回false
//递归 传 左子树的根和右子树的根
bool isUnivalTree(struct TreeNode* root)
{
    //空树不违反单值二叉树
    if (root == NULL)
        return true;
    //前提是有左孩子或右孩子结点或都有
    //根与左孩子结点相同不能立刻推出是单值二叉树，但不相同一定不是单值二叉树
    //与左孩子不相同不需要再和右孩子比较，return直接结束这次函数调用
    if (root->left != NULL && root->val != root->left->val)
        return false;
    //根与右孩子结点相同不能立刻推出是单值二叉树，但不相同一定不是单值二叉树
    if (root->right != NULL && root->val != root->right->val)
        return false;
    //到这里暂时不能推出是单值二叉树，左子树和右子树都要判断是否是单值二叉树（是否出现false）
    return isUnivalTree(root->left) && isUnivalTree(root->right);
}


//遍历二叉树，将二叉树的结点与val比较
/*bool flag = true;//定义全局变量，默认判断是单值二叉树
void PreOrderCompare(struct TreeNode* root, int val)
{

    //用前序的方式遍历二叉树，将二叉树的结点与val比较
    //空树不需要比较
    if(root == NULL)
        return;
    //如果已经判断出它不是单值二叉树，有一个结点不同，就不需要去比较其它剩下的结点
    if(flag == false)
        return;
    //树的根结点与基准值比较
    //树的根结点=基准值不能立刻推出它是单值二叉树，但不相同能立刻推出它不是
    if(root->val != val)
    {
        flag = false;
        return;
    }
    //将左、右子树的结点分别与val比较
    PreOrderCompare(root->left,val);
    PreOrderCompare(root->right,val);
}
bool isUnivalTree(struct TreeNode* root)
{
    if(root == NULL)
        return true;
    //flag是全局变量，如果该函数被调用两次，第一次不是单值二叉树,flag置false，第二次是单值二叉树,
    //但flag不是默认的true了，所以每次调用该函数要把flag置true
    flag = true;
    //遍历这棵树，将树中每一个结点和一个基准值比较,通过flag来判断是否为完全二叉树
    PreOrderCompare(root, root->val);
    return flag;
}*/