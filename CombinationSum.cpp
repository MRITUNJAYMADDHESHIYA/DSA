#include<bits/stdc++.h>
using namespace std;

// Time Complexity: O(2^t * k) where t is the target, k is the average length
// Reason: Assume if you were not allowed to pick a single element multiple times, every element will have a couple of options: pick or not pick which is 2^n different recursion calls, also assuming that the average length of every combination generated is k. (to put length k data structure into another data structure)
// Why not (2^n) but (2^t) (where n is the size of an array)?
// Assume that there is 1 and the target you want to reach is 10 so 10 times you can “pick or not pick” an element.
// Space Complexity: O(k*x), k is the average length and x is the no. of combinations
void findCombination(vector<int> &arr, int index, int target, vector<vector<int>> &ans, vector<int> &carry){
    if(index == arr.size()){
        if(target == 0){
            ans.push_back(carry);
        }
        return;
    }
    
    if(arr[index] <= target){
        carry.push_back(arr[index]); //add the value 
        findCombination(arr, index, target- arr[index], ans, carry); //pick up
        carry.pop_back();  //remove the value
    }
    findCombination(arr, index+1, target, ans, carry); //not pick up
}

vector<vector<int>> CombinationSum1(vector<int> &arr, int target){
    vector<vector<int>> ans;
    vector<int> carry; //storing the value
    findCombination(arr, 0, target, ans, carry);
    return ans;
}

int main(){
    vector<int> arr = {2,3,6,7};
    int target = 7;
    vector<vector<int>> ans = CombinationSum1(arr, target);
    for (int i = 0; i < ans.size(); i++) {
    for (int j = 0; j < ans[i].size(); j++)
      cout << ans[i][j] << " ";
    cout << endl;
  }
  return 0;
}
