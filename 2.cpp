//Lower bound:-The lower bound algorithm finds the first or the smallest index in a sorted array where the value at that index is greater than or equal to a given key i.e. x.
//Time complexity O(logN)
//Important where arr[ind] >= x
#include<bits/stdc++.h>
using namespace std;

int lowerbound(vector<int> arr, int n, int x){
    int low = 0, high = n-1;
    int ans = n;
    while (low <= high){
        int mid = (low + high)/2;
        if(arr[mid] >=x ){
            ans = mid;
            high = mid -1;
        }
        else{
            low = mid + 1;
        }
    }
    return ans;
}


////////Upper bound(The upper bound is the smallest index, ind, where arr[ind] > x.)
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

