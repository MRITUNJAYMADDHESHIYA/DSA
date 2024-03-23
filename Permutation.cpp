#include<bits/stdc++.h>
using namespace std;


void permuteRecursive1(vector<int> &ds, vector<int> &arr, vector<vector<int>> &ans, int freq[]){
    if(ds.size() == arr.size()){
        ans.push_back(ds);
        return;
    }

    for(int i=0; i<arr.size(); i++){
        if(!freq[i]){
            ds.push_back(arr[i]);
            freq[i]=1;
            permuteRecursive1(ds, arr, ans, freq);
            freq[i]=0;
            ds.pop_back();
        }
    }
}
//time=n!*n,space=O(n)ds+O(n)frq
vector<vector<int>> permute1(vector<int> &arr){
    vector<vector<int>> ans;
    vector<int> ds;
    int freq[arr.size()];
    for(int i=0; i<arr.size(); i++){
        freq[i] = 0;
    }
    permuteRecursive1(ds, arr, ans, freq);
    return ans;
}

//time=O(N!*N),space=O(1)
void permuteRecursive2(int index, vector<int> &arr, vector<vector<int>> &ans){
    if(index == arr.size()){
        ans.push_back(arr);
        return;
    }

    for(int i=index; i<arr.size(); i++){
        swap(arr[index], arr[i]);
        permuteRecursive2(index+1, arr, ans);
        swap(arr[index], arr[i]);
    }
}
vector<vector<int>> permute2(vector<int> &arr){
    vector<vector<int>> ans;
    permuteRecursive2(0, arr, ans);
    return ans;
}


int main(){
    vector<int> arr = {1,2,3};
    vector<vector<int>> ans = permute2(arr);
    for(int i=0; i<ans.size(); i++){
        for(int j=0; j< ans[i].size(); j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}

//////////////////for string
// void permuteRecursive(int index, string &s, vector<string> &ans) {
//     if (index == s.size()) {
//         ans.push_back(s);
//         return;
//     }

//     for (int i = index; i < s.size(); i++) {
//         swap(s[index], s[i]);
//         permuteRecursive(index + 1, s, ans);
//         swap(s[index], s[i]);
//     }
// }

// vector<string> findPermutations(string &s) {
//     vector<string> ans;
//     permuteRecursive(0, s, ans);
//     sort(ans.begin(), ans.end()); // Sort to get the permutations in lexicographical order
//     return ans;
// }