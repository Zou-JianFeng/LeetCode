int searchInsert(int* nums, int numsSize, int target) {
    int ans = 0, i;
    for (i = 0; i < numsSize; i++) {
        if (nums[i] == target) {
            //ans = i;
            break;
        }
        if (nums[i] > target) {
            //ans = i; 
            break;
        }
    }
    return i;
}