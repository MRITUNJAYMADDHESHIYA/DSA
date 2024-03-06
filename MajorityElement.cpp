#include<bits/stdc++.h>
using namespace std;

//time=O(n*n)
int MajorityElement1(vector<int> &arr, int n){
    for(int i=0; i<n; i++){
        int count = 0;
        for(int j=0; j<n; j++){
            if(arr[i] == arr[j]){count++;}
        }
        if(count > n/2){return arr[i];}
    }
}

//Hashing method is one of the best algorithm method
//time=O(N*logN)+O(N),space=O(n)
int MajorityElement2(vector<int> &arr){
    int n = arr.size();
    map<int, int> mpp;
    for(int i=0; i<n; i++){
        mpp[arr[i]]++;  //itereting the value and key in the map
    }
    for(auto it: mpp){
        if(it.second > (n/2)){
            return it.first;
        }
    }
    return -1;
} 

//Moore’s Voting Algorithm:
//time=O(N)+O(N),space=O(1)
int MajorityElement3(vector<int> &arr){
    int n=arr.size();
    int count = 0;
    int element;
    for(int i=0; i<n; i++){
        //checking the new section 
        if(count == 0){
            count = 1;
            element = arr[i];
        }
        //if it's majority 
        else if(arr[i] == element){
            count++;
        }
        else{
            count--;
        }
    }

    //if at the end count == 0 then establish new count1
    int count1 = 0;
    for(int i=0; i<n; i++){
        if(arr[i] == element){count1++;}
    }

    if(count1 > (n/2)){
        return element;
    }

    return -1;
}

int main(){
    vector<int> arr = {2,1,1,2,3,1,1};
    int ans = MajorityElement3(arr);
    cout<< ans <<endl;
    return 0;
}