bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    int slow=0,fast=0;
    for(slow = 0;slow<numsSize;slow++){
        for(fast = slow+1;fast<=slow+k && fast<numsSize;fast++)
            if(nums[slow] == nums[fast])
                return true;
    }
    return false;
}