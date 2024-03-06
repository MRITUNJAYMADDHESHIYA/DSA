#include<bits/stdc++.h>
using namespace std;

//time=O(n*n),space=O(1)
int findDublicat1(vector<int> &arr){
    int n = arr.size();
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            if(arr[i]==arr[j]){
                return arr[i];
            }
        }
    }
}


//time=O(n*logn + n), space=O(1)
int findDublicat2(vector<int> &arr){
    int n = arr.size();
    sort(arr.begin(), arr.end());
    for(int i=0; i<n; i++){
        if(arr[i] == arr[i+1]){
            return arr[i];
        }
    }
}


//Hashing
//time=O(N),space=O(N)
int findDublicat3(vector<int> &arr){
    int n = arr.size();
    int fre[n+1] = {0};  //fre array with zero

    for(int i=0; i<n; i++){
        if(fre[arr[i]] == 0){
            fre[arr[i]]++;
        }
        else{
            return arr[i];
        }
    }
}


//Linked List cycle method
//time=O(N),space=O(1)
int findDublicat4(vector<int> &arr){
    int n = arr.size();
    int slow = arr[0];
    int fast = arr[0];

    do{
        slow = arr[slow];  //slow move by one step
        fast = arr[arr[fast]];  //fast move by two step
    }while(slow != fast);

    fast = arr[0];
    while(slow != fast){
        slow = arr[slow]; //one step both
        fast = arr[fast];
    }
    return slow;
}



int main(){
    vector<int> arr = {1,3,4,2,2};
    int ans = findDublicat4(arr);
    cout<< ans;
    return 0;
}