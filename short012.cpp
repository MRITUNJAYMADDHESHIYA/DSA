#include<bits/stdc++.h>
using namespace std;

//this question can be done by shorting merge short //time=o(nlogn),space=O(n)
//time=O(2*n),space=O(1)
void shortArray2(vector<int> &arr, int n){
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == 0) cnt0++;
        else if (arr[i] == 1) cnt1++;
        else cnt2++;
    }
    //Replace the places in the original array:
    for (int i = 0; i < cnt0; i++) arr[i] = 0; // replacing 0's
    for (int i = cnt0; i < cnt0 + cnt1; i++) arr[i] = 1; // replacing 1's
    for (int i = cnt0 + cnt1; i < n; i++) arr[i] = 2; // replacing 2's
}

//Dutch National flag algorithm. 
// This algorithm contains 3 pointers i.e. low, mid, and high, and 3 main rules.  The rules are the following:
// arr[0….low-1] contains 0. [Extreme left part]
// arr[low….mid-1] contains 1.
// arr[high+1….n-1] contains 2. [Extreme right part], n = size of the array
//time=O(N),space=O(1)
void shortArray1(vector<int> &arr, int n){
    int low = 0, mid = 0, high = n-1;
    while(mid<= high){
        if(arr[mid] == 0){
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1){
            mid++;
        }
        else{
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}