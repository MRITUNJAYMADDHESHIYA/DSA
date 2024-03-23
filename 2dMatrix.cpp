#include<bits/stdc++.h>
using namespace std;
//One 1D binary(index) --> 2D binary convert(row,column) ===>position 
//row = index/column
//column = index%column

bool binarySearch(vector<int> &arr, int target){
    int n = arr.size();
    int low = 0;
    int high = n;

    while(low<= high){
        int mid = low+ (high - low)/2;
        if(arr[mid] == target) return true;
        else if(target > arr[mid]) low = mid +1;
        else high = mid - 1;
    }
    return false;
}

//time=O(N + logM),space=o(1)
bool SearchMatrix1(vector<vector<int>> &matrix, int target){
    int n = matrix.size(); 
    int m = matrix[0].size();

    for(int i=0; i<n; i++){
        if(matrix[i][0] <= target && target <= matrix[i][m-1]){
            return binarySearch(matrix[i], target);
        }
    }
    return false;
}

//time=O(log(NxM)),space=o(1)
bool SearchMatrix2(vector<vector<int>> &matrix, int target){
    int n = matrix.size();
    int m = matrix[0].size();

    int low = 0, high = n * m -1 ;
    while(low<=high){
        int mid = low +(high - low)/2;
        int row = mid / m;
        int column = mid % m;
        if(matrix[row][column] == target) return true;
        else if(matrix[row][column]< target) low = mid +1;
        else high = mid -1;
    }
    return false;
}


int main()
{
    vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    SearchMatrix2(matrix, 8) == true ? cout << "true\n" : cout << "false\n";
}