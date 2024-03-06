#include<bits/stdc++.h>
using namespace std;


//time=O(N*logN) + O(2*N),space=O(n)
vector<vector<int>> Overlapping(vector<vector<int>> &matrix){
    int n = matrix.size();

    sort(matrix.begin(), matrix.end());
    vector<vector<int>> ans;

    for(int i=0; i<n; i++){
        int start = matrix[i][0];
        int end = matrix[i][1];

        //skip all the merge element
        if(!ans.empty() && end <= ans.back()[1]){
            continue;
        }

        //rest of the interval
        for(int j = i+1; j<n; j++){
            if(matrix[j][0] <= end){
                end = max(end, matrix[j][1]); //max value in the interval //focus here
            }
            else{
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}


//time= O(N*logN) + O(N),space=O(n)
vector<vector<int>> Overlapping2(vector<vector<int>> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    vector<vector<int>> ans;
    for(int i=0; i<n; i++){
        //if ans is empty and ans last element is less than arr first element
        if(ans.empty() || ans.back()[1] < arr[i][0]){
            ans.push_back(arr[i]);
        }
        else{
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}


int main()
{
    vector<vector<int>> arr = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = Overlapping2(arr);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans) {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;
    return 0;
}