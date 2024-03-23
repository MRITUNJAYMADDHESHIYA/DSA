#include<bits/stdc++.h>
using namespace std;

//time=O(n*m),space=o(1)
int MaximumRowsWith1(vector<vector<int>> &mat){
    int n = mat.size();
    int m = mat[0].size();

    int count_max = 0;
    int index = -1;
    for(int i=0; i<n; i++){
        int count_one = 0;
        for(int j=0; j<m; j++){
            count_one += mat[i][j];
        }
        if(count_one > count_max){
            count_max = count_one;
            index = i;
        }
    }
    return index;
}

int lowerBound(vector<int> arr, int n, int x) {
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high) {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x) {
            ans = mid;
            //look for smaller index on the left
            high = mid - 1;
        }
        else {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}

//time = O(n*logm),space = O(1)
int MaximumRowsWith2(vector<vector<int>> &matrix){
    int n = matrix.size();
    int m = matrix[0].size();

    int cnt_max = 0;
    int index = -1;

    //traverse the rows:
    for (int i = 0; i < n; i++) {
        // get the number of 1's:
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > cnt_max) {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

int main()
{
    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    cout <<"The row with maximum no. of 1's is: " <<
         MaximumRowsWith1(matrix) << '\n';
}