#include<bits/stdc++.h>
using namespace std;

//time=O(N*N*N*N),space=O(2 * no. of the quadruplets)
vector<vector<int>> fourSum1(vector<int>& arr, int target) {
    int n = arr.size();

    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            for (int k = j + 1; k < n; k++) {
                for (int l = k + 1; l < n; l++) {
                    // taking bigger data type
                    // to avoid integer overflow:
                    long long sum = arr[i] + arr[j];
                    sum += arr[k];
                    sum += arr[l];

                    if (sum == target) {
                        vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}

//time=O(N*N*N*log(M)),space=O(2 * no. of the quadruplets)+O(N)
vector<vector<int>> fourSum2(vector<int>& arr, int target) {
    int n = arr.size();

    set<vector<int>> st;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            set<long long> hashset;
            for (int k = j + 1; k < n; k++) {

                // taking bigger data type
                // to avoid integer overflow:
                long long sum = arr[i] + arr[j];
                sum += arr[k];
                long long fourth = target - sum;
                if (hashset.find(fourth) != hashset.end()) {
                    vector<int> temp = {arr[i], arr[j], arr[k], (int)(fourth)};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                // put the kth element into the hashset:
                hashset.insert(arr[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


//time=O(n*n*n),space=O(no. of quadruplets), This space is only used to store the answer. 
vector<vector<int>> fourSum3(vector<int> &arr){
    int n = arr.size();

    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        if(i>0 && arr[i] == arr[i-1]) continue;

        for(int j=i+1; j<n; j++){
            if(j > i+1 && arr[j] == arr[j-1]) continue;

            int k = j+1;
            int l = n-1;
            while(k < l){
                long long sum = arr[i];
                sum += arr[j];
                sum += arr[k];
                sum += arr[l];
                if(sum == 0){
                    vector<int> temp = {arr[i], arr[j], arr[k], arr[l]};
                    ans.push_back(temp);
                    k++;
                    l--;

                    //skip the duplicate
                    while(k < l && arr[k] == arr[k-1]) k++;
                    while(k < l && arr[l] == arr[l+1]) l--;
                }
                else if(sum < 0){
                    k++;
                }
                else{
                    l--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {1, 0, -1, 0, -2, 2};
    vector<vector<int>> ans = fourSum3(arr);
    cout << "The quadruplets are: \n";
    for (auto it : ans) {
        cout << "[";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "] ";
    }
    cout << "\n";
    return 0;
}