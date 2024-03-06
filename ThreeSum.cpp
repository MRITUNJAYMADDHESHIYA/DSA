#include<bits/stdc++.h>
using namespace std;


//time=O(N3 * log(no. of unique triplets)),space=O(2*no of unique triplets)
vector<vector<int>> threeSum1(vector<int>& arr){
    int n = arr.size();

    //need to sort the triplets in ascending order so that we can consider only the unique ones.
    set<vector<int>> st;  //
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                if(arr[i] + arr[j] + arr[k] == 0){
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end()); //we will sort this triplet and insert it in the set data structure.
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//time=O(N2 * log(no. of unique triplets)),space=O(2 * no. of the unique triplets) + O(N) 
vector<vector<int>> threeSum2(vector<int> &arr) {
    int n = arr.size();
    set<vector<int>> st;

    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            //Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


//time=O(NlogN)+O(N*2),space=O(no. of quadruplets), This space is only used to store the answer.
vector<vector<int>> threeSum3(vector<int> &arr){
    int n = arr.size();
    
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        if(i>0 && arr[i] == arr[i-1]) continue;
        int j = i + 1;
        int k = n - 1;

        while(j<k){
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0){
                j++;
            }
            else if(sum > 0){
                k--;
            }
            else{
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j] == arr[j-1]) j++;
                while(j<k && arr[k] == arr[k+1]) k--;
            }
        }
    }
    return ans;
}


int main()
{
    vector<int> arr = { -1, 0, 1, 2, -1, -4};
    vector<vector<int>> ans = threeSum3(arr);
    for (auto it : ans) {
        cout << "[";
        for (auto i : it) {
            cout << i << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}