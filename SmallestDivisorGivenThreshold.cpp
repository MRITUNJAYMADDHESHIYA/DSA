#include<bits\stdc++.h>
using namespace std;

//time=O(max(arr[])*N),space=o(1)
int SmallestDivisorGivenaThreshold1(vector<int> &arr, int threshold){
    int n = arr.size();
    int maxi = *max_element(arr.begin(), arr.end()); //*max_element(arr.begin(), arr.end()) dereferences the iterator, giving the actual value of the maximum element.

    for(int d = 1; d<= maxi; d++){
        int sum = 0;
        for(int i=0; i<n; i++){
            sum += ceil((double)(arr[i]) / (double)(d));
        }
        if(sum <= threshold){
            return d;
        }
    }
    return -1;
}

int sumByD(vector<int> &arr, int div) {
    int n = arr.size(); //size of array
    //Find the summation of division values:
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += ceil((double)(arr[i]) / (double)(div));
    }
    return sum;
}

//time=O(log(max(arr[]))*N),space = O(1)
int SmallestDivisorGivenaThreshold2(vector<int>& arr, int threshold) {
    int n = arr.size();
    if (n > threshold) return -1;
    int low = 1, high = *max_element(arr.begin(), arr.end());

    //Apply binary search:
    while (low <= high) {
        int mid = (low + high) / 2;
        if (sumByD(arr, mid) <= threshold) {
            high = mid - 1;
        }
        else {
            low = mid + 1;
        }
    }
    return low;
}



int main(){
    vector<int> arr = {1,2,3,4,5};
    int threshold = 8;
    int ans = SmallestDivisorGivenaThreshold2(arr, threshold);
    cout<<ans <<endl;
    return 0;
}