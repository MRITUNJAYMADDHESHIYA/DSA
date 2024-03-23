//Search Element in Rotated Sorted Array
//Identify the shorted half-> left/right

//Unique element
#include <bits/stdc++.h>
using namespace std;

// int search(vector<int>& arr, int n, int k){
//     int low = 0, high = n-1;
//     while(low <= high){
//         int mid = (low + high)/2;
//         if(arr[mid] == k) return mid;

//         //left sort
//         if(arr[low] <= arr[mid]){
//             if(arr[low] <= k && k <= arr[mid]){
//                 high = mid - 1;
//             }
//             else{
//                 low = mid + 1;
//             }
//         }

//         else{
//             if(arr[mid] <= k && k <= arr[high]){
//                 low = mid + 1;
//             }
//             else{
//                 high = mid - 1;
//             }
//         }
//     }
//     return -1;
// }


//Dublicate (repeat element)
//In ture and false
bool searchInARotatedSortedArrayII(vector<int>&arr, int k) { 
    int n = arr.size();
    int low = 0, high = n-1;
    while(low <= high){
        int mid = (low + high)/2;
        if(arr[mid] == k) return true;
        if(arr[low] == arr[mid] && arr[mid] == arr[high]){
            low++;
            high--;
            continue;
        }

        //left sort
        if(arr[low] <= arr[mid]){
            if(arr[low] <= k && k <= arr[mid]){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        else{
            if(arr[mid] <= k && k <= arr[high]){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
     }
    return false;
}

