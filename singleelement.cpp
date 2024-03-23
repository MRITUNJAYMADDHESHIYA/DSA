#include<bits/stdc++.h>
using namespace std;

//time=O(N)
int singleElement1(vector<int> &arr, int n){
    if(n==1) return arr[0];
    for(int i=0; i<n; i++){
        if(i==0){
            if(arr[i]!=arr[i+1]) return arr[i];
        }
        else if(i == n-1){
            if(arr[i]!=arr[i-1]) return arr[i];
        }
        else{
            if(arr[i]!=arr[i+1] && arr[i]!=arr[i-1]) return arr[i];
        }
    }
}

//time=O(logn),space=O(1)
int singleElement2(vector<int> &arr, int n){
    if(n==1) return arr[0];
    if(arr[0] != arr[1]) return arr[0];
    if(arr[n-1] != arr[n-2]) return arr[n-1];
    int low = 1, high = n-2;

    while(low<=high){
        int mid = (low+high)/2;

        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid]; //if mid is a single element
        
        //for left side elemination, if index is odd or even
        if((mid%2==1 && arr[mid] == arr[mid-1]) || (mid%2==0 && arr[mid] == arr[mid+1])){
            low = mid + 1;
        }
        //for right side elemination, if index is odd or even
        else{
            high = mid - 1;
        }
    }
    return -1;
}
int main(){
    vector<int> arr = {1,1,3,3,4,5,5,6,6,7,7,9,9};
    int n =13;
    int ans = singleElement2(arr, n);
    cout<< ans <<endl;
    return 0;
}

