//Find out how many times array has been rotated

#include<bits/stdc++.h>
using namespace std;

#include <climits>  //this is for INT_MAX

int findKRotation(vector<int> &arr){
	int low = 0, high = arr.size() - 1;
	int ans = INT_MAX;
    int index = -1;
	while(low <= high){
		int mid = low + (high - low)/2;
		//If left half is sorted
		if(arr[low] <= arr[mid]){
			if(arr[low] < ans){
				index = low;
				ans = arr[low];
			}
			low = mid +1;
		}
		//If right half is sorted
		else{
			if(arr[mid] < ans){
				index = mid;
				ans = arr[mid];
			}
			high = mid - 1;
		}
	}
	return index;   
}


