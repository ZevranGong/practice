/**
 * Find minimum in rotated sorted array
 * Assume that there are no duplicate numbers
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size()-1;
        int mid;
        if (start>end) return NULL;
        while(start < end){
            mid = (start + end)/2;
            if (nums[mid] < nums[end]){
                end = mid;
            } else {
                start = mid+1;
            }
        }
        return nums[start];
    }
};

//When duplicates are allowed
class Solution {
public:
    int findMin(vector<int>& nums) {
        return findMinHelp(nums, 0, nums.size()-1);
    }
    
    int findMinHelp(vector<int>& nums, int lo, int hi){
        int mid;
        if (lo>hi) return NULL;
        while(lo < hi){
            mid = (lo+hi)/2;
            if (nums[mid]>nums[hi]){
                lo = mid +1;
            }
            else if (nums[mid] < nums[hi]){
                hi = mid;
            } else {
                return min(findMinHelp(nums, lo, mid), findMinHelp(nums,mid+1,hi));
            }
        }
        return nums[lo];
    }
};