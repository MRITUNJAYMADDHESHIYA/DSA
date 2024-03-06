#include<bits/stdc++.h>
using namespace std;

//time=O(N*N*N),space=O(1)
int maxSubarray1(vector<int> &arr, int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int sum = 0;
            for(int k=i; k<=j; k++){
                sum +=arr[k];
            }
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

//time =O(N*N),space = O(1)
int maxSubarray2(vector<int> &arr, int n){
    int maxi = INT_MIN;
    for(int i=0; i<n; i++){
        int sum = 0;
        for(int j=i; j<n; j++){
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

//time=O(N),space=O(1)
// The intuition of the algorithm is not to consider the subarray as a part of the answer if its sum is less than 0. 
// A subarray with a sum less than 0 will always reduce our answer and 
// so this type of subarray cannot be a part of the subarray with maximum sum.
long long maxSubarray3(vector<int> &arr, int n){
    long long maxi = LONG_MIN;
    long long sum = 0;

    for(int i=0; i<n; i++){
        sum += arr[i];

        if(sum > maxi){
            maxi = sum;
        }

        if(sum < 0){
            sum = 0;
        }
        // To consider the sum of the empty subarray
        //if (maxi < 0) maxi = 0;
    }
    return maxi;
}

//There might be more than one subarray with the maximum sum. We need to print any of them.
long long maxSubarray4(vector<int> &arr, int n){
    long long maxi = LONG_MIN; // maximum sum
    long long sum = 0;

    int start = 0;
    int ansStart = -1, ansEnd = -1;
    for (int i = 0; i < n; i++) {

        if (sum == 0) start = i; // starting index
        sum += arr[i];

        if (sum > maxi) {
            maxi = sum;

            ansStart = start;
            ansEnd = i;
        }

        // If sum < 0: discard the sum calculated
        if (sum < 0) {
            sum = 0;
        }
    }

    //printing the subarray:
    cout << "The subarray is: [";
    for (int i = ansStart; i <= ansEnd; i++) {
        cout << arr[i] << " ";
    }
    cout << "]n";

    // To consider the sum of the empty subarry
    //if (maxi < 0) maxi = 0;
    return maxi;
}


int main(){
    vector<int> arr ={1, 2, 7, -4, 3, 2, -10, 9, 1};
    int n = 9;
    int ans = maxSubarray3(arr, n);
    cout<< ans <<endl;
    return 0;
}