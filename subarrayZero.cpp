#include<bits/stdc++.h>
using namespace std;


//time=O(N*N),space=O(1)
int solve(vector<int> &arr){
    int n = arr.size();
    int maxLen = 0;
    unordered_map<int, int> sumIndexMap;
    int sum = 0;

    for(int i=0; i<n; i++){
        sum += arr[i];
        if(sum == 0){
            maxLen = i+1;
        }
        else if(sumIndexMap.find(sum) != sumIndexMap.end()){
            maxLen = max(maxLen, i - sumIndexMap[sum]);
        }
        else{
            sumIndexMap[sum] = i;
        }
    }
    return maxLen;
}


//prefics sum
//time=O(N),space=o(n)in the worst case we would insert all array elements prefix sum into our hashmap
int solve2(vector<int> &arr){
    unordered_map<int,int> mpp; 
    int maxi = 0;
    int sum = 0; 

    for(int i = 0;i<arr.size();i++) {
        sum += arr[i]; 
        if(sum == 0) {
            maxi = i + 1; 
        }
        else {
            if(mpp.find(sum) != mpp.end()) {
                maxi = max(maxi, i - mpp[sum]); 
            }
            else {
                mpp[sum] = i;
            }
        }   
    }

    return maxi;
}

int main(){
    vector<int> arr ={9,-3,3,-1,6,-5};
    cout<<solve2(arr);
    return 0;
}