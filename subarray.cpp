#include<bits/stdc++.h>
using namespace std;

//time=O(N*N*N),space=O(1)
int  longestSubarrayWithSumK1(vector<int> &arr, long long k){
    int len = 0;
    for(int i=0; i<arr.size(); i++){
        for(int j=i; j<arr.size(); j++){
            long long sum = 0;
            for(int l=i; l<=j; l++){
                sum += arr[l];
            }
            if(sum == k){
                len = max(len,j-i+1);
            }
        }
    }
    return len;
}

//for zero and positive
//time = O(2*N),space=O(1)
int longestSubarrayWithSumK2(vector<int> &arr, long long k){
    int left = 0, right = 0;
    int n = arr.size();
    long long sum = arr[0];
    int maxlen = 0;
    
    while(right < n){
        while(left <= right && sum >k){
            sum -= arr[left];
            left++;
        }
        if(sum == k){
            maxlen = max(maxlen, right - left +1);
        }
        right++;
        if(right < n) sum += arr[right];
    }
    return maxlen;
}

int main(){
    vector<int> arr = {575, 330, 339, 584, 239, 31, 173, 929, 967};
    int k = 204;
    int ans = longestSubarrayWithSumK2(arr, k);
    cout<< ans<< endl;
    return 0;
}