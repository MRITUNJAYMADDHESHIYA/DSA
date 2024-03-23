#include<bits/stdc++.h>
using namespace std;

void generateSubsequences(int ind, vector<int> &ds, int arr[], int n){
    if(ind == n){
        for(auto it: ds){
            cout<<it<<" ";
        }
        if(ds.size()==0){
            cout<<"{}";
        }
        cout<< endl;
        return;
    }
    //Pick the particular index into the sequence
    ds.push_back(arr[ind]);
    generateSubsequences(ind+1, ds, arr, n);
    ds.pop_back();
    
    //not pick, not take condition , the element is not added in the sequence
    generateSubsequences(ind+1, ds, arr,n);
}

int main(){
    int arr[] ={3,1,2};
    int n=3;
    vector<int> ds;
    generateSubsequences(0, ds, arr, n);

    return 0;
}