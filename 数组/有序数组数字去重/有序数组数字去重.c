#define _CRT_SECURE_NO_WARNINGS
/*void SLErase(int* nums, int numsSize, int pos)
{
    int begin = pos;
    while(begin < numsSize-1)
    {
        nums[begin] = nums[begin + 1];
        begin++;
    }
}

int removeDuplicates(int* nums, int numsSize)//O(N^2)
{
    //1 ¸²¸ÇÉ¾³ý
    int length = numsSize;
    for(int i = 0; i < length - 1; )
    {
        if(nums[i] == nums[i+1])
        {
            SLErase(nums, length, i);
            length--;
        }
        else
            i++;
    }
    return length;

}*/
int removeDuplicates(int* nums, int numsSize)
{
    //2 Ë«Ö¸Õë£¬¿ìÖ¸ÕëÓÃÀ´±éÀú£¬ÂýÖ¸ÕëÅÐ¶ÏÊÇ·ñÖØ¸´
    int fast = 1, slow = 0;
    while (fast < numsSize)
    {
        if (nums[slow] == nums[fast])
        {
            fast++;
        }
        else
        {
            slow++;
            nums[slow] = nums[fast];
            fast++;
        }
    }
    return slow + 1;
}