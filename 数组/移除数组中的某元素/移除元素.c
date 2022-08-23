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
    //思路1：覆盖删除 空间复杂度O(1) 时间复杂度O(N^2)
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
    //思路2：保留不是val的值，挪到新数组
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
    //思路3：保留不是val的值，覆盖前面的值
    int fast = 0, slow = 0;
    //慢指针负责记录不是val的值，快指针负责遍历数组
    for (fast = 0; fast < numsSize; fast++)
    {
        if (nums[fast] != val)
        {
            nums[slow++] = nums[fast];
        }
    }
    return slow;
}