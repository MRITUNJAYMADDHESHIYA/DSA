//Given the sorted rotated array nums of unique elements, return the minimum element of this array.
//Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

//Unique element
//Binary Search--> always eliminate left/right

#include<bits/stdc++.h>
using namespace std;

int findMin(vector<int>& arr)
{
	// Write your code here.
	int low = 0, high = arr.size() - 1;
	int ans = INT_MAX;
	while(low <= high){
		int mid = low + (high - low)/2;
		//If left half is sorted
		if(arr[low] <= arr[mid]){
			ans = min(ans, arr[low]);
			low = mid +1;
		}
		//If right half is sorted
		else{
			ans = min(ans, arr[mid]);
			high = mid - 1;
		}
	}
	return ans;
}




