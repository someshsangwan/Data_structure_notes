#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// peak element is that element in array whose value is strictly greater than its neighbours;
// Input: nums = [1,2,3,1]
// Output: 2
// Explanation: 3 is a peak element and your function should return the index number 2.

// Input: nums = [1,2,1,3,5,6,4]
// Output: 5
// Explanation: Your function can return either index number 1 where the peak element is 2, or index number 5 where the peak element is 6.

//try it in log(n);

// corner case
// array is asccending order- output will be last index;
// array is deccending order - output will be first index;
// all element is peak -- same value of every element --- output will be any index;

int findPeakElement(vector<int>& nums) {
        int low = 0,high = nums.size()-1;
        while(low < high){
            int mid = (low + high)/2;
            if(nums[mid] > nums[mid+1]) high = mid;
            else low = mid+1;
        }
        return low;
    }