/* https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).

Find the minimum element.

You may assume no duplicate exists in the array.

Example 1:

Input: [3,4,5,1,2] 
Output: 1
Example 2:

Input: [4,5,6,7,0,1,2]
Output: 0 */

/* Agorithm : Find the pivot
Find the mid element of the array.

If mid element > first element of array this means that we need to look for the inflection point on the right of mid.

If mid element < first element of array this that we need to look for the inflection point on the left of mid. */
class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        
        while(l < r){
            int mid = l + (r - l) / 2;
            if(nums[mid] > nums[r]) l = mid + 1; //this means pivot lies between mid and extreme right, left half of array is sorted. 
            else r = mid; //this means nums[mid]<nums[r],hence mid onwards to extreme right,right half of array is sorted, hence pivot can lie anywhere from mid to extreme left.
        }
        
        return nums[r];
    }
};
