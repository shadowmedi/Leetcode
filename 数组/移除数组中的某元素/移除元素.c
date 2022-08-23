#define _CRT_SECURE_NO_WARNINGS
/* void SLErase(int pos, int* nums, int numsSize)
{
    int begin = pos;
    while (begin < numsSize - 1)
    {
        nums[begin] = nums[begin + 1];
        begin++;
    }
}
int removeElement(int* nums, int numsSize, int val)
{
    //˼·1������ɾ�� �ռ临�Ӷ�O(1) ʱ�临�Ӷ�O(N^2)
    int length = numsSize;
    for (int i = 0; i < length; )
    {
        if (nums[i] == val)
        {
            SLErase(i, nums, length);
            length--;
        }
        else
        {
            i++;
        }
    }
    return length;
}*/
/*int removeElement(int* nums, int numsSize, int val)
{
    //˼·2����������val��ֵ��Ų��������
    int* new = (int*)malloc(sizeof(int)*numsSize);
    int num = 0;
    for(int i = 0; i < numsSize; i++)
    {
        if(nums[i] != val)
        {
            new[num++] = nums[i];
        }
    }
    for(int i = 0; i < num; i++)
    {
        nums[i] = new[i];
    }
    return num;
}*/
int removeElement(int* nums, int numsSize, int val)
{
    //˼·3����������val��ֵ������ǰ���ֵ
    int fast = 0, slow = 0;
    //��ָ�븺���¼����val��ֵ����ָ�븺���������
    for (fast = 0; fast < numsSize; fast++)
    {
        if (nums[fast] != val)
        {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}