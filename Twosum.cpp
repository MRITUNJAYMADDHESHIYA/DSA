#include<bits/stdc++.h>
using namespace std;

//time=O(n*n)
string sum(int n, vector<int> &arr, int k){
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == k) return "YES";
        }
    }
    return "NO";
}

//time=O(n*logn),space=O(n)
string sum(int n, vector<int> &arr, int k){
    map<int,int> m;
    for(int i=0; i<n; i++){
        int a = arr[i];
        int remain = k - a;
        if(m.find(remain) != m.end()){
            return "YES"; //return {m[remain], i};
        }
        m[a] = i;
    }
    return "NO";
}

//time=O(n)+O(nlogn),space=O(1)
//Two pointer appoach
//Given a sorted array A (sorted in ascending order), having N integers, find if there exists any pair of elements (A[i], A[j]) such that their sum is equal to X.
int isPairSum(vector<int> &arr, int k){
    sort(arr.begin(), arr.end());
    int n = arr.size();
    int i = 0;
    int j = n-1;
    while(i<j){
        if(arr[i]+arr[j] == k) return 1;
        else if(arr[i] + arr[j] < k) i++;
        else j--;
    }
    return 0;
}