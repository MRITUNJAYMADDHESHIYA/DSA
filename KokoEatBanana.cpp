#include<bits/stdc++.h>
using namespace std;


int findMax(vector<int> &arr) {
    int maxi = INT_MIN;
    int n = arr.size();
    //find the maximum:
    for (int i = 0; i < n; i++) {
        maxi = max(maxi, arr[i]);
    }
    return maxi;
}

int TotalHour(vector<int> &arr, int hourly) {
    int totalH = 0;
    int n = arr.size();
    //find total hours:
    for (int i = 0; i < n; i++) {
        totalH += ceil((double)(arr[i]) / (double)(hourly));
    }
    return totalH;
}

//O(max(a[]) * N),space=O(1)
int MinimamRate(vector<int> &arr, int h){
    int maxi = findMax(arr);

    for(int i=1; i<=maxi; i++){
        int reqTime = TotalHour(arr, i);
        if(reqTime<=h){
            return i;
        }
    }
    return maxi;
}

//time=O(N * log(max(a[]))),space=O(1)
int MinimamRate2(vector<int> &arr, int h){
    int low = 1, high = findMax(arr);

    while(low<=high){
        int mid = (low+high)/2;
        int reqTime = TotalHour(arr, mid);
        if(reqTime<=h){
            high = mid - 1;
        }
        else{
            low = mid+1;
        }
    }
    return low;
}
int main(){
    vector<int> arr = {7, 15, 6, 3};
    int h = 8;
    int ans = MinimamRate2(arr, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}