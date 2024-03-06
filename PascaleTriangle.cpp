#include<bits/stdc++.h>
using namespace std;

//we are given the row number r and the column number c, and we need to find out the element at position (r,c). 
//time=O(r),space=o(1)
int nCr(int n, int r){
    long long res = 1;
    for(int i=0; i<r; i++){
        res = res*(n-i);
        res = res/(i+1);
    }
    return res;
}

int PascalTriangle(int row, int col){
    int element = nCr(row-1, col-1);
    return element;
}



//Given the row number n. Print the n-th row of Pascal’s triangle.
//Current element = prevElement * (rowNumber - colIndex) / colIndex
//time=o(n),space=O(1)
void PascalTriangle2(int n){
    long long ans = 1;
    cout<<ans<<" "; //first element

    for(int i=1; i<n; i++){
        ans = ans*(n - i); //i is use like column
        ans = ans / i;     
        cout<<ans<<" ";
    }
    cout<<endl;
}



//find Pattern
//time=O(n*n),space=O(1)
vector<int> generateRow(int row){
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}
vector<vector<int>> PascalTriangle3(int n){
    vector<vector<int>> ans;

    //store the pascal triangle
    for(int row=1; row<=n; row++){
        ans.push_back(generateRow(row));
    }
    return ans;
}


int main()
{
    int n = 5;
    vector<vector<int>> ans = PascalTriangle3(n);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout <<endl;
    }
    return 0;
}

// int main(){
//     int row = 5;
//     int col = 3;
//     int n = 5;
//     PascalTriangle2(n);
//     //cout<<element;
//     return 0;
// }