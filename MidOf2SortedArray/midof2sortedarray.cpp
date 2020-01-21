/*===========================================
*    
*    anwser for leetcode
*    
*    Created by Haugy on 11/05/2018
*    Copyright (c) 2018 Haugy. All right reserved.
*    
*===========================================*/


/*Q:
'''
给定两个大小为 m 和 n 的有序数组 nums1 和 nums2 。

请找出这两个有序数组的中位数。要求算法的时间复杂度为 O(log (m+n)) 。

示例 1:

nums1 = [1, 3]
nums2 = [2]

中位数是 2.0

示例 2:

nums1 = [1, 2]
nums2 = [3, 4]

中位数是 (2 + 3)/2 = 2.5
'''
*/

#include <stdio.h>

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int
        nums2Size){
    //nums1 < nums2
    if (nums1Size > nums2Size){
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    }
    if (nums1Size == 0 && nums2Size != 0){
        if (nums2Size % 2 == 1){
            return nums2[nums2Size / 2];
        }
        else{
            return (double)(nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0;
        }
    }
    if (nums1Size == 1){
        if (nums2Size % 2 == 0){
            if (nums1[0] <= nums2[nums2Size / 2 - 1]){
                return nums2[nums2Size / 2 - 1];    
            }
            if (nums1[0] >= nums2[nums2Size / 2 - 1] && nums1[0] <= nums2[nums2Size / 2]){
                return nums1[0];
            }
            if (nums1[0] >= nums2[nums2Size / 2]){
                return nums2[nums2Size / 2];
            }
        }
        else{
            if (nums1[0] <= nums2[nums2Size / 2 - 1]){
                return (double)(nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0;
            }
            if (nums1[0] >= nums2[nums2Size / 2 - 1] && nums1[0] <= nums2[nums2Size / 2 + 1]){
                return (double)(nums1[0] + nums2[nums2Size / 2]) / 2.0;
            }
            if (nums1[0] >= nums2[nums2Size / 2 + 1]){
                return (double)(nums2[nums2Size / 2 + 1] + nums2[nums2Size / 2]) / 2.0;
            }
        }
    }
    if (nums1Size % 2 == 0 && nums2Size % 2 == 0){
        if (nums1[nums1Size / 2 - 1] >= nums2[nums2Size / 2 - 1]
                && nums1[nums1Size / 2] <= nums2[nums2Size / 2]){
            return (double)(nums1[nums1Size / 2 - 1] + nums1[nums1Size / 2]) / 2.0;
        }
        if (nums1[nums1Size / 2 - 1] <= nums2[nums2Size / 2 - 1]
                && nums1[nums1Size / 2] >= nums2[nums2Size / 2]){
            return (double)(nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0;
        }
    }
    int* new_nums1 = new int[nums1Size];
    int* new_nums2 = new int[nums2Size];
    //nums1、nums2中位数位置
    double n1_mid, n2_mid;
    int new_n1Size, new_n2Size;

    //nums1 nums2 Size = 2
    if (nums1Size == 2){
        if (nums2Size % 2 == 1){
            n2_mid = nums2[nums2Size / 2];
            if ((nums1[0] < n2_mid) && nums1[1] > n2_mid){
                return n2_mid;
            }
            else if (nums1[1] < nums2[nums2Size / 2 - 1]){
                return nums2[nums2Size / 2 - 1];
            }
            else if (nums1[1] >= nums2[nums2Size / 2 - 1] && nums1[1] <=
                    n2_mid)
            {
                return nums1[1];
            }
            else if (nums1[0] > nums2[nums2Size / 2 + 1]){
                return nums2[nums2Size / 2 + 1];
            }
            else if (nums1[0] >= n2_mid && nums1[0] <= nums2[nums2Size / 2 + 1])
            {
                return nums1[0];
            }
            //flag
            return 0;
        }
        else{
            n2_mid = (double)(nums2[nums2Size / 2] + nums2[nums2Size / 2 - 1]) / 2.0;
            if (nums2Size == 2){
                if (nums1[0] <= nums2[0] && nums1[1] >=nums2[1]){
                    return n2_mid;
                }
                else if (nums1[0] >= nums2[0] && nums1[1] <= nums2[1]){
                    return (double)(nums1[0] + nums1[1]) / 2.0;
                }
                else if (nums1[0] >= nums2[0] && nums1[1] >= nums2[1])
                {
                    return (double)(nums1[0] + nums2[1]) / 2.0;
                }
                else if (nums1[0] <= nums2[0] && nums1[1] <= nums2[1])
                {
                    return (double)(nums2[0] + nums1[1]) / 2.0;
                }
            }
            if (nums1[1] <= nums2[nums2Size / 2 - 2])
            {
                return (double)(nums2[nums2Size / 2 - 2] 
                        + nums2[nums2Size / 2 - 1]) / 2.0;
            }
            if (nums1[1] >= nums2[nums2Size / 2 - 2] 
                    && nums1[0] <= nums2[nums2Size / 2 - 1] 
                    && nums1[1] <= nums2[nums2Size / 2])
            {
                return (double)(nums2[nums2Size / 2 - 1] + nums1[1]) / 2.0;
            }
            if (nums1[0] >= nums2[nums2Size / 2 - 1]
                    && nums1[1] <= nums2[nums2Size / 2])
            {
                return (double)(nums1[0] + nums1[1]) / 2.0;
            }
            if (nums1[0] <= nums2[nums2Size / 2 - 1]
                    && nums1[1] >= nums2[nums2Size / 2])
            {
                return (double)(nums2[nums2Size / 2 - 1] + nums2[nums2Size / 2]) / 2.0;
            }
            if (nums1[1] >= nums2[nums2Size / 2]
                    && nums1[0] <= nums2[nums2Size / 2 + 1]
                    && nums1[0] >= nums2[nums2Size / 2 - 1])
            {
                return (double)(nums1[0] + nums2[nums2Size / 2]) / 2.0;
            }
            if (nums1[0] >= nums2[nums2Size / 2 + 1])
            {
                return (double)(nums2[nums2Size / 2] + nums2[nums2Size / 2 +1]) / 2.0;
            }
            //flag
            return 0;
        }

    }

    if (nums1Size % 2 == 0){
        n1_mid = (double)(nums1[nums1Size / 2] + nums1[nums1Size / 2 - 1]) / 2;
    }
    else{
        n1_mid = nums1[nums1Size / 2];
    }

    if (nums2Size % 2 == 0){
        n2_mid = (double)(nums2[nums2Size / 2] + nums2[nums2Size / 2 - 1]) / 2;
    }
    else{
        n2_mid = nums2[nums2Size / 2];
    }

    if (n1_mid > n2_mid){
        new_n1Size = nums1Size - (nums1Size / 2);
        new_nums1 = &nums1[0];
        new_n2Size = nums2Size - (nums1Size / 2);
        new_nums2 = &nums2[nums1Size / 2];

        return findMedianSortedArrays(new_nums1, new_n1Size, new_nums2,
                new_n2Size);
    }
    else if (n1_mid < n2_mid){
        new_n1Size = nums1Size - (nums1Size / 2);
        new_nums1 = &nums1[nums1Size / 2];
        new_n2Size = nums2Size - (nums1Size / 2);
        new_nums2 = &nums2[0];

        return findMedianSortedArrays(new_nums1, new_n1Size, new_nums2,
                new_n2Size);

    }
    else if (n1_mid == n2_mid){
        return n1_mid;
    }
    return 0;
}

//test
int main(int argc, char** argv){

    int a[4] = {1,5,6,7};
    int b[6] = {2,3,4,8,9,10};
    double result = findMedianSortedArrays(a, 4, b, 6);
    printf("mid is:%f\n", result);

    return 0;
}
