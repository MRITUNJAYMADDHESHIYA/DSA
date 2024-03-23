#include<bits/stdc++.h>
using namespace std;

//time=O(n),space=O(1)
int floorSqrt1(int n){
    int ans=1;
    for(int i=0; i<n; i++){
        if(i*i<=n){
            ans=i;
        }
        else{
            break;
        }
    }
    return ans;
}

//time=O(logn),space=O(1)
//from binary search
int floorSqrt2(int n) {
    int ans = sqrt(n);
    return ans;
}

//time=O(logn),space=O(1)
int floorSqrt3(int n){
    int low = 0;
    int high = n;
    int ans = 1;
    while(low<=high){
        long long mid = (low+high)/2;
        long long value = mid*mid;
        if(value<= n){
            ans = mid;
            low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;
}
int main(){
    int n = 37;
    int ans = floorSqrt3(n);
    cout << "The floor of square root of " << n
         << " is: " << ans << "\n";
    return 0;
}