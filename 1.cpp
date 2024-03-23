// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. 
// If target exists, then return its index. Otherwise, return -1.
// You must write an algorithm with O(log n) runtime complexity.
//Overflow case mid = low + (high-low)/2

#include<bits/stdc++.h>
using namespace std;

// int search(vector<int> &array, int target){
//     int n = array.size();
//     int low = 0 ,high = n-1;
//     while(low <= high){
//         int mid = (low + high)/2;
//         if(array[mid] == target){return mid;}
//         else if(target > array[mid]){low = mid+1;}
//         else{
//             high = mid - 1;
//         }
//     }
//     return -1;
// }

int bs(vector<int> &nums, int low, int high, int target){
    if(low > high){return -1;}
    int mid = (low + high)/2;
    if(nums[mid] == target){return mid;}
    else if(target > nums[mid]){return bs(nums, mid+1, high, target);}
    return bs(nums, low, high -1, target);

}
int search(vector<int> &nums, int target){
    return bs(nums, 0, nums.size()-1 ,target);
}