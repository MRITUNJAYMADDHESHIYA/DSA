// // Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value.
// // If target is not found in the array, return [-1, -1].
// // You must write an algorithm with O(log n) runtime complexity.
// //Time complexity 2log(N)

#include <bits/stdc++.h>
using namespace std;

// int lowerbound(vector<int> arr, int n, int x){
//     int low = 0, high = n-1;
//     int ans = n;
//     while (low <= high){
//         int mid = (low + high)/2;
//         if(arr[mid] >=x ){
//             ans = mid;
//             high = mid -1;
//         }
//         else{
//             low = mid + 1;
//         }
//     }
//     return ans;
// }

// int upperBound(vector<int> arr, int n, int x) {
// 	int low=0, high=n-1;
// 	int ans = n;
// 	while(low <= high){
// 		int mid = (low + high)/2;
// 		if(arr[mid] > x){
// 			ans = mid;  // May be the ans
// 			high = mid-1;  //Look for more small index
// 		}
// 		else{
// 			low = mid + 1; //took for right
// 		}
// 	}
// 	return ans;
// }

// pair<int, int> firstAndLastPosition(vector<int>& arr, int n, int k)
// {
//     int lb  =lowerbound(arr, n, k);
//     if(lb == n || arr[lb] != k) return {-1, -1};
//     return {lb, upperBound(arr, n, k) - 1};
// }



int firstOcc(vector<int> &arr, int n, int k){
    int first = -1;
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == k){
            first = mid;
            high = mid - 1;
        }
        else if(arr[mid] < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return first;
}

int lastOcc(vector<int> &arr, int n, int k){
    int last = -1;
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == k){
            last = mid;
            low = mid + 1;
        }
        else if(arr[mid] < k){
            low = mid + 1;
        }
        else{
            high = mid - 1;
        }
    }
    return last;
}

pair <int, int> firstandlast(vector<int> &arr, int n, int k){
    int first = firstOcc(arr, n, k);
    if(first == -1){return {-1, -1};}
    int last = lastOcc(arr, n, k);
    return {first, last};
}

int count(vector<int>& arr, int n, int x) {
	// Write Your Code Here
	pair<int, int> ans = firstandlast(arr,n,x);
	if(ans.first == -1){return 0;}
	return ans.second - ans.first + 1 ;   // ans.second means  the second element of the pair<int, int> named ans.
}




