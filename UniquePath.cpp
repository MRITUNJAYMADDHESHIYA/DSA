#include<bits/stdc++.h>
using namespace std;


//time=The time comp[lexity of this recursive solution is exponential.
//space=As we are using stack space for recursion so the space complexity will also be exponential.
int countPaths(int i, int j, int n, int m){
    if(i == (n-1) && j == (m-1)) return 1;
    if(i >= n || j >= m) return 0;
    else return countPaths(i+1, j, n, m) + countPaths(i, j+1, n, m);
}
int uniquePath(int m, int n){
    return countPaths(0,0,m,n);
}


//time=The time complexity of this solution will be O(n*m) because at max there can be n*m number of states.
//space=As we are using extra space for the dummy matrix the space complexity will also be O(n*m).
int countPaths2(int i, int j, int n, int m, vector<vector<int>> &dp){
    if(i==(n-1) && j==(m-1)) return 1;
    if(i>n || j>m) return 0;
    if(dp[i][j]!=-1) return dp[i][j];
    else return dp[i][j]=countPaths2(i+1,j,n,m,dp)+countPaths2(i,j+1,n,m,dp);
}
int uniquePath2(int m, int n){
    vector<vector<int>> dp(m+1, vector<int>(n+1, -1));

    int num=countPaths2(0,0,m,n,dp);
    if(m==1&&n==1){
        return num;
    }
    return dp[0][0];
}


//time= The time complexity of this solution will be O(n-1) or  O(m-1) depending on the formula we are using.
//space=O(1)
int uniquePath3(int m, int n) {
    int N = n + m - 2;
    int r = m - 1; 
    double res = 1;
    
    for (int i = 1; i <= r; i++)
        res = res * (N - r + i) / i;
    return (int)res;
}

int main(){
    int totalCount = uniquePath3(3,7);
    cout<<totalCount;
    return 0;
}