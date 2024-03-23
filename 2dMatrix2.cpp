#include<bits/stdc++.h>
using namespace std;


bool binarySearch(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n-1;
    while(low<=high){
        int mid = low+ (high - low)/2;
        if(arr[mid] == target) return true;
        else if(arr[mid]< target) low = mid +1;
        else high = mid - 1;
    }
    return false;
}

//binary search
//time=O(N*logM),space=o(1)
bool SearchMatrix1(vector<vector<int>> &matrix, int target){
    int n = matrix.size();

    for(int i=0; i<n; i++){
        bool index = binarySearch(matrix[i], target);  
        if(index) return true;

        //index = binarySearch(matrix[i],target);
        //if(index != -1)return {i, index};
    }
}

//logic mathematics
//important
//time=O(n+m),space=O(1)
bool SearchMatrix2(vector<vector<int>>& matrix, int target) {
    int n = matrix.size();
    int m = matrix[0].size();
    int row = 0, col = m - 1;

    while (row < n && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) row++;
        else col--;
    }
    return false;
}

int main()
{
    vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    SearchMatrix1(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}