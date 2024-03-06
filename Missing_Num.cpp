#include<bits/stdc++.h>
using namespace std;

//time=O(N*N),space=O(1)
int missing1(vector<int> &arr, int n){
    
    for(int i=1; i<n; i++){
        int flag = 0;
        for(int j=0; j<n; j++){
            if(arr[j] == i){
                flag = 1;
                break;
            }
        }
        if(flag == 0) return i;
    }
    return -1;
}

//time=O(2*N),space=(N)
int missing2(vector<int> &arr, int n){
    int hash[n+1] ={0};
    for(int i=0; i<n-1; i++){ //convert the present value in arr to 1 in hash
        hash[arr[i]] = 1;
    }
    for(int i=0; i<n; i++){
        if(hash[i] == 0){
            return i;
        }
    }
    return -1;
}

//time=O(N),space=(1)
int missing3(vector<int> &arr, int n){
    int sum = (n*(n+1))/2;  //n is very high here
    int value_sum = 0;

    for(int i=0; i<n; i++){
        value_sum = value_sum + arr[i];
    }
    int ret = sum - value_sum;
    return ret;
}

//time=O(N),space=(1)
int missing4(vector<int>&a, int N) {
    int xor1 = 0, xor2 = 0;
    int n = N-1;
    for(int i=0; i<n; i++){
        xor2 = xor2 ^ a[i];
        xor1 = xor1 ^ (i+1);
    }
    xor1 = xor1 ^ N;
    return xor1 ^ xor2;
}

int main(){
    int N = 11;
    vector<int> a = {0, 4, 6, 7, 9, 2, 1, 8, 11, 10, 3 };
    int ans = missing3(a, N);
    cout << "The missing number is: " << ans << endl;
    return 0;
}