#include<bits/stdc++.h>
using namespace std;


//time=O(N*N),space=O(1)
vector<int> findMissingRepetingNumber1(vector<int> &arr){
    int n = arr.size();
    int repeating = -1;
    int missing = -1;
    for(int i=1; i<=n; i++){
        int count=0;
        for(int j=0; j<n; j++){
            if(arr[j]==i){count++;}
        }
        if(count == 2){repeating = i;}
        else if(count == 0){missing = i;}

        if(repeating != -1 && missing != -1){
            break;
        }
    }
    return {repeating, missing};
}

//Hashing
//time = O(2*N),space =O(N)
vector<int> findMissingRepetingNumber2(vector<int> &arr){
    int n = arr.size();
    int hash[n+1] = {0};

    //hashing update
    for(int i=0; i<n; i++){
        hash[arr[i]]++;
    }

    int repeating = -1, missing = -1;
    for(int i=1; i<=n; i++){
        if(hash[i] == 2){
            repeating = i;
        }
        else if(hash[i] == 0){
            missing = i;
        }
        if(repeating != -1 && missing != -1){
            break;
        }
    }
    return {repeating, missing};
}

//using math
//time=O(N),space=O(1)
vector<int> findMissingRepetingNumber3(vector<int> &arr){
    int n = arr.size();

    // Find Sn and S2n:
    long long SN = (n * (n + 1)) / 2;
    long long S2N = (n * (n + 1) * (2 * n + 1)) / 6;

    // Calculate S and S2:
    long long S = 0, S2 = 0;
    for (int i = 0; i < n; i++) {
        S += arr[i];
        S2 += (long long)arr[i] * (long long)arr[i];
    }

    //S-Sn = X-Y:
    long long val1 = S - SN;

    // S2-S2n = X^2-Y^2:
    long long val2 = S2 - S2N;

    //Find X+Y = (X^2-Y^2)/(X-Y):
    val2 = val2 / val1;

    //Find X and Y: X = ((X+Y)+(X-Y))/2 and Y = X-(X-Y),
    // Here, X-Y = val1 and X+Y = val2:
    long long x = (val1 + val2) / 2;
    long long y = x - val1;

    return {(int)x, (int)y};
}

//XOR
//time=o(N),space=O(1)
vector<int> findMissingRepetingNumber4(vector<int> &arr){
    int n = arr.size(); // size of the array

    int xr = 0;

    //Step 1: Find XOR of all elements:
    for (int i = 0; i < n; i++) {
        xr = xr ^ arr[i];
        xr = xr ^ (i + 1);
    }

    //Step 2: Find the differentiating bit number:
    int number = (xr & ~(xr - 1));

    //Step 3: Group the numbers:
    int zero = 0;
    int one = 0;
    for (int i = 0; i < n; i++) {
        //part of 1 group:
        if ((arr[i] & number) != 0) {
            one = one ^ arr[i];
        }
        //part of 0 group:
        else {
            zero = zero ^ arr[i];
        }
    }

    for (int i = 1; i <= n; i++) {
        //part of 1 group:
        if ((i & number) != 0) {
            one = one ^ i;
        }
        //part of 0 group:
        else {
            zero = zero ^ i;
        }
    }

    // Last step: Identify the numbers:
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == zero) cnt++;
    }

    if (cnt == 2) return {zero, one};
    return {one, zero};
}


int main(){
    vector<int> arr = {3, 1, 2, 5, 4, 6, 7, 5};
    vector<int> ans = findMissingRepetingNumber3(arr);
    cout<<"{"<<ans[0]<<" "<<ans[1]<<"}";
    return 0;
}