#include<bits/stdc++.h>
using namespace std;


//time=o(n*n),space=O(1)
int countPair(vector<int> &arr){
    int n = arr.size();
    int count = 0;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]> 2*arr[j]){
                count++;
            }
        }
    }
    return count;
}

int pair1(vector<int> &skill, int n){
    return countPair(skill);
}


//Important
//time=O(2n*logn),space=O(n)
void merge(vector<int> &arr, int low, int mid, int high){
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while(low<=mid && right<=high){
        if(arr[left] <= arr[right]){
            temp.push_back(arr[left]);
            left++;
        }
        else{
            temp.push_back(arr[right]);
            right++;
        }
    }

    while(left <= mid){
        temp.push_back(arr[left]);
        left++;
    }

    while(right <= high){
        temp.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++){
        arr[i] = temp[i-low];
    }
}

int countPair2(vector<int> &arr, int low, int mid, int high){
    int right = mid + 1;
    int count = 0;
    for(int i = low; i<=mid; i++){
        while(right <= high && arr[i]>2*arr[right]){
            right++;
        }
        count += (right-(mid+1));
    }
    return count;
}

int mergeSort(vector<int> &arr, int low, int high){
    int count = 0;
    if(low>=high) return count;
    int mid = (low+high)/2;
    count += mergeSort(arr, low, mid); //left half
    count += mergeSort(arr, mid+1, high);//right half
    count += countPair2(arr, low, mid, high); //modification
    merge(arr, low, mid, high);  //merging sorted halves
    return count;
}
int team(vector<int> &skill, int n){
    return mergeSort(skill, 0, n-1);
}
int main(){
    vector<int> a = {4, 1, 2, 3, 1};
    int n = 5;
    int cnt = team(a, n);
    cout << "The number of reverse pair is: " << cnt << endl;
    return 0;
}



// void merge(vector<int> &arr, int low, int mid, int high, long long &count) {
//         vector<int> temp;
//         int left = low;
//         int right = mid + 1;

//         while (left <= mid && right <= high) {
//             if (static_cast<long long>(arr[left]) > 2 * static_cast<long long>(arr[right])) {
//                 count += (mid - left + 1);
//                 right++;
//             } else {
//                 left++;
//             }
//         }

//         left = low;
//         right = mid + 1;

//         while (left <= mid && right <= high) {
//             if (arr[left] <= arr[right]) {
//                 temp.push_back(arr[left]);
//                 left++;
//             } else {
//                 temp.push_back(arr[right]);
//                 right++;
//             }
//         }

//         while (left <= mid) {
//             temp.push_back(arr[left]);
//             left++;
//         }

//         while (right <= high) {
//             temp.push_back(arr[right]);
//             right++;
//         }

//         for (int i = low; i <= high; i++) {
//             arr[i] = temp[i - low];
//         }
//     }

//     void mergeSort(vector<int> &arr, int low, int high, long long &count) {
//         if (low < high) {
//             int mid = (low + high) / 2;
//             mergeSort(arr, low, mid, count);
//             mergeSort(arr, mid + 1, high, count);
//             merge(arr, low, mid, high, count);
//         }
//     }

//     int reversePairs(vector<int> &skill) {
//         long long n = skill.size();
//         long long count = 0;
//         mergeSort(skill, 0, n - 1, count);
//         return count;
//     }