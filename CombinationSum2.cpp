#include<bits/stdc++.h>
using namespace std;


// Time Complexity:O(2^n*k)
// Reason: Assume if all the elements in the array are unique then the no. of subsequence you will get will be O(2^n). we also add the ds to our ans when we reach the base case that will take “k”//average space for the ds.
// Space Complexity:O(k*x)
// Reason: if we have x combinations then space will be x*k where k is the average length of the combination.
void findCombination(int ind, int target, vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds){
    if(target == 0){
        ans.push_back(ds);
        return;
    }

    for(int i= ind; i<arr.size(); i++){
        if(i > ind && arr[i] == arr[i-1]) continue;
        if(arr[i] > target) break;
        
        ds.push_back(arr[i]);
        findCombination(i+1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}

vector<vector<int>> CombinationSum2(vector<int> &arr, int target){
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    vector<int> ds;
    findCombination(0, target, arr, ans, ds);
    return ans;
}

int main(){
    vector<int> arr = {10,1,2,7,6,1,5};
    int target = 8;
    vector<vector<int>> ans = CombinationSum2(arr, target);
    cout << "[ ";
    for (int i = 0; i < ans.size(); i++) {
        cout << "[ ";
        for (int j = 0; j < ans[i].size(); j++) {
        cout << ans[i][j] << " ";
        }
        cout << "]";
    }
    cout << " ]";

}