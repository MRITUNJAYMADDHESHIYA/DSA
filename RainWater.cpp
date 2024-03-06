#include<bits/stdc++.h>
using namespace std;


//time=O(N*N),space=O(1)
int trap1(vector<int> &arr){
    int n = arr.size();
    int waterTrapped = 0;
    for(int i=0; i<n; i++){
        int j = i;
        int leftMax = 0;
        int rightMax = 0;
        while(j>=0){
            leftMax = max(leftMax, arr[j]);
            j--;
        }
        j=i;
        while(j<n){
            rightMax = max(rightMax, arr[j]);
            j++;
        }
        waterTrapped += min(leftMax, rightMax) - arr[i];
    }
    return waterTrapped;
}

//time=3*O(N),space=O(2*N)
int trap2(vector<int> &arr){
    int n = arr.size();
    int prefix[n];
    int suffix[n];
    prefix[0] = arr[0];
    for(int i=1; i<n; i++){
        prefix[i] = max(prefix[i-1], arr[i]);
    }
    suffix[n-1]  = arr[n-1];
    for(int i = n-2; i>=0; i--){
        suffix[i] = max(suffix[i+1], arr[i]);
    }

    int waterTrapped = 0;
    for(int i=0; i<n; i++){
        waterTrapped += min(prefix[i], suffix[i]) - arr[i];
    }
    return waterTrapped;
}

//two pointer 
//time=O(N),sapce=O(1)
int trap3(vector<int> &height){
    int n = height.size();
    int left = 0, right = n - 1;
    int res = 0;
    int maxLeft = 0, maxRight = 0;
    while (left <= right) {
        if (height[left] <= height[right]) {
        if (height[left] >= maxLeft) {
            maxLeft = height[left];
        } else {
            res += maxLeft - height[left];
        }
        left++;
        } else {
        if (height[right] >= maxRight) {
            maxRight = height[right];
        } else {
            res += maxRight - height[right];
        }
        right--;
        }
    }
    return res;
}


int main(){
    vector < int > arr;
    arr = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << "The water that can be trapped is " << trap2(arr) << endl;
    return 0;
}