#include<bits/stdc++.h>
using namespace std;

//time=O(N),space=O(1)
int FindPickElement1(vector<int> &arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        if((i==0 || arr[i-1]<arr[i]) && (i==n-1 || arr[i]>arr[i+1])){
            return i;
        }
    }
    return -1;
}

//time=O(logn),space=O(1)
//for multiple pick, if we are eleminate the left then right have pick also 
//if we are eleminate the right then left have pick also 
int FindPickElement2(vector<int> &arr){
    int n = arr.size();
    if(n==1) return 0;
    if(arr[0]>arr[1]) return 0;
    if(arr[n-1] > arr[n-2]) return n-1;

    int low = 1;
    int high = n-2;
    while(low<=high){
        int mid = low + (high - low)/2;
        //If mid is the pick
        if(arr[mid-1]<arr[mid] && arr[mid]>arr[mid+1]){
            return mid;
        }
        //if we are in left then increasing line
        if(arr[mid]> arr[mid-1]){
            low = mid+1;
        }
        //if we are in right then decreasing line
        else{
            high = mid - 1;
        }
    }
    return -1;
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    int ans = FindPickElement2(arr);
    cout << "The peak is at index: " << ans << "\n";
    return 0;
}