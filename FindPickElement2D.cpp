#include<bits/stdc++.h>
using namespace std;

//time=O(n*logm),space=O(1)
int findMaxIndex(vector<vector<int>> &matrix, int n, int m, int col){
    int maxValue = -1;
    int index = -1;
    for(int i=0; i<n; i++){
        if(matrix[i][col] > maxValue){
            maxValue = matrix[i][col];
            index = i;
        }
    }
    return index;
}
vector<int> FindPickGrid(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();
    int low = 0, high = m-1;
    while(low<=high){
        int mid = (low + high)/2;
        int maxRowIndex = findMaxIndex(matrix, n, m, mid);
        int left = mid - 1 >= 0 ? matrix[maxRowIndex][mid - 1] : -1;
        int right = mid + 1 < m ? matrix[maxRowIndex][mid + 1] : -1;
        if(matrix[maxRowIndex][mid] >left && matrix[maxRowIndex][mid] > right){
            return {maxRowIndex, mid};
        }
        else if(matrix[maxRowIndex][mid] < left){
            high = mid - 1;
        }
        else{
            low = mid + 1;
        }
    }
    return {-1, -1};
}

