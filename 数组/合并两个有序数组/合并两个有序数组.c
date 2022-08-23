#define _CRT_SECURE_NO_WARNINGS
/*void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    //思路一：开额外数组，用归并的思想使用双指针
    int* tmp = (int*)malloc(sizeof(int)*(m+n));
    int k = 0;
    int p1 = 0, p2 = 0;
    while(p1 < m || p2 < n)
    {
        if(p1 < m &&p2 < n)
        {
            if(nums1[p1] < nums2[p2])
            {
                tmp[k++] = nums1[p1];
                p1++;
            }
            else
            {
                tmp[k++] = nums2[p2];
                p2++;
            }
        }
        else if(p1 < m && p2 == n)
        {
            tmp[k++] = nums1[p1];
            p1++;
        }
        else
        {
            tmp[k++] = nums2[p2];
            p2++;
        }
    }
    for(int i = 0; i < m + n; i++)
    {
        nums1[i] = tmp[i];
    }
}*/

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    //用归并的思路从后往前找较大值
    int p1 = m - 1;
    int p2 = n - 1;
    int dest = m + n - 1;
    while (p1 >= 0 || p2 >= 0)
    {
        if (p1 >= 0 && p2 >= 0)
        {
            if (nums1[p1] > nums2[p2])
            {
                nums1[dest] = nums1[p1];
                dest--;
                p1--;
            }
            else
            {
                nums1[dest] = nums2[p2];
                dest--;
                p2--;
            }
        }
        else if (p1 >= 0 && p2 < 0)
        {
            nums1[dest] = nums1[p1];
            p1--;
            dest--;
        }
        else
        {
            nums1[dest] = nums2[p2];
            p2--;
            dest--;
        }
    }
}