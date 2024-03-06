#include<bits/stdc++.h>
using namespace std;

//1
//time=O(N!*N),space=O(1)
// Step 1: Find all possible permutations of elements present and store them.
// Step 2: Search input from all possible permutations.
// Step 3: Print the next permutation present right after it.


//2
//stl library
vector<int> nextGreaterPer1(vector<int> &A){
    next_permutation(A.begin(), A.end());
    return A;
}


//3
//time=O(3*N),space=O(1)
//Find the break-point.
//If such a break-point does not exist i.e. if the array is sorted in decreasing order
//If a break-point exists:
// Find the smallest number i.e. > arr[i] and in the right half of index i(i.e. from index i+1 to n-1) and swap it with arr[i].
// Reverse the entire right half(i.e. from index i+1 to n-1) of index i. And finally, return the array.
vector<int> nextGreaterPer2(vector<int> &arr){
    int n = arr.size();

    //find break point
    //n-2 because of dip is strarting from n-2
    int ind = -1;
    for(int i= n-2; i>=0; i--){
        if(arr[i] < arr[i+1]){
            ind = i;
            break;
        }
    }

    // if breakpoint does not exist
    if (ind == -1) {
        // Vector is reversed directly, make sure this is safe
        reverse(arr.begin(), arr.end());
    } else {
        // find out next greater and placed at arr[i]
        for (int i = n - 1; i > ind; i--) {
            if (arr[i] > arr[ind]) {
                swap(arr[i], arr[ind]);
                break;
            }
        }

        // reverse the right half
        reverse(arr.begin() + ind + 1, arr.end());
    }
    return arr;
}

 int main(){
    vector<int> arr = {2,1,3};
    vector<int> ans = nextGreaterPer2(arr);
    cout<<"[ ";
    for(auto it: ans){
        cout<<it<<" ";
    }
    cout<<"]";
    return 0;
}