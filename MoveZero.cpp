#include<bits/stdc++.h>
using namespace std;

//time=O(2N), space=O(N)
vector<int> moveZero1(vector<int> &arr, int n){
    vector<int> temp;
    for(int i=0; i<n; i++){
        if(arr[i] != 0){
            temp.push_back(arr[i]);
        }
    }

    //this convert the temp in original arr
    for(int i=0; i<temp.size(); i++){
        arr[i]= temp[i];
    }
    
    int non_zero = temp.size();
    for(int i=non_zero; i<n; i++){
        arr[i] = 0;
    }
}
vector<int> moveZero2(vector<int> &arr, int n){
    int j = -1;
    for(int i=0; i<n; i++){
        if(arr[i]==0){
            j=i;
            break;
        }
    }
    //no non-zero number
    if(j==-1) return arr;

    for(int i=j+1; i<n; i++){
        if(arr[i]!=0){
            swap(arr[j],arr[i]);
            j++;
        }
    }
    return arr;
}
int main(){
    vector<int> arr = {0,1,0,3,21};
    int n = 5;
    vector<int> ans = moveZero2(arr, n);
    for (auto &it : ans) {
        cout << it << " ";
    }
    cout << '\n';
    return 0;
}