#include<bits/stdc++.h>
using namespace std;


//time=O(2^n)+O(2^n log(2^n)). Each index has two ways. You can either pick it up or not pick it. So for n index time complexity for O(2^n) and for sorting it will take (2^n log(2^n)).
//space=O(2^n) for storing subset sums, since 2^n subsets can be generated for an array of size n.
void subsetSumHelper(vector<int> &arr, int ind, int sum,int n, vector<int> &ans){
    if(ind == n){
        ans.push_back(sum);
        return;
    }

    subsetSumHelper(arr, ind+1, sum + arr[ind], n, ans);//pick the value
    subsetSumHelper(arr, ind+1, sum, n, ans);     //not picking the value

}

vector<int> subsetSum1(vector<int> &arr){
    int n = arr.size();
    vector<int> ans;

    subsetSumHelper(arr, 0, 0, n, ans);

    sort(ans.begin(), ans.end());
    return ans;
}

int main(){
    vector<int> arr = {3,1,2};
    vector<int> ans = subsetSum1(arr);
    for(auto sum: ans){
        cout<<sum<<" ";
    }
    cout<<endl;
    return 0;
}