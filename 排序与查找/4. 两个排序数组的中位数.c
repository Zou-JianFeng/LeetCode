double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int numsSize = nums1Size + nums2Size;
    int *nums = (int*)malloc(sizeof(int) * numsSize);
    int min, max;
    for (int i = 0, j = 0, k = 0; k < numsSize;){
        if (i >= nums1Size){
            nums[k++] = nums2[j++];
        }
        else if (j >= nums2Size){
            nums[k++] = nums1[i++];
        }
        else {
            nums[k++] = nums1[i] < nums2[j] ? nums1[i++] : nums2[j++];
        }
    }
    if (numsSize % 2 == 0){
        min = nums[numsSize / 2 - 1];
        max = nums[numsSize / 2];
    }
    else {
        min = max = nums[numsSize / 2];
    }
    free(nums);
    return (double)(min + max) / 2;
}