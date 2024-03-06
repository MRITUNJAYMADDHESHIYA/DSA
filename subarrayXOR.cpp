#include<bits/stdc++.h>
using namespace std;


//time =O(N*N*N),space=O(1)
int subarray1(vector<int> &arr, int target){
    int n = arr.size();
    int count = 0;

    for(int i=0; i<n; i++){
        for(int j=i; j<n; j++){
            int xorr = 0;
            for(int k=i; k<=j; k++){
                xorr = xorr^arr[k];
            }
            if(xorr == target){
                count++;
            }
        }
    }
    return count;
}

//time=O(N*N),space=O(1)
int subarray2(vector<int> &arr, int target){
    int n = arr.size();
    int count = 0;

    for(int i=0; i<n; i++){
        int xorr = 0;
        for(int j=i; j<n; j++){
            xorr = xorr^arr[j];
            if(xorr == target){
                count++;
            }
        }
    }
    return count;
}

//time=O(N) or O(N*logN) depending on which map data structure
//space=o(n)
int subarray3(vector<int> &arr, int target){
    int n = arr.size();
    int xrr = 0;
    map<int, int> mpp;
    mpp[xrr]++; //{0,1}

    int count = 0;
    for(int i=0; i<n; i++){
        xrr = xrr^arr[i];
        //for target
        int x = xrr^target;
        count += mpp[x];
        mpp[xrr]++;
    }
    return count;
}
int main()
{
    vector<int> a = {4, 2, 2, 6, 4};
    int k = 6;
    int ans = subarray3(a, k);
    cout << "The number of subarrays with XOR k is: "<< ans << "\n";
    return 0;
}